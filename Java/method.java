

public class method {
     static void pattern(int a){
            for(int i=0;i<a;i++){
                for(int j=0;j<i;j++){
                    System.out.print(" * ");
                }
                System.out.print("\n");
            }
     }
     static int fiboncci(int n){
           if(n==0){
            return 0;
           }
           if(n==1){
            return 1;
           }
           return fiboncci(n-1)+fiboncci(n-2);
     }
     static  int  pattern2(int a){
        if(a==0){
            return a;
        }
           for(int i=0;i<a;i++){
           System.out.print(" * ");
           }
           System.out.print("\n");
           return pattern2(a-1);
     }
     static int sum(int a){
        if(a==0){
            return a;
        }
          return a+sum(a-1);
     }
    public static void main(String[] args) {
        //pattern(5);
        //int num=sum(5);
        //System.out.printf("the sum is %d\n",num);
        //int c=pattern2(5);
        int fib=fiboncci(5);
        System.out.printf("the number is %d \n",fib);

    }   
}
