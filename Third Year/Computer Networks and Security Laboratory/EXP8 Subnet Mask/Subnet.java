import java.util.Scanner;
class Subnet{
public static void main(String args[])
{
Scanner sc = new Scanner(System.in);
System.out.print("Enter the ip address: ");
String ip = sc.nextLine();
String split_ip[] = ip.split("\\."); //SPlit the string after every .
String split_bip[] = new String[4]; //split binary ip
String bip = "";
String mask1="";

                                int firstoctet = Integer.parseInt(split_ip[0]);
                                if(firstoctet<=127)
                                {
                                                mask1 = "255.0.0.0";
                                                System.out.println("Class A IP Address");
                                                System.out.println("Default mask is: "+mask1);
                                }
                                else if(firstoctet>=128 && firstoctet<=191)
                                {
                                                mask1 = "255.255.0.0";
                                                System.out.println("Class B IP Address");
                                                System.out.println("Default mask is: "+mask1);
                                }
                                else if(firstoctet>=192 && firstoctet<=223)
                                {
                                                mask1 = "255.255.255.0";
                                                System.out.println("Class C IP Address");
                                                System.out.println("Defaultt mask is: "+mask1);
                                }
for(int i=0;i<4;i++)
{
split_bip[i] = appendZeros(Integer.toBinaryString(Integer.parseInt(split_ip[i]))); // "18" => 18 => 10010 => 00010010
bip += split_bip[i];
}
System.out.println("IP in binary is "+bip);
System.out.print("Enter the number of subnets: ");
int n = sc.nextInt();

//Calculation of mask
double bits = (int)Math.ceil(Math.log(n)/Math.log(2)); /*eg if address = 120, log 120/log 2 gives log to the base 2 => 6.9068, ceil gives us upper integer */
int y=(int) bits;
System.out.println("Number of bits borrowd from host to network are = "+y);
int z=8-y;
System.out.println("Number of host bits are = "+z);
//int mask = 32-bits;
double mask=256-(Math.pow(2.0,z));
int x = (int) mask;
System.out.println("New subnet mask is = "+x);
int sub_size=256-x;
System.out.println("Subnet Size = "+sub_size);

//Calculation of first address and last address
int fbip[] = new int[32];
for(int i=0; i<32;i++)
 fbip[i] = (int)bip.charAt(i)-48; //convert cahracter 0,1 to integer 0,1
for(int i=31;i>31-z;i--)//Get first address by ANDing last n bits with 0
fbip[i] &= 0;
String fip[] ={"","","",""};
for(int i=0;i<32;i++)
fip[i/8] = new String(fip[i/8]+fbip[i]);
System.out.println("first Subnet Details");
System.out.print("first N/W address is = ");
for(int i=0;i<4;i++){
System.out.print(Integer.parseInt(fip[i],2));
if(i!=3) System.out.print(".");
}
System.out.println();

int lbip[] = new int[32];
for(int i=0; i<32;i++) 
lbip[i] = (int)bip.charAt(i)-48; //convert cahracter 0,1 to integer 0,1
for(int i=31;i>31-z;i--)//Get last address by ORing last n bits with 1
lbip[i] |= 1;
String lip[] = {"","","",""};
for(int i=0;i<32;i++)
lip[i/8] = new String(lip[i/8]+lbip[i]);
System.out.print("last address is = ");
for(int i=0;i<4;i++){
System.out.print(Integer.parseInt(lip[i],2));
if(i!=3) System.out.print(".");
}
System.out.println();
}
static String appendZeros(String s)
{
String temp = new String("00000000");
return temp.substring(s.length())+ s;
}
}
