import java.io.*;
import java.util.Scanner;
public class FCFS
{
	public static void main(String args[])
	{
		int i,no_p,burst_time[],TT[],WT[];
		float avg_wait=0,avg_TT=0;
		burst_time=new int[50];
		TT=new int[50];
		WT=new int[50];
		WT[0]=0;
		Scanner s=new Scanner(System.in);
		System.out.println("Enter the number of process: ");
		no_p=s.nextInt();
		System.out.println("\nEnter Burst Time for processes:");
		for(i=0;i<no_p;i++)
		{
			System.out.print("\tP"+(i+1)+":  ");
			burst_time[i]=s.nextInt();
		}
		
		for(i=1;i<no_p;i++)
		{
			WT[i]=WT[i-1]+burst_time[i-1];
			avg_wait+=WT[i];
		}
		avg_wait/=no_p;
		
		for(i=0;i<no_p;i++)
		{
			TT[i]=WT[i]+burst_time[i];
			avg_TT+=TT[i];
		}
		avg_TT/=no_p;
		System.out.println("\n****************************************************************");
		System.out.println("\tProcesses:");
		System.out.println("****************************************************************");
		System.out.println("    Process\tBurst Time\tWaiting Time\tTurn Around Time");
		for(i=0;i<no_p;i++)
		{
			System.out.println("\tP"+(i+1)+"\t  "+burst_time[i]+"\t\t  "+WT[i]+"\t\t "+TT[i]);
			
		}
		System.out.println("\n----------------------------------------------------------------");
		System.out.println("\nAverage waiting time : "+avg_wait);
		System.out.println("\nAverage Turn Around time : "+avg_TT+"\n");
	}
}
