import java.util.Scanner;
public class Input {
    
    public static void main(String[] args){
        Scanner sc =new Scanner(System.in);
        System.out.println("enter the first number ");
         int a=sc.nextInt();
         System.out.println("enter second number ");
         int b=sc.nextInt();
         int sum=a+b;
         System.out.println("the sum of both the number is ");
         System.out.print(sum);
         sc.close();
    }
    
}
