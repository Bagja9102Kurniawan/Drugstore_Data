#include <iostream>
#include <stdlib.h>
#include "drugstore.h"
#include "medicine.h"
#include "relation.h"
#include "generaloperation.h"

using namespace std;

int main()
{
    void menu();
    int pil;

    string nambat;
    string namtik;
    string Yes;
    int ID ;

    apotik aptx;
    adrapt adpt;
    Listapt lapt;

    obat medx;
    admed admd;
    limed limd;

    lire lir;

    createListApt(lapt);
    createListMed(limd);
    createListRel(lir);

    while(pil <= 15 && pil>=1)
    {
        menu();
        cin >> pil;
        switch (pil)
        {
        case 1 :
            cout << " ===================== " << endl ;
            cout << " TAMBAH APOTIK " << endl ;
            cout << "Masukkan ID apotik : ";
            cin >> aptx.IDapotik;
            adpt = findElmIDApt(lapt, aptx.IDapotik);
            while(adpt != NIL){
                cout<<"id sudah terdaftar"<<endl<< "Masukkan ID apotik : ";
                cin >> aptx.IDapotik;
            }

            cout << "nama apotik : ";
            cin >> aptx.namaApotik;

            cout << "nomor izin : ";
            cin >> aptx.noIzin;

            adpt = alokasiApt(aptx) ;

            insertLastApt(lapt,adpt) ;

            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 2 :
            cout << " ===================== " << endl ;
            cout << " TAMBAH OBAT " << endl ;
            cout << "Masukkan ID obat : ";
            cin >> medx.IDobat;
            admd = findElmIDMed(limd, medx.IDobat);
            while(adpt != NIL){
                cout<<"id sudah terdaftar"<<endl<< "Masukkan ID obat : ";
                cin >> medx.IDobat;
            }
            cout << "nama obat : ";
            cin >> medx.namaObat;

            cout << "harga obat : ";
            cin >> medx.hargaObat;

            admd = alokasiMed(medx) ;

            insertLastMed(limd,admd) ;

            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 3 :
            cout << " ===================== " << endl ;
            cout << " MENAMBAH OBAT PADA APOTIK TERTENTU " << endl ;
            connect(lir, lapt, limd);
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 4 :
            cout << " ===================== " << endl ;
            cout << " MENGHAPUS OBAT PADA APOTIK TERTENTU " << endl ;
            cout<< "Masukkan nama Apotik : "; cin>>namtik;
            adpt = findElmApt(lapt, namtik);
            while(adpt == NIL){
                cout<<" Mohon maaf apotik tidak ditemukan, ingin ulang ? Y/N"<<endl;
                cin>> Yes;
                if(Yes == "Y" || Yes == "y"){
                    cout<< "Masukkan nama Apotik : "; cin>>namtik;
                    adpt = findElmApt(lapt, namtik);
                }else if(Yes == "N" || Yes == "n"){
                    break;
                }
            }
            cout<< "Masukkan nama Obat : "; cin>>nambat;
            admd = findElmMed(limd, nambat);
            while(admd == NIL){
                cout<<" Mohon maaf obat tidak ditemukan, ingin ulang ? Y/N"<<endl;
                cin>> Yes;
                if(Yes == "Y" || Yes == "y"){
                    cout<< "Masukkan nama Obat : "; cin>>nambat;
                    admd = findElmMed(limd, nambat);
                }else if(Yes == "N" || Yes == "n"){
                    break;
                }
            }
            if(adpt != NIL && admd != NIL){
                disconnectonerel(lir, adpt, admd);
            }else{
                cout<<"Batalkan proses.............";
            }
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 5 :
            cout << " ===================== " << endl ;
            cout << " APOTIK TUTUP " << endl ;
            cout<< "Masukkan nama Apotik : "; cin>>namtik;
            adpt = findElmApt(lapt, namtik);
            while(adpt == NIL){
                cout<<" Mohon maaf apotik tidak ditemukan, ingin ulang ? Y/N"<<endl;
                cin>> Yes;
                if(Yes == "Y" || Yes == "y"){
                    cout<< "Masukkan nama Apotik : "; cin>>namtik;
                    adpt = findElmApt(lapt, namtik);
                }else if(Yes == "N" || Yes == "n"){
                    break;
                }
            }
            if(adpt != NIL){
                adrapt beforeadpt = first(lapt);
                while(next(beforeadpt)!= adpt){
                    beforeadpt = next(beforeadpt);
                }
                disconnectapt(lir,adpt) ;
                deleteAfterApt(lapt,beforeadpt,adpt) ;
                dealokasiApt(adpt);
            }else{
                cout<<"Batalkan proses.............";
            }
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 6 :
            cout << " ===================== " << endl ;
            cout << " OBAT YANG PENJUALANNYA DILARANG " << endl ;
            cout<< "Masukkan nama Obat : "; cin>>nambat;
            admd = findElmMed(limd, nambat);
            while(admd == NIL){
                cout<<" Mohon maaf obat tidak ditemukan, ingin ulang ? Y/N"<<endl;
                cin>> Yes;
                if(Yes == "Y" || Yes == "y"){
                    cout<< "Masukkan nama Obat : "; cin>>nambat;
                    admd = findElmMed(limd, nambat);
                }else if(Yes == "N" || Yes == "n"){
                    break;
                }
            }
            if(admd != NIL){
                admed beforeadmd = first(limd);
                while(next(beforeadmd)!= admd){
                    beforeadmd = next(beforeadmd);
                }
                disconnectmed(lir,admd) ;
                deleteAfterMed(beforeadmd,admd) ;
                dealokasiMed(admd);
            }else{
                cout<<"Batalkan proses.............";
            }
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 7 :
            cout << " ===================== " << endl ;
            cout << " MENCARI NOMOR IZIN APOTIK BERDASARKAN NAMA " << endl ;
            cout<< "Masukkan nama Apotik : "; cin>>namtik;
            adpt = findElmApt(lapt, namtik);
            while(adpt == NIL){
                cout<<" Mohon maaf apotik tidak ditemukan, ingin ulang ? Y/N"<<endl;
                cin>> Yes;
                if(Yes == "Y" || Yes == "y"){
                    cout<< "Masukkan nama Apotik : "; cin>>namtik;
                    adpt = findElmApt(lapt, namtik);
                }else if(Yes == "N" || Yes == "n"){
                    break;
                }
            }
            if(adpt != NIL){
                cout << "Nomor izin apotik: " << info(adpt).noIzin << endl ;
            }else{
                cout<<"Batalkan proses.............";
            }
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 8 :
            cout << " ===================== " << endl ;
            cout << " MENCARI NOMOR IZIN APOTIK BERDASARKAN ID " << endl ;
            cout<< "Masukkan ID Apotik : "; cin>>ID;
            adpt = findElmIDApt(lapt, ID);
            while(adpt == NIL){
                cout<<" Mohon maaf ID apotik tidak ditemukan, ingin ulang ? Y/N"<<endl;
                cin>> Yes;
                if(Yes == "Y" || Yes == "y"){
                    cout<< "Masukkan ID Apotik : "; cin>>ID;
                    adpt = findElmIDApt(lapt, ID);
                }else if(Yes == "N" || Yes == "n"){
                    break;
                }
            }
            if(adpt != NIL){
                cout << "Nomor izin apotik: " << info(adpt).noIzin << endl ;
            }else{
                cout<<"Batalkan proses.............";
            }
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 9 :
            cout << " ===================== " << endl ;
            cout << " MENCARI OBAT " << endl ;
            cout<< "Masukkan nama Obat : "; cin>>nambat;
            admd = findElmMed(limd, nambat);
            while(admd == NIL){
                cout<<" Mohon maaf obat tidak ditemukan, ingin ulang ? Y/N"<<endl;
                cin>> Yes;
                if(Yes == "Y" || Yes == "y"){
                    cout<< "Masukkan nama Obat : "; cin>>nambat;
                    admd = findElmMed(limd, nambat);
                }else if(Yes == "N" || Yes == "n"){
                    break;
                }
            }
            if (admd == NULL)
            {
                cout << "Mohon maaf obat belum tersedia, terimakasih sduah menggunakan layanan kami" ;
            }
            else
            {
                cout << "ID Obat: " << info(admd).IDobat <<endl<< "Harga Obat: " << info(admd).hargaObat << endl ;
            }
            cout << " ===================== " << endl ;
            cout << endl ;
        case 10 :
            cout << " ===================== " << endl ;
            cout << " MENAMPILKAN APOTIK " << endl ;
            printInfoApt(lapt) ;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 11 :
            cout << " ===================== " << endl ;
            cout << " MENAMPILKAN OBAT " << endl ;
            printInfoMed(limd) ;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 12 :
            cout << " ===================== " << endl ;
            cout << " MENAMPILKAN APOTIK YANG MEMILIKI OBAT TERTENTU " << endl ;
            cout<< "Masukkan nama Obat : "; cin>>nambat;
            admd = findElmMed(limd, nambat);
            while(admd == NIL){
                cout<<" Mohon maaf obat tidak ditemukan, ingin ulang ? Y/N"<<endl;
                cin>> Yes;
                if(Yes == "Y" || Yes == "y"){
                    cout<< "Masukkan nama Obat : "; cin>>nambat;
                    admd = findElmMed(limd, nambat);
                }else if(Yes == "N" || Yes == "n"){
                    break;
                }
            }
            if(admd != NIL){
                cout << "Obat ini tersedia di: " ;
                listMedfApt(lir, admd) ;
            }else{
                cout<<"Batalkan proses.............";
            }
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 13 :
            cout << " ===================== " << endl ;
            cout << " MENAMPILKAN OBAT YANG DIMILIKI APOTIK TERTENTU " << endl ;
            cout<< "Masukkan nama Apotik : "; cin>>namtik;
            adpt = findElmApt(lapt, namtik);
            while(adpt == NIL){
                cout<<" Mohon maaf apotik tidak ditemukan, ingin ulang ? Y/N"<<endl;
                cin>> Yes;
                if(Yes == "Y" || Yes == "y"){
                    cout<< "Masukkan nama Apotik : "; cin>>namtik;
                    adpt = findElmApt(lapt, namtik);
                }else if(Yes == "N" || Yes == "n"){
                    break;
                }
            }
            if(adpt != NIL){
                cout << "Apotik ini menyediakan obat: " ;
                listAptfMed(lir, adpt) ;
            }else{
                cout<<"Batalkan proses.............";
            }
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 14 :
            cout << " ===================== " << endl ;
            cout << " jumlah obat yang dimiliki apotik x "<< endl ;
            cout<< "Masukkan nama Apotik : "; cin>>namtik;
            adpt = findElmApt(lapt, namtik);
            while(adpt == NIL){
                cout<<" Mohon maaf apotik tidak ditemukan, ingin ulang ? Y/N"<<endl;
                cin>> Yes;
                if(Yes == "Y" || Yes == "y"){
                    cout<< "Masukkan nama Apotik : "; cin>>namtik;
                    adpt = findElmApt(lapt, namtik);
                }else if(Yes == "N" || Yes == "n"){
                    break;
                }
            }
            if(adpt != NIL){
                cout << "Jumlah obat pada apotik "<<namtik<<" saat ini adalah : "<<countMed(lir,adpt);
            }else{
                cout<<"Batalkan proses.............";
            }
            cout << " ===================== " << endl ;
        case 15 :
            cout << " ===================== " << endl ;
            cout<< "Masukkan nama Obat : "; cin>>nambat;
            admd = findElmMed(limd, nambat);
            while(admd == NIL){
                cout<<" Mohon maaf obat tidak ditemukan, ingin ulang ? Y/N"<<endl;
                cin>> Yes;
                if(Yes == "Y" || Yes == "y"){
                    cout<< "Masukkan nama Obat : "; cin>>nambat;
                    admd = findElmMed(limd, nambat);
                }else if(Yes == "N" || Yes == "n"){
                    break;
                }
            }
            if(admd != NIL){
                cout << " jumlah apotik yang memiliki obat x " <<countApt(lir,admd)<< endl ;
            }else{
                cout<<"Batalkan proses.............";
            }
            cout << " ===================== " << endl ;
            break;
        }

    }
    return 0;
}

