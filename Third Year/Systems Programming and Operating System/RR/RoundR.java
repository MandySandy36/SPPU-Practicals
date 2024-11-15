import java.util.*;
import java.io.*;
class RoundR
{
	public static void main(String args[])
	{
		int Process[]=new int[10];
		int a[]=new int[10];
		int Arrival_time[]=new int[10];
		int Burst_time[]=new int[10];
		int WT[]=new int[10];
		int TAT[]=new int[10];
		int Pno,sum=0;;
		int TimeQuantum;
		
System.out.println("\nEnter the no. of Process::");
		Scanner sc=new Scanner(System.in);
		Pno=sc.nextInt();
		System.out.println("\nEnter each process::");
		for(int i=0;i<Pno;i++)
		{
			Process[i]=sc.nextInt();
		}
		
System.out.println("\nEnter the Burst Time of each process::");
		for(int i=0;i<Pno;i++)
		{
			Burst_time[i]=sc.nextInt();
		}
System.out.println("\nEnter the Time Quantum::");
TimeQuantum=sc.nextInt();		
		do{
	    	for(int i=0;i<Pno;i++)
	    	{
	     		if(Burst_time[i]>TimeQuantum)
	     		{
	    		  	Burst_time[i]-=TimeQuantum; 
	      		  	for(int j=0;j<Pno;j++)
	      			{
	       				if((j!=i)&&(Burst_time[j]!=0))
	        			WT[j]+=TimeQuantum;
	         		}
	          	}
	           	else
	           	{ 
	           		for(int j=0;j<Pno;j++)
	           		{
	            			if((j!=i)&&(Burst_time[j]!=0))
	             			WT[j]+=Burst_time[i];
	              		} 
	              		Burst_time[i]=0; 
	                } 
	       }
	               sum=0; 
	               for(int k=0;k<Pno;k++) 
            		sum=sum+Burst_time[k];
	    } while(sum!=0); 
	                
	             for(int i=0;i<Pno;i++)
	                	 TAT[i]=WT[i]+a[i];
	               System.out.println("process\t\tBT\tWT\tTAT");
	               for(int i=0;i<Pno;i++)
	               {
	                    System.out.println("process"+(i+1)+"\t"+a[i]+"\t"+WT[i]+"\t"+TAT[i]);
	               } 
	                     float avg_wt=0;
	               float avg_tat=0;
	               for(int j=0;j<Pno;j++)
	               { 
	                       avg_wt+=WT[j]; 
	               } 
	               for(int j=0;j<Pno;j++)
	               { 
	                       avg_tat+=TAT[j]; 
	               } 
	                 System.out.println("average waiting time "+(avg_wt/Pno)+"\n Average turn around time"+(avg_tat/Pno)); 		
	}		
}
