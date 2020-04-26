#include "generaloperation.h"

void connect(lire L, Listapt P, limed C){
    /**Bagja 9102 Kurniawan (1301194020)*/
    admed M;
    adrapt N;
    string aptk,medi,yes;
    cout << "masukkan nama apotik : ";
    cin >> aptk;
    N = findElmApt(P, aptk);
    while(N == NIL){
        cout << "apotik tidak ditemukan, mohon coba lagi Y/N "<<endl;
        cin >> yes;
        if(yes == "Y" || yes == "y"){
            cout << "masukkan nama apotik : ";
            cin >> aptk;
        }else if(yes == "N" || yes == "n"){
            break;
        }
        N = findElmApt(P, aptk);
    }
    if(N != NIL){
        cout << "masukkan nama obat ";
        cin >> medi;
        M = findElmMed(C, medi);
        while(M == NIL){
            cout << "obat tidak ditemukan, mohon coba lagi "<<endl;
            cin >> yes;
            if(yes == "Y" || yes == "y"){
                cout << "masukkan nama obat : ";
                cin >> medi;
            }else if(yes == "N" || yes == "n"){
                break;
            }
            M = findElmMed(C, medi);
        }
    }else if(N==NIL||M==NIL){
        cout<<"Batalkan proses.............";
    }
    if(isredundant(L,N,M)==false){
       if(N!=NIL&&M!=NIL){
            adre Rel = alokasiRel(N,M);
            insertLastRel(L,Rel);
        }
    }else{
        cout<<"Mohon maaf, Obat "<<medi<<" sudah terdaftar di "<<aptk<<"ingin mengganti ? Y/N"<<endl;
        if(yes == "Y" || yes == "y"){
            connect(L,P,C);
        }else if(yes == "N" || yes == "n"){
            cout<< "Terimakasih sudah menggunakan layanan kami, mohon maaf atas ketidaknyamanannya";
        }
    }
}

void disconnectmed(lire &L, adrapt P, admed C);
void disconnectapt(lire &L, adrapt P, admed C){
    /**Bagja 9102 Kurniawan (1301194020)*/
    adre R = first(L);
    while(R!=NIL){
        if(apt(next(R)) == P && ctn(next(R))== C){

        }
    }
}
int countMed(lire L);
int countApt(lire L){
    /**Bagja 9102 Kurniawan (1301194020)*/
}
void listMedfApt(lire L); /**obat tersedia di apotik ? */
void listAptfMed(lire L){
    /**Bagja 9102 Kurniawan (1301194020)*/
} /**apotik mentediakan obat ? */
bool isredundant(lire L, adrapt P, admed C);
