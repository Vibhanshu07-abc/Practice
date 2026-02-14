
import java.util.Scanner;
public class User {
  public static void  main(String [] args){
   // Scanner sc=new Scanner(System.in);
   //System.out.println("enter the name of the user ");
  // String name=sc.next();
   //System.out.println("Hello " + name +" have a good day");
   // question 4
   Scanner sc=new Scanner(System.in);
   System.out.println("enter the number of the user ");
//int num=sc.nextInt();
System.out.println(sc.hasNextInt());
   sc.close();
  }
    
}
