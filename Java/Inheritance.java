class Parent{
    Parent(){
        System.out.println("parent is called ");
    }
    public void method1(){
        System.out.println("method of parent is called ");
    }
}
class Child extends Parent{
    Child(){
        System.out.println("child is called ");
    }
}
class Grandchild extends Child{
   public  void method1(){
        System.out.println("grandchild is called ");
    }
}
public class Inheritance {
    public static void main(String[] args){ 
       Grandchild obj=new Grandchild();
       obj.method1();
       Child obj2=new Child();
       obj2.method1();
    }
}
