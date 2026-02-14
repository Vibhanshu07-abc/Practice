class Mythread1 implements Runnable{
    public void run(){
         for(int i=0;i<20;i++){
     System.out.println("java is learning ");
    }
}
}
class Mythread2 implements Runnable{
    public void run(){
    for(int i=0;i<20;i++){
    
     System.out.println("java is learning very good  ");
    }
}
}
public class Mythread {
       public static void main(String[]args){
        Mythread1 obj = new Mythread1();
        Thread obja=new Thread(obj);
        Mythread2 obj1 = new Mythread2();
        Thread obj1a=new Thread(obj1);
        obj1a.start();
        obja.start();
        
       }
}
