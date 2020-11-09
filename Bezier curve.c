#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
clrscr();
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C://TC//BGI");
float x,y,x1,x2,x3,x4,y1,y2,y3,y4;
float u=0.001;
printf("enter coordinates\n");
scanf("%f%f",&x1,&y1);
scanf("%f%f",&x2,&y2);
scanf("%f%f",&x3,&y3);
scanf("%f%f",&x4,&y4);
while(u<=1.001)
{
x=(((1-u)*(1-u)*(1-u)*x4)+(3*u*(1-u)*(1-u)*x3)+(3*u*u*(1-u)*x2)+(u*u*u*x1));
y=(((1-u)*(1-u)*(1-u)*y4)+(3*u*(1-u)*(1-u)*y3)+(3*u*u*(1-u)*y2)+(u*u*u*y1));
putpixel((float)x,(float)y,3);
u=u+0.001;
}
getch();
closegraph();
}
