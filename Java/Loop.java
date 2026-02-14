
public class Loop {
    public static void main(String[] args){
      //  for(int i=0;i<4;i++){
        //    for(int j=i;j<4;j++){
          //      System.out.print(" * ");
            //}
            //System.out.print("\n");
        //}
        int fact=1;
        for(int i=1;i<=10;i++){
             fact *= i;
        }
        System.out.printf("the factorial is %d ",fact);
    }    
}
