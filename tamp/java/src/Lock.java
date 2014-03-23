import java.util.Random;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.atomic.AtomicReference;

/**
 * Created with IntelliJ IDEA.
 * User: wuyang
 * Date: 14-3-16
 * Time: 下午7:50
 * To change this template use File | Settings | File Templates.
 */
public interface Lock {
    public void lock();
    public void unlock();
}
class Peterson implements Lock{
    private static volatile int nextID = 0;
    private static class ThreadLocalID extends ThreadLocal<Integer>{
        protected synchronized Integer initialValue(){
            return nextID++;
        }
    }
    private static ThreadLocalID threadID = new ThreadLocalID();
    public static int get(){
        return threadID.get();
    }
    public static void set(int index){
        threadID.set(index);
    }
    private volatile boolean[] flag = new boolean[2];
    private volatile int victim;

    public void lock(){
        int i = threadID.get();
        int j = 1 - i;
        flag[i] = true;
        victim = i;
        while(flag[j] && victim == i){};

    }
    public void unlock(){
        int i = threadID.get();
        flag[i] = false;
    }
}

class TASLock implements Lock{
    AtomicBoolean state = new AtomicBoolean(false);
    public void lock(){
        while(state.getAndSet(true));
    }
    public void unlock(){
        state.set(false);
    }
}

class TTASLock implements Lock{
    AtomicBoolean state = new AtomicBoolean(false);
    public void lock(){
        while(true){
            while(state.get());
            if(!state.getAndSet(true)){
                return;
            }
        }
    }
    public void unlock(){
        state.set(false);
    }
}


class Backoff{
    final int minDelay, maxDelay;
    int limit;
    final Random random;
    public Backoff(int min, int max){
        minDelay = min;
        maxDelay = max;
        limit = minDelay;
        random = new Random();
    }

    public void backoff() throws InterruptedException{
        int delay = random.nextInt(limit);
        limit = Math.min(maxDelay, 2 * limit);
        Thread.sleep(delay);
    }
}

class BackoffLock implements Lock{
    private AtomicBoolean state = new AtomicBoolean(false);
    private static final int MIN_DELAY = 1;
    private static final int MAX_DELAY = 10;
    public void lock(){
        Backoff backoff = new Backoff(MIN_DELAY, MAX_DELAY);

        while(true){
            while(state.get());
            if(!state.getAndSet(true)){
                return;
            } else {
                try{
                    backoff.backoff();
                } catch(Exception e){
                    e.printStackTrace();
                }
            }
        }
    }
    public void unlock(){
        state.set(false);
    }
}

class ALock implements Lock{
    ThreadLocal<Integer> mySlotIndex = new ThreadLocal<Integer>(){
        protected Integer initialValue() {
            return 0;
        }
    };
    AtomicInteger tail;
    boolean[] flag;
    int size;
    public ALock(int capacity){
        size = capacity;
        tail = new AtomicInteger(0);
        flag = new boolean[capacity];
        flag[0] = true;
    }
    public void lock(){
        int slot = tail.getAndIncrement() % size;
        mySlotIndex.set(slot);
        //System.out.printf(Thread.currentThread().getName() + "] lock slot=%d, flag=%b\n", slot, flag[slot]);
        while(!flag[slot]){
            //System.out.printf(Thread.currentThread().getName() + "] lock in while slot=%d, flag=%b\n", slot, flag[slot]);
        };
    }
    public void unlock(){
        int slot = mySlotIndex.get();
        //System.out.printf(Thread.currentThread().getName() + "] enter unlock slot=%d, flag=%b, next flag=%b \n",slot, flag[slot], flag[(slot + 1) % size]);
        flag[slot] = false;
        flag[(slot + 1) % size] = true;
        //System.out.printf(Thread.currentThread().getName() + "] exit unlock slot=%d, flag=%b, next flag=%b \n",slot, flag[slot], flag[(slot + 1) % size]);
    }
}

class CLHLock implements Lock{
    private final AtomicReference tail;
    private final ThreadLocal myPred;
    private final ThreadLocal myNode;
    public CLHLock(){
        tail = new AtomicReference(new QNode());
        myNode = new ThreadLocal(){
            protected QNode initialValue(){
                return new QNode();
            }
        };
        myPred = new ThreadLocal();
    }
    @Override
    public void lock(){
        QNode node = (QNode)myNode.get();
        node.locked = true;
        QNode pred = (QNode)tail.getAndSet(node);
        myPred.set(pred);
        while(pred.locked){};
    }

    @Override
    public void unlock(){
        QNode node = (QNode)myNode.get();
        node.locked = false;
        myNode.set(myPred.get());
    }
    private class QNode{
        volatile boolean locked;
    }
}

class MSCLock implements Lock{
    private final AtomicReference<QNode> tail;
    private final ThreadLocal<QNode> myNode;
    public MSCLock(){
        tail = new AtomicReference<QNode>(null);
        myNode = new ThreadLocal<QNode>(){
            protected QNode initialValue(){
                return new QNode();
            }
        };
    }
    @Override
    public void lock(){
        QNode node = myNode.get();
        //node.locked = true;
        QNode pred = tail.getAndSet(node);
        if(pred != null){
            node.locked = true;
            pred.next = node;
            while(node.locked){};
        }
    }

    @Override
    public void unlock(){
        QNode node = myNode.get();
        if(node.next == null){
            if(tail.compareAndSet(node, null))
                return;
            while(node.next == null){}
        }
        node.next.locked = false;
        node.next = null;
    }
    private class QNode{
        boolean locked = false;
        QNode next = null;
    }
}