#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void floodfill(int x, int y, int oldcolor, int newcolor);
void main()
{
   	clrscr();
   	int gdriver = DETECT, gmode, errorcode;
   	int x, y, newcolor, oldcolor;
   	initgraph(&gdriver, &gmode,"C://TC//BGI");
printf("enter coordinates\n");
   	scanf("%d%d",&x,&y);
   	printf("enter oldcolor and newcolor\n");
   	scanf("%d%d",&oldcolor,&newcolor);
   	rectangle(100,100,150,150);
   	floodfill(x,y,oldcolor,newcolor);
   	getch();
   	closegraph();
}

void floodfill(int x, int y, int oldcolor, int newcolor)
{
if(getpixel(x,y)==oldcolor)
{
putpixel(x,y,newcolor);
floodfill(x+1,y,oldcolor,newcolor);
floodfill(x,y+1,oldcolor,newcolor);
floodfill(x-1,y,oldcolor,newcolor);
floodfill(x,y-1,oldcolor,newcolor);
}
}

