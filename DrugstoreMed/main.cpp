#include <iostream>
#include "drugstore.h"
#include "medicine.h"
#include "relation.h"
#include "generaloperation.h"

using namespace std;

int main()
{
    int  menu ;
    Listapt L1 ;
    limed L2 ;
    apotik x ;
    obat y ;
    adrapt P1 ;
    admed P2 ;
    createList(L1) ;
    createList(L2) ;
    do
    {
        cout << " =====================SEHAT JAYA SDN. BHD.=====================" << endl ;
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
        cin >> menu ;
        cout<< endl ;
        switch (menu)
        {
            case 1 :
                cout << " ===================== " << endl ;
                cout << " TAMBAH APOTIK " << endl ;
                cout << "Masukkan ID apotik, nama apotik, dan nomor izin: " ;
                cin >> x.IDapotik >> x.namaApotik >> x.noIzin ;
                alokasi(x) ;
                insertFirst(L1,P1) ;
                cout << " ===================== " << endl ;
                cout << endl ;
                break ;
            case 2 :
                cout << " ===================== " << endl ;
                cout << " TAMBAH OBAT " << endl ;
                cout << "Masukkan ID obat, nama obat, dan harga obat: " ;
                cin >> y.IDobat >> y.namaObat >> y.hargaObat ;
                alokasi(y) ;
                insertFirst(L2,P2) ;
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
