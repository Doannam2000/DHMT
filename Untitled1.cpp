#include<graphics.h>
using namespace std;
void HTCB(int xa,int xb,int xc,int xd,int mauto,int yamin,int ydmax)
{
    int xm1,xm2;
    for(int y=yamin;y<=ydmax;y++)
    {
        xm1 = (float)1.0*(xd-xa)*(y-yamin)/(ydmax-yamin)+xa;
        xm2 = (float)1.0*(xc-xb)*(y-yamin)/(ydmax-yamin)+xb;
        line(xm1,y,xm2,y);
    }
}
int main()
{
    initwindow(500,700);
    setcolor(5);
    HTCB(100,300,450,0,6,100,300);
    delay(3000);
    getch();
    closegraph();
}
