#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
clrscr();
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C://TC//BGI");
int xwmin,xwmax,ywmin,ywmax,a3[4],i;
float m,x1,x2,y1,y2;
int a1[4]={0,0,0,0};
int a2[4]={0,0,0,0};
printf("enter the clipping window x coordinates\n");
scanf("%d%d",&xwmin,&xwmax);
printf("enter the clipping window y coordinates\n");
scanf("%d%d",&ywmin,&ywmax);
rectangle(xwmin,ywmax,xwmax,ywmin);
printf("enter the 1st endpoint\n");
scanf("%f%f",&x1,&y1);
printf("enter the 2nd endpoint\n");
scanf("%f%f",&x2,&y2);
m=(y2-y1)/(x2-x1);
line(x1,y1,x2,y2);
if(x1<xwmin)
{
a1[0]=1;
}
if(x1>xwmax)
{
a1[1]=1;
}
if(y1<ywmin)
{
a1[2]=1;
}
if(y1>ywmax)
{
a1[3]=1;
}
if(x2<xwmin)
{
a2[0]=1;
}
if(x2>xwmax)
{
a2[1]=1;
}
if(y2<ywmin)
{
a2[2]=1;
}
if(y2>ywmax)
{
a2[3]=1;
}
for(i=0;i<4;i++)
{
a3[i]=a1[i]&a2[i];
}
if(a1[0]==0 && a1[1]==0 && a1[2]==0 && a1[3]==0 && a2[0]==0 && a2[1]==0 && a2[2]==0 && a2[3]==0)
{
printf("After clipping\n");
setcolor(4);
rectangle(xwmin,ywmax,xwmax,ywmin);
line(x1,y1,x2,y2);
}
else if(a3[0]!=0 || a3[1]!=0 || a3[2]!=0 || a3[3]!=0)
{  setcolor(4);
rectangle(xwmin,ywmax,xwmax,ywmin);
}
else
{
 if(a1[0]==1)
 {
 y1=y1+m*(xwmin-x1);
 x1=xwmin;
 }
 if(a1[1]==1)
 {
 y1=y1+m*(xwmax-x1);
 x1=xwmax;
 }
 if(a1[2]==1)
 {
  x1=x1+(1/m)*(ywmin-y1);
 y1=ywmin;
 }
 if(a1[3]==1)
 {
  x1=x1+(1/m)*(ywmax-y1);
   y1=ywmax;
 }
  if(a2[0]==1)
 {
 y2=y2+m*(xwmin-x2);
 x2=xwmin;
 }
 if(a2[1]==1)
 {
 y2=y2+m*(xwmax-x2);
 x2=xwmax;
 }
 if(a2[2]==1)
 {
  x2=x2+(1/m)*(ywmin-y2);
 y2=ywmin;
 }
 if(a2[3]==1)
 {
  x2=x2+(1/m)*(ywmax-y2);
   y2=ywmax;
 }
getch();
cleardevice();
setcolor(4);
rectangle(xwmin,ywmax,xwmax,ywmin);
line(x1,y1,x2,y2);
}
getch();
closegraph();
}
