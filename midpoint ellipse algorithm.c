#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main()
{
clrscr();
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C://TC//BGI");
float rx,ry,xc,yc,x,y,p1,p2,dx,dy;
printf("enter the centre");
scanf("%f%f",&xc,&yc);
printf("enter rx and ry");
scanf("%f%f",&rx,&ry);
x=0;
y=ry;
p1=(ry*ry)-((rx*rx)*ry)+((rx*rx)/4);
dx=2*(ry*ry)*x;
dy=2*(rx*rx)*y;
while(dy>dx)
{
putpixel((int)x+xc,(int)y+yc,3);
putpixel((int)-x+xc,(int)y+yc,3);
putpixel((int)-x+xc,(int)-y+yc,3);
putpixel((int)x+xc,(int)-y+yc,3);
if(p1<0)
{
x=x+1;
dx=dx+(2*(ry*ry));
p1=p1+dx+(ry*ry);
}
else
{
x=x+1;
y=y-1;
dx=dx+(2*(ry*ry));
dy=dy-(2*(rx*rx));
p1=p1+dx-dy+(ry*ry);
} }

p2=(ry*ry*(x+0.5)*(x+0.5))+(rx*rx*(y-1)*(y-1))-(rx*rx*ry*ry);
while(y>=0)
{
putpixel((int)x+xc,(int)y+yc,3);
putpixel((int)-x+xc,(int)y+yc,3);
putpixel((int)-x+xc,(int)-y+yc,3);
putpixel((int)x+xc,(int)-y+yc,3);
if(p2>0)
{
y=y-1;
dy=dy-(2*rx*rx);
p2=p2+(rx*rx)-dy;
}
else
{
y=y-1;
x=x+1;
dx=dx+(2*ry*ry);
dy=dy-(2*rx*rx);
p2=p2+dx-dy+(rx*rx);
}
}
getch();
closegraph();
}




