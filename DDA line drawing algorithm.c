#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
int sign(int xi);
int main()
{
clrscr();
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C://TC//BGI");
int x1,y1,x2,y2,dx,dy,xi,yi,x,y,i,step;
printf("Enter x1 and y1:\n");
scanf("%d%d",&x1,&y1);
printf("Enter x2 and y2:\n");
scanf("%d%d",&x2,&y2);
dx=x2-x1;
dy=y2-y1;
if(abs(dx)>=abs(dy))
{
 step=abs(dx);
}
else
{
 		step=abs(dy);
}	
xi=dx/step;
yi=dy/step;
x=x1+(0.5*sign(xi));
y=y1+(0.5*sign(yi));
i=1;
while(i<=step)
{
 		putpixel((int)x,(int)y,3);
 x=x+xi;
 y=y+yi;
 i=i+1;
}
getch();
closegraph();
}

int sign(int xi)
{
 if(xi<0)
  		return -1;
 else if(xi>0)
  		return 1;
 else
  		return 0;
}
