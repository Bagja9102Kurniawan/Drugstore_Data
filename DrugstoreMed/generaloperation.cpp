#include "generaloperation.h"

void connect(lire L, adrapt P, admed C){
    /**Bagja 9102 Kurniawan (1301194020)*/
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
    adre R = first(L);
    while(R!=NIL){
        if(apt(R) == P){

        }
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

void listAptfMed(lire L) /**apotuk mentediakan obat ? */
{
    /**Bagja 9102 Kurniawan (1301194020)*/

}

bool isredundant(lire L, adrapt P, admed C)
{
    /** Manuel Benedict (1301194182) */

}
