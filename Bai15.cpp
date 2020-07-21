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
    float x=xmin; float y= -pow(x ,3)+1;
    ChuyenDen2D(x,y);
    while (x<=xmax)
    {
        x=x+dx;
        y=- pow(x ,3)+1);
        VeDen2D(x,y);
    }
}
void TinhTien(float x,float y,float m,float n,float &x1,float &y1)
{
    x1=x+m;
    y1=y+n;
}
void DoiXungOx(float x,float y,float &x1,float &y1)
{
    x1=x;y1=-y;
}
void DoiXungssOx(float x,float y,float y0,float &x1,float &y1)
{
    float x11,y11,x12,y12;
    TinhTien(x,y,0,-y0,x11,y11);
    DoiXungOx(x11,y11,x12,y12);
    TinhTien(x12,y12,0,y0,x1,y1);
}
void VeDoThi1(float xmin, float xmax)
{
    float dx=0.01;
    float x=xmin; float y=sin(x);
    float x1,y1;
    DoiXungssOx(x,y,-1,x1,y1);
    ChuyenDen2D(x1,y1);
    while (x<=xmax)
    {
        x=x+dx;
        y=sin(x);
        DoiXungssOx(x,y,-1,x1,y1);
        VeDen2D(x1,y1);
    }
}
int main()
{
    int gd=0, gm;
    initgraph(&gd,&gm,"");
    CuaSo(-3*M_PI, -3, 4*M_PI, 3);
    KhungNhin(150,150,450,400);
    setcolor(4);
    VeDoThi(-2,2);
    setcolor(5);
    VeDoThi1(-2*M_PI, 3*M_PI);
    getch();
    closegraph();
}
