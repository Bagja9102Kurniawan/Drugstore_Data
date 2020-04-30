#include"medicine.h"

void createListMed(limed &L) {
    /**Manuel Benedict (1301194182)*/
    first(L) = NULL ;
}

void insertFirstMed(limed &L, admed P){
    /**Manuel Benedict (1301194182)*/
    if(obatKosong(L))
    {
        first(L) = P;
        next(P) = P;
        prev(P) = P;
    }
    else
    {
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(first(L))) = P;
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLastMed(limed &L, admed P){
    /**Manuel Benedict (1301194182)*/
    if(obatKosong(L))
    {
        first(L) = P;
        next(P) = P;
        prev(P) = P;
    }
    else
    {
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(first(L))) = P;
        prev(first(L)) = P;
    }
}

void insertAfterMed(admed Prec, admed P){
    /**Manuel Benedict (1301194182)*/
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    next(Prec) = P;
    prev(P) = Prec;
}

void deleteFirstMed(limed &L, admed &P){
    /**Manuel Benedict (1301194182)*/
    P = first(L);
    if (next(P) == first(L))
    {
        first(L) = NULL;
        next(P) = NULL;
        prev(P) = NULL;
    }
    else
    {
        first(L) = next(first(L));
        next(prev(P)) = first(L);
        prev(first(L)) = prev(P);
        next(P) = NULL;
        prev(P) = NULL;
    }
}

void deleteLastMed(limed &L, admed &P){
    /**Manuel Benedict (1301194182)*/
    P = first(L);
    if (next(P) == first(L))
    {
        next(P) = NULL;
        prev(P) = NULL;
        first(L) = NULL;
    }
    else
    {
        P = prev(first(L));
        next(prev(first(L))) = next(P);
        prev(first(L)) = prev(P);
    }
}

void deleteAfterMed(admed Prec, admed &P){
    /**Manuel Benedict (1301194182)*/
    P = next(Prec);
    if (next(next(Prec)) == Prec)
    {
        next(P) = NULL;
        prev(P) = NULL;
        next(Prec) = Prec;
        prev(Prec) = Prec;
    }
    else
    {
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
}

admed alokasiMed(obat x){
    /**Manuel Benedict (1301194182)*/
    admed P = new elmed;
    info(P).IDobat = x.IDobat;
    info(P).namaObat = x.namaObat;
    info(P).hargaObat = x.hargaObat;
    next(P) = NULL;
    prev(P) = NULL ;
    return P ;
}

void dealokasiMed(admed &P){
    /**Manuel Benedict (1301194182)*/
    delete P ;
}

admed findElmIDMed(limed L, int x){
    /**Manuel Benedict (1301194182)*/
    admed P = first(L);
    do
    {
        P = next(P);
    }
    while((P != first(L)) && (x != info(P).IDobat)) ;
    if (x != info(P).IDobat) {
        return NIL;
    }
    else
    {
        return P;
    }
}

admed findElmMed(limed L, string x){
    /**Bagja 9102 Kurniawan*/
    admed P = first(L);
    do
    {
        P = next(P);
    }
    while((P != first(L)) && (x != info(P).namaObat)) ;
    if (x != info(P).namaObat) {
        return NIL;
    }
    else
    {
        return P ;
    }
}

void printInfoMed(limed L){
    /**Manuel Benedict (1301194182)*/
    admed P = first(L);
    do
    {
        cout <<info(P).IDobat<<" "<<info(P).namaObat<<" "<<info(P).hargaObat<<endl;
        P = next(P);
    }
    while (P != first(L));
    cout<<endl;
}

int jumlahJenisObat(limed L){
    /**Manuel Benedict (1301194182)*/
    admed P;
    P = first(L);
    int i ;
    i = 1;
    do
    {
        P = next(P);
        if (info(P).IDobat != info(prev(P)).IDobat)
        {
            i++;
        }
    }
    while (next(P) != first(L));
    return i;
}

bool obatKosong(limed L){
    /**Manuel Benedict (1301194182)*/
    return (first(L) == NULL) ;
}
