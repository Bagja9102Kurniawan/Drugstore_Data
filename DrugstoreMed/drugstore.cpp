#include "drugstore.h"

bool isEmptyApt(Listapt L){
    /**Bagja 9102 Kurniawan (1301194020)*/
    return (first(L) == NIL && last(L) == NIL);
}

void createListApt(Listapt &L){
    /**Bagja 9102 Kurniawan (1301194020)*/
    first(L) = NIL;
    last(L) = NIL;
}

adrapt alokasiApt(apotik x){
    /**Bagja 9102 Kurniawan (1301194020)*/
    adrapt P = new elmapt;
    info(P).IDapotik = x.IDapotik ;
    info(P).namaApotik = x.namaApotik ;
    info(P).noIzin = x.noIzin;
    next(P) = NIL;
    return P;
}

void dealokasiApt(adrapt &P){
    /**Bagja 9102 Kurniawan (1301194020)*/
    delete P;
}

void insertFirstApt(Listapt &L, adrapt P){
    /**Bagja 9102 Kurniawan (1301194020)*/
    if(isEmptyApt(L)){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}

void insertAfterApt(Listapt &L, adrapt Prec, adrapt P){
    /**Bagja 9102 Kurniawan (1301194020)*/
    if(isEmptyApt(L)){
        first(L) = P;
        last(L) = P;
    }else if(Prec == last(L)) {
        insertLastApt(L, P);
    }else{
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void insertLastApt(Listapt &L, adrapt P){
    /**Bagja 9102 Kurniawan (1301194020)*/
    if(isEmptyApt(L)){
        first(L) = P;
        last(L) = P;
    }else{
        next(last(L)) = P;
        last(L) = P;
    }
}

void deleteFirstApt(Listapt &L, adrapt &P){
    /**Bagja 9102 Kurniawan (1301194020)*/
    if(!isEmptyApt(L)){
        P = first(L);
        first(L) = next(P);
        next(P)=NIL;
    }else{
        cout<<"LIST KOSONG"<<endl;
    }
}

void deleteLastApt(Listapt &L, adrapt &P){
    /**Bagja 9102 Kurniawan (1301194020)*/
    if(isEmptyApt(L)){
        cout<<"LIST KOSONG"<<endl;
    }else if(next(first(L))==NIL){
        deleteFirstApt(L,P);
    }else{
        adrapt Q = first(L);
        while(next(Q)!= last(L)){
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = NIL;
        last(L) = Q;
    }
}

void deleteAfterApt(Listapt &L, adrapt Prec, adrapt &P){
    /**Bagja 9102 Kurniawan (1301194020)*/
    if(isEmptyApt(L)){
        cout<<"LIST KOSONG"<<endl;
    }else if(next(Prec)==last(L)){
        deleteLastApt(L,P);
    }
    else if (next(Prec) == NULL){
        cout<< "Tidak dapat mendelete"<< endl;
    }else{
        P = next(Prec);
        next(Prec) = next(P);
        next(P)=NIL;
    }
}


void printInfoApt(Listapt L){
    /**Bagja 9102 Kurniawan (1301194020)*/
    adrapt P = first(L);
    while(P != NIL)
    {
        cout<< info(P).IDapotik<<" "<< info(P).namaApotik<<" "<< info(P).noIzin<<endl;
        P = next(P);
    }
    cout<<endl;
}

adrapt findElmApt(Listapt L, string x){
    /**Bagja 9102 Kurniawan (1301194020)*/
    adrapt P = first(L);
    while(P!=NULL && info(P).namaApotik!= x){
        P = next(P);
    }
    return P;
}

adrapt findElmApt(Listapt L, int x){
    /**Bagja 9102 Kurniawan (1301194020)*/
    adrapt P = first(L);
    while(P!=NULL && info(P).IDapotik!= x){
        P = next(P);
    }
    return P;
}

int jumlahApotik(Listapt L){
    /**Bagja 9102 Kurniawan (1301194020)*/
    adrapt P = first(L);
    int qtnApt = 0;
    while(P != NIL){
        P = next(P);
        qtnApt -= -1;
    }
    return qtnApt;
}
