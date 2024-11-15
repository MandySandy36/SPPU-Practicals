#include<iostream>
#include<graphics.h>
using namespace std;
const int TOP=8,BOTTOM=4,RIGHT=2,LEFT=1;
typedef int outcode;
outcode compute(int x, int y , int xmax, int ymax, int xmin, int ymin)
{
 	outcode oc=0;
 	if(x<xmin)
 		oc|=LEFT;
 	if(x>xmax)
 		oc|=RIGHT;
 	if(y>ymax)
 		oc|=TOP;
 	if(y<ymin)
 		oc|=BOTTOM;
	return oc;
}
void coh(int x1,int y1,int x2,int y2, int xmin,int ymin, int xmax, int ymax)
{
 	bool accept = false, done=false;double m;
 	outcode o1,o2,ot;
 	o1=compute(x1,y1,xmax,ymax,xmin,ymin);
 	o2=compute(x2,y2,xmax,ymax,xmin,ymin);
 	do
	{ 
  		if(!(o1 | o2))
  		{
   			done=true;
   			accept=true;
 		}
  		else if(o1&o2)
  		{
   			done=true;
  		}
  		else
  		{
   			int x,y;
   			ot=o1?o1:o2;
   			if(ot & TOP)
   			{
   				y=ymax;
    				x = x1 + (x2-x1)*(ymax-y1)/(y2-y1);
   			} 
   			else if(ot & BOTTOM)
   			{
    				y=ymin;
    				x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
   			}
   			else if(ot & RIGHT)
   			{
    				x=xmax;
   				y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
   			}
   			else if(ot & LEFT)
   			{
    				x=xmin;
     				y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
   			}
   			if(ot==o1)
   			{
    				x1=x;
    				y1=y;
    				o1=compute(x1,y1,xmax,ymax,xmin,ymin);
   			}
   			else
   			{
    				x2=x;
    				y2=y;
    				o2=compute(x2,y2,xmax,ymax,xmin,ymin);
   			}
  		}
 	}while(done==false);
 	if(accept==true)
 	{
  		line(x1,y1,x2,y2);
 	}
}
int main()
{
	int xmx=200,ymx=200,xmn=100,ymn=100;
 	int ax1,ay1,bx1,by1;
	cout<<"enter coordinate:";
	cin>>ax1>>ay1>>bx1>>by1;
 	int gd=DETECT,gm,x,y,j,i;
 	initgraph(&gd,&gm,NULL);
 	line(ax1,ay1,bx1,by1);
 	setcolor(4);
 	rectangle(xmn,ymn,xmx,ymx);
 	delay(5000);
 	cleardevice(); 
 	setcolor(4);
 	rectangle(xmn,ymn,xmx,ymx);
 	setcolor(15);
 	coh(ax1,ay1,bx1,by1,xmn,ymn,xmx,ymx);
 	delay(1000);
 	getch();
 	closegraph();
 	return 0;
}
