#include"medicine.h"

void createList(limed &L) {
    first(L) = NULL ;
}

void insertFirst(limed &L, admed P){
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

void insertLast(limed &L, admed P){
    if (first(L) == NULL)
    {
        insertFirst(L,P);
    }
    else
    {
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(first(L))) = P;
        prev(first(L)) = P;
    }
}

void insertAfter(admed Prec, admed P){
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    next(Prec) = P;
    prev(P) = Prec;
}

void deleteFirst(limed &L, admed &P){
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

void deleteLast(limed &L, admed &P){
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

void deleteAfter(admed Prec, admed &P){
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

admed alokasi(obat x){
    admed P = new elmed;
    info(P).IDobat = x.IDobat;
    info(P).namaObat = x.namaObat;
    info(P).hargaObat = x.hargaObat;
    next(P) = NULL;
    prev(P) = NULL ;
    return P ;
}

void dealokasi(admed &P){
    delete P ;
}

admed findElmIDMed(limed L, obat x){
    admed P;
    P = first(L);
    do
    {
        P = next(P);
    }
    while((P != first(L)) && (x.IDobat != info(P).IDobat));
    if((P == first(L)) && (x.IDobat != info(P).IDobat)){
        return NIL;
    }else{
        return P;
    }
}

admed findElmMed(limed L, string x){
    admed P;
    P = first(L);
    do
    {
        P = next(P);
    }
    while((P != first(L)) && (x != info(P).namaObat));
    if((P == first(L)) && (x != info(P).namaObat)){
        return NIL;
    }else{
        return P;
    }
}

void printInfo(limed L){
    admed P = first(L);
    do
    {
        cout <<info(P).IDobat<<" "<<info(P).namaObat<<" "<<info(P).hargaObat<<endl;
        P = next(P);
    }
    while (next(P) != NULL);
    cout<<endl;
}

int jumlahJenisObat(limed L){
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
    while (next(P) != NULL);
    return i;
}

bool obatKosong(limed L){
    return (first(L) == NULL) ;
}
