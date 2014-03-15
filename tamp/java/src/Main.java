/**
 * Created with IntelliJ IDEA.
 * User: wuyang
 * Date: 14-3-15
 * Time: 下午9:22
 * To change this template use File | Settings | File Templates.
 */
public class Main {
    public static void main(String[] args){
        Thread[] threads = new Thread[8];
        for(int i = 0; i < threads.length; i++){
            final String message = "Hello world from thread" + i;
            threads[i] = new Thread(new Runnable() {
                @Override
                public void run() {
                    System.out.println(message);
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
    }
}
