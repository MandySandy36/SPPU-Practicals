import java.net.*;
import java.io.*;
public class Server2
{
            public static void main(String args[])throws IOException
            {
                        byte b[]=new byte[3072];
                        DatagramSocket dsoc=new DatagramSocket(1000);
                        FileOutputStream f=new FileOutputStream("testudp1.txt");
                        while(true)
                        {
                                    DatagramPacket dp=new DatagramPacket(b,b.length);
                                    dsoc.receive(dp);
                                    System.out.println(new String(dp.getData(),0,dp.getLength()));  
										PrintWriter pw = new PrintWriter("testudp1.txt");
		pw.println(new String(dp.getData(),0,dp.getLength()));
		pw.close();
		

                        }
            }
}