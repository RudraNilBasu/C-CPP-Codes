import java.lang.*;
import java.util.Scanner;
import java.math.BigInteger;

class Main
{
        public static void main(String args[]) throws java.lang.Exception
        {
                Scanner sc = new Scanner(System.in);
                BigInteger total = BigInteger.ZERO, diff = BigInteger.ZERO;
                int i;
                for(i = 1; i <= 10; i++) {
                        if (sc.hasNext()) {
                                total = new BigInteger(sc.next());
                        }
                        if (sc.hasNext()) {
                                diff = new BigInteger(sc.next());
                        }
                        BigInteger x = total.add(diff);
                        x = x.divide(new BigInteger("2"));
                        BigInteger y = total.subtract(x);
                        System.out.println(x + "\n" + y);
                }
        }
}
