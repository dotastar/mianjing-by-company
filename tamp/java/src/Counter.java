/**
 * Created with IntelliJ IDEA.
 * User: wuyang
 * Date: 14-3-15
 * Time: 下午11:06
 * To change this template use File | Settings | File Templates.
 */



public class Counter {
    private int value;
    //private Lock lock = new Peterson();
    //private Lock lock = new TTASLock();
    private Lock lock = new ALock(2);
    public Counter(int c){
        value = c;
    }
    public int getAndIncrement(){
        int temp;
        lock.lock();
        try{
            temp = value;
            value = temp + 1;
        } finally {
            lock.unlock();
        }
        return temp;
    }
    public int get(){
        return value;
    }

    static Counter c = new Counter(0);

    public static void main(String[] args){
        Thread[] threads = new Thread[2];
        for(int i = 0; i < threads.length; i++){
            //final String message = "Hello world from thread" + i;
            threads[i] = new Thread(new Runnable() {
                @Override
                public void run() {
                    //System.out.println(message);
                    for(int i = 0; i < 5000000; i++){
                        c.getAndIncrement();
                        System.out.println("="+c.get());
                    }
                }
            });
        }

        for(int i = 0; i < threads.length; i++){
            threads[i].start();
        }

        for(int i = 0; i < threads.length; i++){
            try {
                threads[i].join();
            } catch(InterruptedException e){
                e.printStackTrace();
            }
        }
        System.out.println("="+c.get());
    }


}
