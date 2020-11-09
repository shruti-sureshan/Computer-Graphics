#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void boundaryfill(int x, int y, int fillcolor, int boundarycolor);
void main()
{
   	clrscr();
   	int gdriver = DETECT, gmode, errorcode;
   	int x, y, fillcolor, boundarycolor;
   	initgraph(&gdriver, &gmode,"C://TC//BGI");
printf("enter coordinates\n");
   	scanf("%d%d",&x,&y);
   	printf("enter fillcolor and boundary color\n");
   	scanf("%d%d",&fillcolor,&boundarycolor);
   	rectangle(100,100,150,150);
   	boundaryfill(x,y,fillcolor,boundarycolor);
   	getch();
   	closegraph();
}

void boundaryfill(int x, int y, int fillcolor, int boundarycolor)
{
if(getpixel(x,y)!=boundarycolor && getpixel(x,y)!=fillcolor)
{
putpixel(x,y,fillcolor);
boundaryfill(x+1,y,fillcolor,boundarycolor);
boundaryfill(x,y+1,fillcolor,boundarycolor);
boundaryfill(x-1,y,fillcolor,boundarycolor);
boundaryfill(x,y-1,fillcolor,boundarycolor);
boundaryfill(x+1,y+1,fillcolor,boundarycolor);
boundaryfill(x-1,y+1,fillcolor,boundarycolor);
boundaryfill(x-1,y-1,fillcolor,boundarycolor);
boundaryfill(x+1,y-1,fillcolor,boundarycolor);
}
}
