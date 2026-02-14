abstract class pen{
   abstract  public void write();
   abstract public void refill();
}
class FountainPen extends pen{
   public  void write(){
        System.out.println("writing...");
    }
   public void refill(){
        System.out.println("refilling...");
    }
    public void changenib(){
        System.out.println("changing...");
    }

}
public class Abstraction {
    public static void main(String [] args){
        FountainPen obj=new FountainPen();
        obj.write();
        obj.changenib();
    }
}
