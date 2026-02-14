class monkey{
    void jump(){
        System.out.print("jumping...");
    }
    void bite(){
        System.out.print("biting...");
    }
}
interface BasicAnimal{
   void eat();
   void sleep();
}
class human extends monkey implements BasicAnimal{
   public void eat(){
       System.out.print("eating...");
    }
    public void sleep(){
        System.out.print("sleeping...");
    }
}
public class Interface {
    public static void main(String[] args){
        human obj=new human();
        obj.sleep();
    }
}
