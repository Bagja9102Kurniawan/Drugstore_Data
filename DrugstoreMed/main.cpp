#include <iostream>
#include "drugstore.h"
#include "medicine.h"
#include "relation.h"
#include "generaloperation.h"

using namespace std;

int main()
{
    int pil;

    apotik aptx;
    adrapt adpt;
    Listapt lapt;

    obat medx;
    admed admd;
    limed limd;

    switch (pil)
    {
        case 1 :
            cout << " ===================== " << endl ;
            cout << " TAMBAH APOTIK " << endl ;
            cout << "Masukkan ID apotik : ";
            cin >> aptx.IDapotik;
            cout << "nama apotik : ";
            cin >> aptx.namaApotik;
            cout << "nomor izin : ";
            cin >> aptx.noIzin;
            alokasi(aptx) ;
            insertLast(lapt,adpt) ;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 2 :
            cout << " ===================== " << endl ;
            cout << " TAMBAH OBAT " << endl ;
            cout << "Masukkan ID obat : ";
            cin >> medx.IDobat;
            cout << "nama obat : ";
            cin >> medx.namaObat;
            cout << "harga obat : ";
            cin >> medx.hargaObat;
            alokasi(admd) ;
            insertLast(limd,admd) ;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 3 :
            cout << " ===================== " << endl ;
            cout << " MENAMBAH OBAT PADA APOTIK TERTENTU " << endl ;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 4 :
            cout << " ===================== " << endl ;
            cout << " MENGHAPUS OBAT PADA APOTIK TERTENTU " << endl ;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 5 :
            cout << " ===================== " << endl ;
            cout << " APOTIK TUTUP " << endl ;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 6 :
            cout << " ===================== " << endl ;
            cout << " OBAT YANG PENJUALANNYA DILARANG " << endl ;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 7 :
            cout << " ===================== " << endl ;
            cout << " MENCARI NOMOR IZIN APOTIK BERDASARKAN NAMA " << endl ;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 8 :
            cout << " ===================== " << endl ;
            cout << " MENCARI NOMOR IZIN APOTIK BERDASARKAN ID " << endl ;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 9 :
            string nama ;
            obat cari;
            admed R ;
            cout << " ===================== " << endl ;
            cout << " MENCARI OBAT " << endl ;
            cout << "Masukkan nama obat: " ;
            cin >> cari.namaObat >> endl ;
            R = findElm(L1,cari)
            if (R == NULL)
            {
                cout << "Obat tidak ditemukan" ;
            }
            else
            {
                cout << "ID Obat: " << cari.IDobat << " dengan harga: " << cari.hargaObat << endl ;
            }
            cout << " ===================== " << endl ;
            cout << endl ;
        case 10 :
            cout << " ===================== " << endl ;
            cout << " MENAMPILKAN APOTIK " << endl ;
            printInfo(L1) ;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 11 :
            cout << " ===================== " << endl ;
            cout << " MENAMPILKAN OBAT " << endl ;
            printInfo(L2) ;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 12 :
            cout << " ===================== " << endl ;
            cout << " MENAMPILKAN APOTIK YANG MEMILIKI OBAT TERTENTU " << endl ;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        case 13 :
            cout << " ===================== " << endl ;
            cout << " MENAMPILKAN OBAT YANG DIMILIKI APOTIK TERTENTU " << endl ;
            cout << " ===================== " << endl ;
            cout << endl ;
            break ;
        }
    }
    while ((menu >=1) && (menu <= 13)) ;


    return 0;
}

int menu(){
    cout << " =====================SEHAT ASIK JAYA ASRI 4646=====================" << endl ;
    cout << " 1. Tambah apotik " << endl ;
    cout << " 2. Tambah obat " << endl ;
    cout << " 3. Menambah obat pada apotik tertentu " << endl ;
    cout << " 4. Menghapus obat pada apotik tertentu  " << endl ;
    cout << " 5. Apotik tutup " << endl ;
    cout << " 6. Obat yang penjualannya dilarang " << endl ;
    cout << " 7. Mencari nomor izin apotik berdasarkan nama " << endl ;
    cout << " 8. Mencari nomor izin apotik berdasarkan ID " << endl ;
    cout << " 9. Mencari obat " << endl ;
    cout << " 10. Menampilkan apotik " << endl ;
    cout << " 11. Menampilkan obat " << endl ;
    cout << " 12. Menampilkan apotik yang memiliki obat tertentu " << endl ;
    cout << " 13. Menampilkan obat yang dimiliki apotik tertentu " << endl ;
    cout << " Pilih menu : " ;
    cout<< endl ;
}
