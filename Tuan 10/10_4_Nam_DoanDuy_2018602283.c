# include <graphics.h>
# include <math.h>
typedef struct
{float x; float y; float z;}diem3D;
typedef struct
{int x; int y;}diem2Di;
typedef struct
{float x; float y;}diem2Df;
typedef struct
{diem3D d1; diem3D d2;}canh;
float R, phi, teta, D, tlx, tly;
int phepchieu; //Quy uoc phepchieu =1: phoi canh; =0: song song
diem2Di o; // O goc toa do hien thi tren man hinh
diem3D a[8];
canh c[12];
// Xay dung cac ham phu tro
void chuyenhqs(diem3D m, diem3D &mv )
// Tính Mv la toa do cua M trong he toa do quan sat
{ mv.x= -m.x*sin(teta)+m.y*cos(teta);
mv.y= -m.x*cos(teta)*sin(phi)-m.y*sin(teta)*sin(phi)+m.z*cos(phi);
mv.z= -m.x*sin(teta)*cos(phi) - m.y*cos(teta)*sin(phi)-m.z*sin(phi)+R;
}
void chieu3D_2D (diem3D mv, diem2Df &mp )
// Tinh toa do Mp tren mat phang chieu P
{ if (phepchieu==1)
{ mp.x=D*mv.x/mv.z; mp.y=D*mv.y/mv.z;}
else

{ mp.x=mv.x; mp.y=mv.y;}
}
void chuyenmh(diem2Df mp, diem2Di &mm)
//Tinh toa do Mm trên màn hình tuong ung voi Mp
{ mm.x= (int) (tlx*mp.x+o.x+0.5);
mm.y= (int) (-tly*mp.y +o.y+0.5);
}
// Hai ham de ve doan thang
void chuyenden3D(diem3D m)
{ diem3D mv; diem2Df mp; diem2Di mm;
chuyenhqs(m,mv);
chieu3D_2D(mv,mp);
chuyenmh(mp,mm);
moveto(mm.x,mm.y);
}
void veden3D(diem3D m)
{ diem3D mv; diem2Df mp; diem2Di mm;
chuyenhqs(m,mv);
chieu3D_2D(mv,mp);
chuyenmh(mp,mm);
lineto(mm.x,mm.y);
}
void khoitao()
{ R=5; phi=30; teta=0; D=3; tlx=50; tly=50;
teta=teta*M_PI/180; phi=phi*M_PI/180;
phepchieu=0;
o.x=getmaxx()/2;
o.y=getmaxy()/2;
}
diem3D p[3];

diem3D q[3][3];
void khoitaoBezier()
{
// Gan gia tri diem dieu khien
p[0].x=1; p[0].y=0; p[0].z=-1;
p[1].x=2; p[1].y=1;p[1].z=2;
p[2].x=4; p[2].y=-3;p[2].z=1;
p[3].x=5; p[3].y=0;p[3].z=-1;

//Ve duong noi cac diem dieu khien
chuyenden3D(p[0]);
for(int i=1; i<=3; i++) veden3D(p[i]);
}

diem3D BezierFunc (float u)
{ // Theo thuật toán Casteljau
for(int i=0; i<=3; i++) q[i][0]=p[i];
for(int j=1; j<=3; j++)
for(int i=j; i<=3; i++)
{ q[i][j].x=(1-u)*q[i-1][j-1].x+u*q[i][j-1].x;
q[i][j].y=(1-u)*q[i-1][j-1].y+u*q[i][j-1].y;
q[i][j].z=(1-u)*q[i-1][j-1].z+u*q[i][j-1].z;
}
return q[3][3];
}
diem3D TaoDiem(float x,float y , float z)
{
    diem3D c;
    c.x=x; c.y= y; c.z = z;
    return c;
}
void outtextxyz(diem3D x,char *s)
{
    chuyenden3D(x);
    settextstyle(10,0,1);
    outtext(s);
}
void khung_oxyz()
{
    diem3D a,b,c;
     a=TaoDiem(0,0,0);
     b=TaoDiem(0,0,5);
    // truc OZ
    chuyenden3D(a);
    veden3D(b);
    //ve mui ten
    chuyenden3D(b);
    c=TaoDiem(0,-0.2,4.8);
    veden3D(c);
    c=TaoDiem(0,-0.4,4.8);
    outtextxyz(c,"z");
    chuyenden3D(b);
    c=TaoDiem(0,0.2,4.8);
    veden3D(c);

    //truc Oy
     b=TaoDiem(0,5,0);
    chuyenden3D(a);
    veden3D(b);
    //ve mui ten
    chuyenden3D(b);
    c=TaoDiem(0.2,4.8,0);
    veden3D(c);
    c=TaoDiem(0.4,4.8,0);
    outtextxyz(c,"y");
    chuyenden3D(b);
    c=TaoDiem(-0.2,4.8,0);
    veden3D(c);

    //truc OX

    b=TaoDiem(8,0,0);
     chuyenden3D(a);
    veden3D(b);
    //ve mui ten
    chuyenden3D(b);
    c=TaoDiem(7.8,0.2,0);
    veden3D(c);
    c=TaoDiem(7.8,0.4,0);
    outtextxyz(c,"x");
    chuyenden3D(b);
    c=TaoDiem(7.8,-0.2,0);
    veden3D(c);
}
void veBezier()
{ float stepu=0.01;
diem3D b=BezierFunc(0);
chuyenden3D(b);
for (float u=stepu; u<=1; u+=stepu)
{ b=BezierFunc(u);
veden3D(b); }
}

int main()
{ int gd=0, gm; initgraph(&gd, &gm, "");
khoitao();
khoitaoBezier();
khung_oxyz();
veBezier();
getch();
closegraph();
return 0;
}
