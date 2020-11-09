#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
clrscr();
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C://TC//BGI");
float temp,xwmin,xwmax,ywmin,ywmax,x1,y1,x2,y2,dx,dy,p[4],q[4],i,t1=0,t2=1;
float xx1,xx2,yy1,yy2;
printf("enter the clipping window x coordinates\n");
scanf("%f%f",&xwmin,&xwmax);
printf("enter the clipping window y coordinates\n");
scanf("%f%f",&ywmin,&ywmax);
rectangle(xwmin,ywmax,xwmax,ywmin);
printf("enter the 1st endpoint\n");
scanf("%f%f",&x1,&y1);
printf("enter the 2nd endpoint\n");
scanf("%f%f",&x2,&y2);
line(x1,y1,x2,y2);
dx=x2-x1;
dy=y2-y1;
p[0]=-dx;
p[1]=dx;
p[2]=-dy;
p[3]=dy;
q[0]=x1-xwmin;
q[1]=xwmax-x1;
q[2]=y1-ywmin;
q[3]=ywmax-y1;
for(i=0;i<4;i++)
{
	if(p[i]==0)
	{
		printf("line is parallel to boundary\n");

		if(q[i]>=0)
		{
		    //  printf("line is inside\n");
			if(i<2)
			{
				if(y2>ywmax)
				{
					y2=ywmax;
				}
				if(y1<ywmin)
				{
					y1=ywmin;
				}
			}
			if(i>1)
			{
				if(x2>xwmax)
				{
					x2=xwmax;
				}
				if(x1<xwmin)
				{
					x1=xwmin;
				}
			}
			setcolor(3);
			line(x1,y1,x2,y2);
		}
	}

}
for(i=0;i<4;i++)
{
	temp=q[i]/p[i];
	if(p[i]<0)
	{
		if(t1<=temp)
		t1=temp;
	}
	else
	{
		if(t2>temp)
		t2=temp;
	}
}
if(t1<t2)
{
xx1=x1+(t1*dx);
xx2=x1+(t2*dx);
yy1=y1+(t1*dy);
yy2=y1+(t2*dy);
setcolor(3);
line(xx1,yy1,xx2,yy2);
//}
getch();
cleardevice();
rectangle(xwmin,ywmax,xwmax,ywmin);
line(xx1,yy1,xx2,yy2);
}

getch();
closegraph();
}
