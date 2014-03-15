/**
 * Created with IntelliJ IDEA.
 * User: wuyang
 * Date: 14-3-15
 * Time: 下午9:56
 * To change this template use File | Settings | File Templates.
 */
public class ThreadID {
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

    public static void main(String[] args){
        Thread thread = new Thread(new Runnable() {
            @Override
            public void run() {
                System.out.println("Hello world from thread" + threadID.get());
            }
        });
        thread.start();
    }
}
