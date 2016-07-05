package test;
import java.math.BigDecimal;
import java.util.*;
class BigDec{

    public static void main(String args[])
    {
        //Input
        Scanner sc= new Scanner(System.in);
        int n=sc.nextInt();
        String []s=new String[n+2];
        for(int i=0;i<n;i++)
        {
            s[i]=sc.next();
        }

        //Write your code here
        int i,j;
        for(i=0;i<n;i++) {
            for(j=0;j<n-i-1;j++) {
                BigDecimal a=new BigDecimal(s[j]);
                BigDecimal b=new BigDecimal(s[j+1]);
                int res=a.compareTo(b);
                if(res==-1) {
                    String temp = s[j+1];
                    s[j+1]=s[j];
                    s[j]=temp;
                }
            }
        }
        //Output
        for(i=0;i<n;i++)
        {
            System.out.println(s[i]);
        }

    }


}
