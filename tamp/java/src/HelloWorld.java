/**
 * Created with IntelliJ IDEA.
 * User: wuyang
 * Date: 14-3-15
 * Time: 下午9:19
 * To change this template use File | Settings | File Templates.
 */
public class HelloWorld implements Runnable {
    String message;
    public HelloWorld(String m){
        message = m;
    }
    public void run(){
        System.out.println(message);
    }
    public static void main(String[] args){
        Thread thread = new Thread(new HelloWorld("Hi, world"));
        thread.start();
        try {
            thread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }
}
