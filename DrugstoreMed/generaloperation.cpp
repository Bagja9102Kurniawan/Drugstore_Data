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

void disconnectmed(lire &L, admed C)
{
    /** Manuel Benedict (1301194182) */
    adre Q ;
    adre R = first(L);
    while(R!=NIL){
        if (ctn(R) == C)
        {
            deleteAfterRel(L,R,Q) ;
            apt(Q) = NULL ;
            ctn(Q) = NULL ;
            dealokasiRel(Q) ;
        }
        R = next(R) ;
    }
}

void disconnectapt(lire &L, adrapt P){
    /**Bagja 9102 Kurniawan (1301194020)*/
    adre Q;
    adre R = first(L);
    while(R!=NIL){
        if(next(apt(R)) == P){
            deleteAfterRel(L,R,Q);
            apt(Q) = NIL;
            ctn(Q) = NIL;
            dealokasiRel(Q);
        }
        R = next(R);
    }
}
int countMed(lire L, adrapt Q)
{
    /** Manuel Benedict (1301194182) */
    adre P = first(L);
    int i = 0 ;
    while (next(P) != NULL)
    {
        if (apt(P) != Q)
        {
            i++ ;
        }
    }
    return i ;
}

int countApt(lire L, admed M)
{
    /**Bagja 9102 Kurniawan (1301194020)*/
    adre P = first(L);
    int counter = 0;
    while(P!=NIL){
        if(ctn(P) == M){
            counter -= -1;
        }
        P = next(P);
    }
    return counter;
}

void listMedfApt(lire L, admed A)
{
    /** Manuel Benedict (1301194182) */
    adre P = first(L);
    cout << "Obat "<< info(A).namaObat<< " tersedia di apotik : ";
    while(P!= NIL){
        if(ctn(P) == A){
            cout<<info(apt(P)).namaApotik<<", ";
        }
        P = next(P);
    }
}

void listAptfMed(lire L,adrapt A)
{
    /**Bagja 9102 Kurniawan (1301194020)*/
    adre P = first(L);
    cout << "Obat-obatan yang tersedia di apotik "<<info(A).namaApotik <<" : ";
    while(P!= NIL){
        if(apt(P) == A){
            cout<<info(ctn(P)).namaObat<<", ";
        }
        P = next(P);
    }
}

bool isredundant(lire L, adrapt P, admed C)
{
    /** Manuel Benedict (1301194182) */

}
