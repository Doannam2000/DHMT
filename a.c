#include<iostream>
#include<iomanip>
using namespace std;
class PTB
{
    int a,b,c;
public:
    PTB(int d, int e,int f)
    {
        a = d;
        b = e;
        c = f;
    }
    PTB()
    {
        a = 3;
        b = 3;
        c = 3;
    }
    PTB operator+(PTB k);
    PTB operator-(PTB k);
    friend istream& operator>>(istream& x, PTB &k);
    friend ostream& operator<<(ostream& x, PTB k);
};
PTB PTB::operator+(PTB k)
{
    PTB h ;
    h.a = a + k.a;
    h.b = b + k.b;
    h.c = c + k.c;
    return h;
}
PTB PTB::operator-(PTB k)
{
    PTB p;
    p.a = a - k.a;
    p.b = b - k.b;
    p.c = c - k.c;
    return p;
}
istream&operator>>(istream& x, PTB &k)
{
    cout<<"\nNhap a: ";
    x>>k.a;
    cout<<"\nNhap b: ";
    x>>k.b;
    cout<<"\nNhap b: ";
    x>>k.c;
    return x;
}
ostream&operator<<(ostream& x, PTB k)
{

    x<<k.a<<"x";
    if(k.b>0)
        cout<<" + "<<k.b<<"y";
    else
        cout<<" - "<<-k.b<<"y";
    if(k.c>0)
        cout<<" + "<<k.c;
    else
        cout<<" - "<<-k.c;
    cout<<" = 0";
    return x;
}

int main()
{
    PTB m, n;
    cout<<"Nhap phuong trinh bac nhat 2 an thu nhat: "<<endl;
    cin>>m;
    cout<<"Nhap phuong trinh bac nhat 2 an thu 2: "<<endl;
    cin>>n;
    PTB T = m+n;
    PTB H = m-n;
    cout<<"\nTong cua 2 phuong trinh :"<<endl;
    cout << T <<endl;
    cout<<"\nHieu cua 2 phuong trinh :"<<endl;
    cout << H << endl;
    return 0;
}
