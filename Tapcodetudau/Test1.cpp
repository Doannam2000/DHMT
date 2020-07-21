#include<graphics.h>
#include<math.h>
float xwmin,xwmax,ywmin,ywmax,tlx,tly;
int xvmin,xvmax,yvmin,yvmax;
void CuaSo(float x1,float y1,float x2,float y2)
{
    xwmin = x1;
    xwmax = x2;
    ywmin = y1;
    ywmax = y2;
}
void KhungNhin(int x,int y,int x1,int y1)
{
    xvmin = x;
    xvmax = x1;
    yvmin = y;
    yvmax = y1;
    tlx = (xvmax - xvmin)/(xwmax - xwmin);
    tly = (yvmax - yvmin)/(ywmax - ywmin);
}
void ChuyenDen2D(float x,float y)
{
    int xm=(int)(tlx*(x- xwmin)+xvmin+0.5);
    int ym=(int)(tly*(ywmax - y)+yvmin +0.5);
    moveto(xm,ym);
}
void VeDen2D(float x,float y)
{
      int xm=(int)(tlx*(x- xwmin)+xvmin+0.5);
    int ym=(int)(tly*(ywmax - y)+yvmin +0.5);
    lineto(xm,ym);
}
void VeDoThi(float xmin,float xmax)
{
    float dx =0.01;
    float x = xmin;
    float y = 2*x*x - 3;
    ChuyenDen2D(x,y);
    while(x<=xmax)
    {
        x = x+dx;
        y = 2*x*x - 3;
        VeDen2D(x,y);
    }
}
void TinhTien(float x,float y ,float m,float n,float &x1,float &y1)
{
    x1=x+m;
    y1=y+n;
}
void Quay(float x,float y,float &x1,float &y1,float a)
{
    x1 = x*cos(a) - y*sin(a);
    y1 = x*sin(a) + y*cos(a);
}
void Quay1(float x,float y,float &x1,float &y1)
{
    TinhTien(x,y,0,3,x1,y1);
    Quay(x1,y1,x,y,M_PI_2);
    TinhTien(x,y,0,-3,x1,y1);
}
void VeDoThi1(float xmin,float xmax)
{
    float dx = 0.01;
    float x=xmin;
    float y =2*x*x - 3;
    float x1,y1;
    Quay1(x,y,x1,y1);
    ChuyenDen2D(x1,y1);
    while(x<=xmax)
    {
        x = x+dx;
        y=2*x*x - 3;
        Quay1(x,y,x1,y1);
        VeDen2D(x1,y1);
    }
}
void khung_ox_oy()
{
    ChuyenDen2D(xwmin,0);
    VeDen2D(xwmax,0);
    ChuyenDen2D(0,ywmin);
    VeDen2D(0,ywmax);
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
    setcolor(3);
    VeDoThi1(0,2);
    getch();
    closegraph();
}

