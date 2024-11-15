import java.io.*;
      class lru
        {
        public static void main(String args[])throws IOException
         {
		  BufferedReader obj=new BufferedReader(new InputStreamReader(System.in));
	       	  int f,page=0,ch,pgf=0,n,chn=0;
	    	  boolean flag;
	       	  int pages[]; 		//pgf-page fault
	      
    	  	System.out.println("1.LRU");
     		int pt=0;
         	System.out.println("enter no. of frames: ");
	     	 f=Integer.parseInt(obj.readLine());
	      	int frame[]=new int[f];


      		for(int i=0;i<f;i++)
      		{
      			frame[i]=-1;
      		}

	       	System.out.println("enter the no of pages ");
	      	n=Integer.parseInt(obj.readLine());

      	         pages=new int[n];
      		System.out.println("enter the page no ");

	      	for(int j=0;j<n;j++)
	     	pages[j]=Integer.parseInt(obj.readLine());
	       	
       		int pg=0;
       		for(pg=0;pg<n;pg++)
            	{
      			page=pages[pg];				
       			flag=true;
      			for(int j=0;j<f;j++)
     			{
       				if(page==frame[j])
       				{
       					flag=false;
      	 				break;
       				 }
       			}
			int temp,h=3,i;
       			if(flag)
        		{
        			if( frame[1]!=-1 && frame[2]!=-1 && frame[0]!=-1)
				{
					temp=pages[pg-3];
					if(temp==pages[pg-2] || temp==pages[pg-1]) 
						temp=pages[pg-4];    
					     
					for(i=0;i<f;i++)
						if(temp==frame[i])
							break;
					frame[i]=pages[pg];
				}
				else
				{
					if(frame[0]==-1)
						frame[0]=pages[pg];
					else if(frame[1]==-1)
						frame[1]=pages[pg];
					else if(frame[2]==-1)
						frame[2]=pages[pg];
				}  
			   

			       	System.out.print("frame :");
			      	for(int j=0;j<f;j++)
			       	System.out.print(frame[j]+"   ");
			    	System.out.println();
		       		pgf++;
		       	}
     		 	else
		      	{
			      	System.out.print("frame :");
			       	for(int j=0;j<f;j++)
			      	System.out.print(frame[j]+"  ");
			    	System.out.println();
		       	}
    	
      	 	}//for
       
        	System.out.println("Page fault:"+pgf);

}//main
}//class

