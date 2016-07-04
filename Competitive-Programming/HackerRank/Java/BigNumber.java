package test;
import java.math.BigInteger;
import java.io.*;

public class BigNumber {
	public static void main(String args[]) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BigInteger b1,b2,b3,b4;
		b1 = new BigInteger(br.readLine());
		b2 = new BigInteger(br.readLine());
		b3=b1.add(b2);
		b4=b1.multiply(b2);
		System.out.println(b3+"\n"+b4);
	}
}
