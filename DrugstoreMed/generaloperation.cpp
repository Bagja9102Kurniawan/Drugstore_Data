#include "generaloperation.h"

/**void connect(lire L, adrapt P, admed C){
    string apt,medi;
    cout << "masukkan nama apotik : ";
    cin >> apt;
    P = findElm(L, apt);
    while(P == NIL){
        cout << "apotik tidak ditemukan, mohon coba lagi "<<endl<< "masukkan nama apotik : ";
        cin >> apt;
    }
    cout << "masukkan nama apotik : ";
    cin >> apt;
    C = findElm(L, medi);
}

void disconnectmed(lire &L, adrapt P, admed C){
    adre R = first(L);
    while(R!=NIL){
        if(apt(R) == P)
    }
}
void disconnectapt(lire &L, adrapt P, admed C){
    adre R = first(L);
    while(R!=NIL){
        if(apt(R) == P){

        }
    }
}
int countMed(lire L);
int countApt(lire L);
void listMedfApt(lire L); /**obat tersedia di apotik ? */
void listAptfMed(lire L); /**apotuk mentediakan obat ? */
bool isredundant(lire L);
