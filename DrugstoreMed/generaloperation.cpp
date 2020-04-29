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

void disconnectmed(lire &L, adrapt P, admed C)
{
    /** Manuel Benedict (1301194182) */
    adre R = first(L);
    while(R!=NIL){
        if(apt(R) == P)
        {
            apt(R) = NULL ;
            ctn(R) = NULL ;
            dealokasiRel(R) ;
        }
    }
}
void disconnectapt(lire &L, adrapt P, admed C){
    /**Bagja 9102 Kurniawan (1301194020)*/
    adre Q;
    adre R = first(L);
    while(R!=NIL){
        if(next(apt(R)) == P && next(ctn(R)) == C){
            apt(next(R)) = NIL;
            ctn(next(R)) = NIL;
            deleteAfterRel(L,R,Q);
            dealokasiRel(Q);
        }
        R = next(R);
    }
}
int countMed(lire L)
{
    /** Manuel Benedict (1301194182) */
    adre P ;
    adrapt Q,apt ;
    int i ;
    P = first(L) ;
    while (next(P) != NULL)
    {
        if (apt(P) != Q)
        {
            i++ ;
        }
    }
    return i ;
}

int countApt(lire L)
{
    /**Bagja 9102 Kurniawan (1301194020)*/
    adrapt P = first(L);
    int counter = 0;
    while(P!=NIL){
        P = next(P);
        counter -= -1;
    }
    return counter;
}

void listMedfApt(lire L) /**obat tersedia di apotik ? */
{
    /** Manuel Benedict (1301194182) */
    adre P ;
    adrapt Q,apt ;
    admed ctn ;
    int i ;
    P = first(L) ;
    while (next(P) != NULL)
    {
        if (apt(P) != Q)
        {
            cout << "Obat yang tersedia di apotik ini: " << endl ;
            cout << i << ". " << info(ctn(P)).IDobat << " " << info(ctn(P)).namaObat << " " << info(ctn(P)).hargaObat << endl ;
            i++ ;
        }
        P = next(P) ;
    }
}

void listAptfMed(lire L,admed A) /**apotik menyediakan obat ? */
{
    /**Bagja 9102 Kurniawan (1301194020)*/
    adre P = first(L);
    cout << "Obat "<< info(A).namaObat<< " tersedia di apotik : ";
    while(P!= NIL){
        if(apt(P) == A){
            cout<<apt(P).namaApotik<<", ";
        }
        P = next(P);
    }

}

bool isredundant(lire L, adrapt P, admed C)
{
    /** Manuel Benedict (1301194182) */

}
