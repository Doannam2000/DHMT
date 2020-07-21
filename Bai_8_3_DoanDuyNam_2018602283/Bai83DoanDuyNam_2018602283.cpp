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
    float y= cos(x)-2;
    ChuyenDen2D(x,y);
    while (x<=xmax)
    {
        x=x+dx;
        y=cos(x)-2;
        VeDen2D(x,y);
    }
}
void TinhTien(float x,float y,float m,float n,float &x1,float &y1)
{
    x1=x+m;
    y1=y+n;
}
void DXOY(float x,float y,float &x1,float &y1)
{
    x1=-x;
    y1=y;
}
void Quay(float x,float y,float &x1,float &y1)
{
    x1=x*cos(M_PI_2/5)-y*sin(M_PI_2/5);
    y1=x*sin(M_PI_2/5)+y*cos(M_PI_2/5);
}
void Quay1(float x,float y,float &x1,float &y1)
{
    float x2,y2,x3,y3;
    TinhTien(x,y,0,10.5,x2,y2);
    Quay(x2,y2,x3,y3);
    TinhTien(x3,y3,0,-10.5,x1,y1);
}
void VeQuat()
{
    ChuyenDen2D(0,ywmin);
    VeDen2D(0,ywmax);
    float ay = ywmin , by = ywmax , cy = ywmax - 15 ,d = ywmin + 2,ax = 0 ,bx= 0 ,cx=0;
    for(int i = 0 ;i < 4 ; i++)
    {
         delay(500);
        float ax1,bx1,cx1,ay1,by1,cy1;
        Quay1(ax,ay,ax1,ay1);
        Quay1(bx,by,bx1,by1);
        Quay1(cx,cy,cx1,cy1);
        //ve thang
        ChuyenDen2D(ax1,ay1);
        VeDen2D(0,d);
        ChuyenDen2D(bx1,by1);
        VeDen2D(0,d);
        //ve giay
        ChuyenDen2D(ax,ay);
        VeDen2D(ax1,ay1);
        ChuyenDen2D(cx,cy);
        VeDen2D(cx1,cy1);
        ChuyenDen2D(bx,by);
        VeDen2D(bx1,by1);
        //ve dx thang
        ChuyenDen2D(-ax1,ay1);
        VeDen2D(0,d);
        ChuyenDen2D(-bx1,by1);
        VeDen2D(0,d);
        //vedx giay
        ChuyenDen2D(-ax,ay);
        VeDen2D(-ax1,ay1);
        ChuyenDen2D(-cx,cy);
        VeDen2D(-cx1,cy1);
        ChuyenDen2D(-bx,by);
        VeDen2D(-bx1,by1);
        ax = ax1;
        bx = bx1;
        cx = cx1;
        ay = ay1;
        by = by1;
        cy = cy1;

    }
     getch();
   // system("pause");
        ax = -ax;
        bx = -bx;
        cx = -cx;
    setcolor(BLACK);
    for(int i = 0 ;i < 4 ; i++)
    {

        float ax1,bx1,cx1,ay1,by1,cy1;
        //xoa thang
        ChuyenDen2D(ax,ay);
        VeDen2D(0,d);
        ChuyenDen2D(bx,by);
        VeDen2D(0,d);
        //xoa dx
        ChuyenDen2D(-ax,ay);
        VeDen2D(0,d);
        ChuyenDen2D(-bx,by);
        VeDen2D(0,d);
        Quay1(ax,ay,ax1,ay1);
        Quay1(bx,by,bx1,by1);
        Quay1(cx,cy,cx1,cy1);
        // xoa giay
        ChuyenDen2D(ax,ay);
        VeDen2D(ax1,ay1);
        ChuyenDen2D(cx,cy);
        VeDen2D(cx1,cy1);
        ChuyenDen2D(bx,by);
        VeDen2D(bx1,by1);
        //xoa dx giay
        ChuyenDen2D(-ax,ay);
        VeDen2D(-ax1,ay1);
        ChuyenDen2D(-cx,cy);
        VeDen2D(-cx1,cy1);
        ChuyenDen2D(-bx,by);
        VeDen2D(-bx1,by1);
        ax = ax1;
        bx = bx1;
        cx = cx1;
        ay = ay1;
        by = by1;
        cy = cy1;
        delay(500);
    }
}
int main()
{
     initwindow(1080,720);
    CuaSo(-20,-12.5,20,12.5);
    KhungNhin(50,50,1000,600);
    setcolor(3);
    VeQuat();
    getch();
    closegraph();
}

