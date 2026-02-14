import java.util.Scanner;
class Employee{
    int salary;
    String name ;
     Scanner sc=new Scanner(System.in);
    int getsalary(){
        return salary;
    }
    String getname(){
        return name;
    }
    void setname(){
       System.out.println("enter the name of the employee ");
       name=sc.next();
    }
    void printall(){
        System.out.println(salary);
        System.out.println(name);

    }
}


public class OOP {
    public static void main(String[] args){
    Employee a=new Employee();
    a.name="demo";
    a.salary=10000;
     a.printall();
     a.setname();
     System.out.println("change of the employee ");
     a.printall();
    
    }
}
