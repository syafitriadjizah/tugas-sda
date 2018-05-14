
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
//#include <alloc.h>

using namespace std;
int pil;
int pilih_list1();
int baru_list2();
int menambah_depan_list3();
int menambah_belakang_list4();
int menambah_tengah_list5();
int hapus_depan_list6();
int hapus_belakang_list7();
int tampilkan_list8();
struct simpul
{
    char admin1[15], admin2 [20];
    int admin3;
    struct simpul *next;
} mhs, *baru, *awal=NULL, *akhir=NULL,*hapus,*bantu,*bantu1;
int posisi;
int clrscr()
{
    system("cls");
}
int main()
{
    do
    {
        clrscr();
        cout<<"MENU SINGLE LINKED LIST"<<endl;
        cout<<"1. Tambah Depan"<<endl;
        cout<<"2. Tambah Belakang"<<endl;
        cout<<"3. Tambah tengah"<<endl;
        cout<<"4. Hapus Depan"<<endl;
        cout<<"5. Hapus Belakang"<<endl;
        cout<<"6. Tampilkan"<<endl;
        cout<<"7. Selesai"<<endl;
        cout<<"Inputkan Pilihan Anda : ";
        cin>>pil;
        pilih_list1();
    } while(pil!=7);
    return 0;
}
int pilih_list1()
{
    if(pil==1)
        menambah_depan_list3();
    else if(pil==2)
  menambah_belakang_list4();
    else if(pil==3)
    menambah_tengah_list5();
     else if(pil==4)
        hapus_depan_list6();
      else if(pil==5)
        hapus_belakang_list7();
        else if(pil ==6)        
        tampilkan_list8();
    else
        cout<<"data list";
}
int baru_list2()
{
    baru=(simpul*)malloc(sizeof(struct simpul));
    cout<<"input nim   : ";cin>>baru->admin1;
    cout<<"input nama  : ";cin>>baru->admin2;
    cout<<"input umur  : ";cin>>baru->admin3;
    baru->next=NULL;
}
int menambah_depan_list3()
{
    baru_list2();
    if(awal==NULL)
    {
        awal=baru;
        akhir=baru;
        akhir->next=NULL;
    }
    else
    {
        baru->next=awal;
        awal=baru;
    }
    cout<<endl<<endl;
    tampilkan_list8();
}
int menambah_belakang_list4()
{
    baru_list2();
    if(awal==NULL)
    {
        awal=baru;
    }
    else
    {
        akhir->next=baru;
    }
    akhir=baru;
    akhir->next=NULL;
    cout<<endl<<endl;
    tampilkan_list8();
}

int menambah_tengah_list5(){
	//masukkan posisi yg ingin dicari
	cout<<"Masukkan posisi : ";cin>>posisi;
	bantu = awal;
	for(int i = 1; i<posisi--;i++){
		bantu->next = bantu;
	}
	//masukkin datanya
	baru= new simpul;
	bantu = awal;
	baru_list2();
		bantu1 = bantu -> next;
		baru -> next = bantu1;
		bantu -> next = baru;
	
    cout<<endl<<endl;
    tampilkan_list8();
}

int hapus_depan_list6()
{
    if (awal==NULL)
        cout<<"Kosong";
    else
    {
        hapus=awal;
        awal=awal->next;
        free(hapus);
    }
   cout<<endl<<endl;
    tampilkan_list8();
}
int hapus_belakang_list7()
{
    if (awal==NULL)
        cout<<"Kosong";
    else if(awal==akhir)
    {
         hapus=awal;
         awal=awal->next;
         free(hapus);
    }
    else
    {
        hapus=awal;
        while(hapus->next!=akhir)
             hapus=hapus->next;
        akhir=hapus;
        hapus=akhir->next;
        akhir->next=NULL;
        free(hapus);
    }
    cout<<endl<<endl;
    tampilkan_list8();
}
int tampilkan_list8()
{
     if (awal==NULL)
          cout<<"Kosong";
     else
     {
         bantu=awal;
         while(bantu!=NULL)
         {
            cout<<"  nim  : "<<bantu->admin1;
            cout<<"  nama : "<<bantu->admin2;
            cout<<"  umur : "<<bantu->admin3<<endl;
            bantu=bantu->next;
         }
     }
     getch();
}
