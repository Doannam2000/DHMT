#include <iostream>
#include <graphics.h>
#include <conio.h>

using namespace std;
void toMauDongQuet(int xa,int ya,int xb,int yb,int xc,int yc,int xd,int yd,int mau)
{
    int y1 = yd;
    int y2 = ya;
    int y = y1;
    setcolor(mau);
    while(y<=y2)
    {
        int  xm1 = int(((xa-xd)*(y - ya))/(ya-yd)) + xa;
        int  xm2 = int(((xc - xb)*(y-yb))/(yc-yb))  + xb;
        line(xm1,y,xm2,y);
        y++;
    }
}
int main()
{
    initwindow(600,600);
    int xd = 100, yd =150;
    int xc = 350, yc = 150;
    int xb = 300, yb = 250;
    int xa = 150, ya = 250;
    putpixel(xa,ya,10);
    putpixel(xb,yb,11);
    putpixel(xc,yc,12);
    putpixel(xd,yd,13);
    line(xa,ya,xb,yb);
    line(xb,yb,xc,yc);
    line(xc,yc,xd,yd);
    line(xd,yd,xa,ya);
    toMauDongQuet(xa,ya,xb,yb,xc,yc,xd,yd,5);
    getch();
    return 0;
}
