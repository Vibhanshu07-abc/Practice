import java.util.Scanner;
public class Exceptionprac {
    public static void main(String []args ){
      System.out.println("enter the number ");
      int a;
      Scanner sc=new Scanner(System.in);
      a=sc.nextInt();
      try{
      int b=100/a;
      System.out.printf("the number is %d \n",b);
      }
      catch(Exception e){
        System.out.println("cant divide ");
         System.out.println(e);
      }
      sc.close();
    }
}
