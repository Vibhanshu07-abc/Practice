class Mythreads extends Thread{
    public void run(){
    for(int i=0;i<20;i++){
    System.out.println("coding is fun ");
}
}
}
class Mythreads2 extends Thread{
   public void run(){
    for(int i=0;i<20;i++){
    
    System.out.println("fun is coding ");
    }
}   
}

public class Multithread {
    public static void main(String[]args){
      Mythreads obj=new Mythreads();
      Mythreads2 obj1=new Mythreads2();
      obj.start();
      obj1.start();

    }
}
