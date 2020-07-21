#include <graphics.h>
#include <math.h>
float xwmin,ywmin,xwmax,ywmax,tlx,tly;
int xvmin,yvmin,xvmax,yvmax;
void CuaSo(float x1, float y1, float x2, float y2)
{
    xwmin=x1;
    ywmin=y1;
    xwmax=x2;
    ywmax=y2;
}
void KhungNhin(int x1, int y1, int x2, int y2)
{
    xvmin=x1;
    yvmin=y1;
    xvmax=x2;
    yvmax=y2;
    tlx=(xvmax-xvmin)/(xwmax-xwmin);
    tly=(yvmax-yvmin)/(ywmax-ywmin);
}
void ChuyenDen2D(float x, float y)
{
    int xm= (int)(tlx*(x-xwmin)+xvmin+0.5);
    int ym= (int)(tly*(ywmax-y)+yvmin+0.5);
     moveto(xm,ym);
}
void VeDen2D(float x, float y)
{
    int xm= (int)(tlx*(x-xwmin)+xvmin+0.5);
    int ym= (int)(tly*(ywmax-y)+yvmin+0.5);
    lineto(xm,ym);
}
void VeDoThi(float xmin, float xmax)
{
    float dx=0.01;
    float x=xmin;
    float y= 2*x*x - 3;
    ChuyenDen2D(x,y);
    while (x<=xmax)
    {
        x=x+dx;
        y=2*x*x - 3;
        VeDen2D(x,y);
    }
}
void TinhTien(float x,float y,float m,float n,float &x1,float &y1)
{
    x1=x+m;
    y1=y+n;
}
void Quay(float x,float y,float &x1,float &y1,float a)
{
    x1=x*cos(a)-y*sin(a);
    y1=x*sin(a)+y*cos(a);
}
void Quay1(float x,float y,float &x1,float &y1)
{
    float x2,y2,x3,y3;
    TinhTien(x,y,0,3,x2,y2);
    Quay(x2,y2,x3,y3,-M_PI_2);
    TinhTien(x3,y3,0,-3,x1,y1);
}
void VeDoThi1(float xmin, float xmax)
{
    float dx=0.01;
    float x=xmin;
    float y= 2*x*x - 3 ;
    float x1 =x ,y1 = y;
    Quay1(x,y,x1,y1);
    ChuyenDen2D(x1,y1);
    while (x<=xmax)
    {
        x=x+dx;
        y=2*x*x - 3;
        Quay1(x,y,x1,y1);
        VeDen2D(x1,y1);
    }
}
void VietChu2D(float x,float y,char *s)
{
    ChuyenDen2D(x,y);
    settextstyle(10,0,1);
    outtext(s);
}
void khung_ox_oy()
{
    ChuyenDen2D(xwmin,0);
    VeDen2D(xwmax,0);
    ChuyenDen2D(0,ywmin);
    VeDen2D(0,ywmax);
    ChuyenDen2D(0,ywmax);
    VeDen2D(-0.2,ywmax-0.2);
    ChuyenDen2D(0,ywmax);
    VeDen2D(0.2,ywmax-0.2);
    ChuyenDen2D(xwmax - 0.2 , -0.2);
    VeDen2D(xwmax,0);
    ChuyenDen2D(xwmax-0.2, 0.2);
    VeDen2D(xwmax,0);
    for(int i=0;i<xwmax;i = i++)
    {
        ChuyenDen2D(i,0.1);
        VeDen2D(i,-0.1);
    }
    for(int i=0;i>xwmin;i = i--)
    {
        ChuyenDen2D(i,0.1);
        VeDen2D(i,-0.1);
    }
    for(int i=0;i<ywmax;i++)
    {
        ChuyenDen2D(-0.1,i);
        VeDen2D(0.1,i);
    }
    for(int i=0;i>ywmin;i--)
    {
        ChuyenDen2D(-0.1,i);
        VeDen2D(0.1,i);
    }
    VietChu2D(-0.5,-0.2,"O");
    VietChu2D(xwmax,-0.3,"x");
    VietChu2D(-0.5,ywmax,"y");
}
int main()
{
    int gd=0,gm;
    initgraph(&gd,&gm,"");
    CuaSo(-2,-6,9,6);
    KhungNhin(40,40,400,400);
    setcolor(3);
    //rectangle(40,40,400,400);
    setcolor(7);
    khung_ox_oy();
    setcolor(5);
    VeDoThi(0,2);
    setcolor(4);
    VeDoThi1(0,2);
    getch();
    closegraph();
}

