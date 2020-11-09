#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main()
{
clrscr();
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C://TC//BGI");
int r,i,n,p,xc,yc,x,y;
printf("enter the no of circles");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter radius\n");
scanf("%d",&r);
printf("enter centre\n");
scanf("%d%d",&xc,&yc);
x=0;
y=r;
p=1-r;
while(x<=y)
{
 putpixel((int)x+xc,(int)y+yc,3);
 putpixel((int)y+xc,(int)x+yc,3);
 putpixel((int)y+xc,(int)-x+yc,3);
 putpixel((int)x+xc,(int)-y+yc,3);
 putpixel((int)-x+xc,(int)-y+yc,3);
 putpixel((int)-y+xc,(int)-x+yc,3);
 putpixel((int)-y+xc,(int)x+yc,3);
 putpixel((int)-x+xc,(int)y+yc,3);
			if(p<0)
 			{
  				x=x+1;
  				p=p+(2*x)+1;
 			}
 			else
  			{
  				 x=x+1;
   				y=y-1;
   				p=p+(2*x)+3-(2*y);
  			}
 		} 
}
 getch();
 	closegraph();
}
