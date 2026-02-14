import java.util.Scanner;
public class Array {
public static void main(String[] args){
    Scanner sc= new Scanner(System.in);
    int[]marks=new int[5];
    for(int i=0;i<5;i++){
        System.out.print("enter the marks of the student \n");
         marks[i]=sc.nextInt();
    }
    System.out.print("marks of the students are \n");
    for(int element:marks){
        System.out.printf("the marks are %d \n",element);
    }
    sc.close();
}

}