void menu()
{
    cout << " ===================== SEHAT ASIK JAYA ASRI 4646 SDN. BHD. =====================" << endl ;
    cout << " 1. Tambah apotik " << endl ;                                      ///DONE
    cout << " 2. Tambah obat " << endl ;                                        ///DONE
    cout << " 3. Menambah obat pada apotik tertentu " << endl ;                 ///HARUSNYA DONE
    cout << " 4. Menghapus obat pada apotik tertentu " << endl ;                ///UDAH (kayaknya)
    cout << " 5. Apotik tutup " << endl ;
    cout << " 6. Obat yang penjualannya dilarang " << endl ;                    ///UDAH (kayaknya)
    cout << " 7. Mencari nomor izin apotik berdasarkan nama " << endl ;         ///UDAH (kayaknya)
    cout << " 8. Mencari nomor izin apotik berdasarkan ID " << endl ;           ///UDAH (kayaknya)
    cout << " 9. Mencari obat " << endl ;                                       ///UDAH (kayaknya)
    cout << " 10. Menampilkan apotik " << endl ;                                ///DONE
    cout << " 11. Menampilkan obat " << endl ;                                  ///DONE
    cout << " 12. Menampilkan apotik yang memiliki obat tertentu " << endl ;    ///UDAH (kayaknya)
    cout << " 13. Menampilkan obat yang dimiliki apotik tertentu " << endl ;    ///UDAH (kayaknya)
    cout << " 14. Menghitung jumlah obat yang dimiliki apotik " << endl ;       ///DONE
    cout << " 15. Menghitung jumlah apotik yang memiliki obat " << endl ;       ///DONE
    cout << " Masukkan angka selain menu diatas untuk keluar " << endl ;        ///DONE
    cout << " Pilih menu : " ;
    cout<< endl ;
}
