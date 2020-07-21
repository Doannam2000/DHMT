#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class SACHGK;
class TacGia
{
private:
    char TenTacGia[15];
    char DiaChi_TG[15];
public:
    friend class SACHGK;
};
class NXB
{
private:
    char TenNXB[15];
    char DiaChi_NXB[15];
public:
    friend class SACHGK;
    friend void NhaXB(SACHGK a[],int n);
};
class IDSACH
{
private:
    char TenSach[15];
    char MaSach[15];
public:
    void Nhap()
    {
        cout << "Nhap ten tac sach :" ;
        fflush(stdin);
        gets(TenSach);
        cout << "Nhap ten ma sach :" ;
        fflush(stdin);
        gets(MaSach);
    }
    void Xuat()
    {
        cout<<setw(15) <<TenSach;
        cout<<setw(15)<<MaSach;
    }
    friend void TenSach(SACHGK a[],int n);
};
class SACHGK : public IDSACH
{
private:
    TacGia x;
    NXB y;
public:
    void Nhap();
    void Xuat();
    friend void NhaXB(SACHGK a[],int n);
    friend void TenSach(SACHGK a[],int n);
};
void SACHGK::Nhap()
{
    IDSACH::Nhap();
    cout << "Nhap ten tac gia :" ;
    fflush(stdin);
    gets(x.TenTacGia);
    cout << "Nhap dia chi tac gia :" ;
    fflush(stdin);
    gets(x.DiaChi_TG);
    cout << "Nhap ten nha xuat ban :" ;
    fflush(stdin);
    gets(y.TenNXB);
    cout << "Nhap dia chi nha xuat ban :" ;
    fflush(stdin);
    gets(y.DiaChi_NXB);
}
void SACHGK::Xuat()
{
    IDSACH::Xuat();
    cout<<setw(15)<<x.TenTacGia;
    cout<<setw(15)<<x.DiaChi_TG;
    cout<<setw(15)<<y.TenNXB;
    cout<<setw(15)<<y.DiaChi_NXB <<endl;
}
void Hien()
{
    cout<<setw(4) <<"STT";
    cout << setw(15) << "TenSach";
    cout << setw(15) << "MaSach";
    cout << setw(15) << "TenTG" ;
    cout << setw(15) << "DiaChiTG";
    cout << setw(15) << "TenNXB";
    cout << setw(15) << "DiaChiNXB"<<endl;
}
void NhaXB(SACHGK a[],int n)
{
    int d =0;
    cout<<"\t\t -----Thong tin sach cua nha xuat ban GiaoDuc------"<<endl;
    Hien();
    for(int i =0; i<n; i++)
    {
        if(stricmp(a[i].y.TenNXB,"GiaoDuc")==0)
        {
            d++;
            cout << setw(4) <<d;
            a[i].Xuat();
        }
    }
    if(d==0)
        cout<<"\t\t------ Khong co -----" <<endl;
}
void TenSach(SACHGK a[],int n)
{
    int d =0;
    cout<<"\t\t -----Thong tin sach co ten sach LTHDT ------"<<endl;
    Hien();
    for(int i =0; i<n; i++)
    {
        if(stricmp(a[i].TenSach,"LTHDT")==0)
        {
            d++;
            cout << setw(4) <<d;
            a[i].Xuat();

        }
    }
    if(d==0)
        cout<<"\t\t------ Khong co -----" <<endl;
}
void Chen(SACHGK a[],int n)
{
    int k;
    SACHGK p;
    cout<<"Nhap thong tin sach giao khoa moi "<<endl;
    p.Nhap();
    do
    {
        cout<<"Nhap so nguyen duong k (1<=k<="<<n+1<<") :";
        cin >>k;
        if(k<1 || k > n+1)
            cout<<"Nhap lai";
    }
    while(k<1 || k > n+1);
    n++;
    k--;
    a=(SACHGK*)realloc(a,n*sizeof(SACHGK));
    for(int  i = n; i>k ; i--)
    {
        a[i] = a[i - 1];
    }
    a[k] = p;
    cout<<"\t\t -----Thong tin sach sau khi chen ------"<<endl;
    Hien();
    for(int i = 0 ; i<n ; i++)
    {
        cout<<setw(4) << i+1;
        a[i].Xuat();
    }
}
int main()
{
    int n;
    cout <<"Nhap so luong sach :";
    cin >> n;
    SACHGK *a = (SACHGK*)realloc(0,n*sizeof(SACHGK));
    cout<<"\t\t -----Nhap thong sach------"<<endl;
    for(int i = 0; i<n; i++)
    {
        cout << "Nhap thong sach "<< i +1 <<endl;
        a[i].Nhap();
    }
    cout<<"\t\t -----Thong tin sach------"<<endl;
    Hien();
    for(int i = 0; i<n; i++)
    {
        cout << setw(4) << i + 1;
        a[i].Xuat();
    }
    NhaXB(a,n);
    TenSach(a,n);
    Chen(a,n);
    cout <<"\t\t------------------------------------------";
    free(a);
    system("pause");
    return 0;
}
