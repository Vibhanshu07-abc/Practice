class Circle{
   public float radius;
    Circle(){
        radius=0;
    }
   public void area(float radius){
        System.out.println("the area is :"+radius*radius*3.14);
    }
}
class Cylinder extends Circle{
     public void area(float radius,float height ){
         System.out.println("the are of cylinder is :"+2*3.14*radius*height);
     }
}

public class inheritanceassi {
    public static void main(String[] args){
        Circle obj=new Circle();
        obj.area(20);
        Cylinder obj2=new Cylinder();
        obj2.area(10,30);
    }
}
