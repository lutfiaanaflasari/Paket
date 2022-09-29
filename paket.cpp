#include<iostream>
#include<conio.h>
#include<windows.h>
#define MAX 100

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

/*********************************************/

using namespace std;
struct paket
{
    int top;
    char jenis_brg[30];
    int berat;
    char kota[30];
}Tumpukan;

struct paket kirim[MAX];

/*******************************************/
    void init()
    {
        Tumpukan.top = -1;
    }

    bool isEmpty()
    {
        return Tumpukan.top == -1;
    }

    bool isFull()
    {
        return Tumpukan.top == MAX-1;
	}
/*******************************************/
void bersihlayar()
{
    for(int a=0;a<80;a++)
    {
        for(int b=0;b<=24;b++)
        {
            gotoxy(a,b);cout<<" ";
        }
    }
}

void push()
{
    if (isFull())
    {
        gotoxy(20,16); cout << "Tumpukan Penuh ! ";
    }
    else
    {
        Tumpukan.top++;
        gotoxy(42,12);cout<<"Inputkan Jenis Barang    :";
        cin>>kirim[Tumpukan.top].jenis_brg;
        gotoxy(42,13);cout<<"Inputkan Berat           :";
        cin>>kirim[Tumpukan.top].berat;
        gotoxy(42,14);cout<<"Inputkan Kota Tujuan     :";
        cin>>kirim[Tumpukan.top].kota;
    }
}

void printStack()
{
    if (isEmpty())
    {
        gotoxy(40,10); cout << " Tumupukan Kosong ";
    }
    else
    {
        gotoxy(40,10);cout<<"Daftar Kiriman Paket"<<endl;
        for(int a=Tumpukan.top; a>=0; a--)
        {
            gotoxy(40,19-a);
            cout<<a<<" ";
            cout<<kirim[a].jenis_brg<<" ";
            cout<<kirim[a].berat<<" ";
            cout<<kirim[a].kota<<endl;
        }
        gotoxy(40,20);
        cout<<"Press Any Key...";
        getch();
        /*harus Ijin --> #include<conio.h>*/
    }

}

void pop()
{
    if (isEmpty())
    {
        gotoxy(40,14); cout << " Data Kosong ";
    }
    else
    {
        gotoxy(40,12);cout<<"Data Terakhir yang anda Hapus Adalah :"<<endl;
        gotoxy(40,13);cout<<kirim[Tumpukan.top].jenis_brg<<" ";
        cout<<kirim[Tumpukan.top].berat<<" Kg ";
        cout<<kirim[Tumpukan.top].kota<<endl<<endl;

        gotoxy(40,15);cout<<"Press Any Key...";
        getch();
        Tumpukan.top--;
    }

}

int main()
{
    int pilih;
    do
    {
        bersihlayar();
        gotoxy(1,1);cout<<"MENU UTAMA";
        gotoxy(1,2);cout<<"1. Tambah Data";
        gotoxy(1,3);cout<<"2. Hapus Data Terakhir"<<endl;
        gotoxy(1,4);cout<<"3. Tampil Data"<<endl;
        gotoxy(1,5);cout<<"9. Keluar"<<endl;

        gotoxy(1,7);cout<<"Pilihan Anda [1-9] : ";
        cin>>pilih;
        if(pilih==1)
            { /*Menambah data baru diletakan di DATAKE*/
                push();
            }
        if(pilih==2)
            { /*Menghapus Data Terakhir (DATAKE-1*/
                pop();
            }
        if(pilih==3) /*Menampilkan Data mulai
                        data ke-1 hingga DATAKE*/
            printStack();

    }
    while(pilih!=9);
    return 0;
}
