import java.util.Scanner;
public class Prac {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("enter the marks of the student ");
        int a=sc.nextInt();
        System.out.println("enter the marks of the student ");
        int b=sc.nextInt();
        System.out.println("enter the marks of the student ");
        int c=sc.nextInt();
        System.out.println("enter the marks of the student ");
        int d=sc.nextInt();
        System.out.println("enter the marks of the student ");
        int e=sc.nextInt();
        int total=a+b+c+d+e;
        float percentage=total*100/500;
        System.out.print("the percentage of student is "+percentage);
        sc.close();
    }
}
