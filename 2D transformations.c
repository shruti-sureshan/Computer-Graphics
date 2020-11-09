#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void main()
{
 clrscr();
 int gdriver=DETECT,gmode;
 initgraph(&gdriver,&gmode,"C://TC//BGI");
 float sx,sy,l,r,xs,ys;
 int xmax,ymax,tx,ty,ch,i,xf,yf,ans[10],j,o,c,d;
 float b[3][3];
 int a[10]={100,50,200,50,200,100,100,100,100,50};
 float xmid,ymid;
 xmax=getmaxx();
 ymax=getmaxy();
 xmid=xmax/2;
 ymid=ymax/2;
 line(0,ymid,xmax,ymid);
 line(xmid,0,xmid,ymax);
 for(i=0;i<8;i=i+2)
 {
 line(xmid+a[i],ymid-a[i+1],xmid+a[i+2],ymid-a[i+3]);
 }
  printf("1.Translation\n2.Scaling\n3.Rotation\n4.Reflection\n5.Shearing\nEnter your choice: ");
  scanf("%d",&ch);
 switch(ch)
 {
 case 1:printf("enter tx and ty\n");
	scanf("%d%d",&tx,&ty);
	b[0][0]=b[1][1]=b[2][2]=1;
	b[0][2]=tx;
	b[1][2]=ty;
	b[0][1]=b[1][0]=b[2][0]=b[2][1]=0;
	break;
 case 2:printf("enter sx and sy: ");
	scanf("%f%f",&sx,&sy);
	printf("1.scaling\n2.scaling about fixed point\nenter your choice:  ");
	scanf("%d",&c);
	if(c==1)
	{
	b[2][2]=1;
	b[0][0]=sx;
	b[1][1]=sy;
	b[0][1]=b[0][2]=b[1][0]=b[1][2]=b[2][0]=b[2][1]=0;
	}
	else if(c==2)
	{
	printf("enter the fixed point: ");
	scanf("%d%d",&xf,&yf);
	b[2][2]=1;
	b[0][0]=sx;
	b[1][1]=sy;
	b[0][2]=xf-(xf*sx);
	b[1][2]=yf-(yf*sy);
	}
	else
	printf("enter proper choice");
	break;
 case 3:printf("enter angle: ");
	scanf("%d",&o);
	r=o*(3.1416/180);
	printf("1.clockwise\n2.anticlockwise\nenter your choice: ");
	scanf("%d",&c);
	if(c==1)
	{
	l=r*-1;
	}
	else
	{
	l=r;
	}
	printf("1.rotation\n2.rotation about fixed point\nenter your choice: ");
	scanf("%d",&d);
	if(d==1)
	{
	b[0][0]=cos(l);
	b[0][1]=(-1)*sin(l);
	b[1][0]=sin(l);
	b[1][1]=cos(l);
	b[2][2]=1;
	b[0][2]=b[1][2]=b[2][0]=b[2][1]=0;
	}
	else if(d==2)
	{
	printf("enter fixed point: ");
	scanf("%d%d",&xf,&yf);
	b[0][0]=cos(l);
	b[0][1]=(-1)*sin(l);
	b[1][0]=sin(l);
	b[1][1]=cos(l);
	b[2][2]=1;
	b[0][2]=xf-(cos(l)*xf)+(sin(l)*yf);
	b[1][2]=yf-(cos(l)*yf)-(sin(l)*xf);
	}
	else
	printf("enter proper choice\n");
	break;
 case 4:
 printf("1.about x axis\n2.about y axis\n3.about origin\n4.about y=x\n5.about y=-x\nenter your choice:");
	scanf("%d",&c);
	b[0][0]=b[0][2]=b[1][1]=b[1][2]=b[2][0]=b[2][1]=0;
	if(c==1)
	{
	b[0][0]=b[2][2]=1;
	b[1][1]=-1;
	}
	else if(c==2)
	{
	b[0][0]=-1;
	b[1][1]=b[2][2]=1;
	}
	else if(c==3)
	{
	b[0][0]=b[1][1]=-1;
	b[2][2]=1;
	}
	else if(c==4)
	{
	b[0][1]=1;
	b[1][0]=1;
	b[2][2]=1;
	b[0][0]=b[0][2]=b[1][1]=b[1][2]=b[2][0]=b[2][1]=0;
	}
	else if(c==5)
	{
	b[0][1]=-1;
	b[1][0]=-1;
	b[2][2]=1;
	b[0][0]=b[0][2]=b[1][1]=b[1][2]=b[2][0]=b[2][1]=0;
	}
	else
	{
	printf("enter proper choice");
	}
	break;
 case 5:printf("1.x shear\n2.y shear\nenter your choice: ");
	scanf("%d",&c);
	printf("enter value of shx and shy: ");
	scanf("%f%f",&xs,&ys);
	if(c==1)
	{
	b[0][0]=b[1][1]=b[2][2]=1;
	b[0][1]=xs;
	b[0][2]=b[1][0]=b[1][2]=b[2][0]=b[2][1]=0;
	}
	else if(c==2)
	{
	b[0][0]=b[1][1]=b[2][2]=1;
	b[1][0]=ys;
	b[0][1]=b[0][2]=b[1][2]=b[2][0]=b[2][1]=0;
	}
	else
	{
	printf("enter proper choice\n");
 }
 break;
 }
 for(j=0;j<=8;j=j+2)
 {
 ans[j]=(b[0][0]*a[j])+(b[0][1]*a[j+1])+b[0][2];
 ans[j+1]=(b[1][0]*a[j])+(b[1][1]*a[j+1])+b[1][2];
 }
 for(i=0;i<8;i=i+2)
 {
 line(xmid+ans[i],ymid-ans[i+1],xmid+ans[i+2],ymid-ans[i+3]);
 }
 getch();
 closegraph();
}
