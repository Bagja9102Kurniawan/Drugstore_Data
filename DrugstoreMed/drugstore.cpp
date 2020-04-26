#include "drugstore.h"

bool isEmpty(Listapt L){
    return (first(L) == NULL && last(L) == NULL);
}

void createList(Listapt &L){
    first(L) = NIL;
    last(L) = NIL;
}

adrapt alokasi(apotik x){
    adrapt P = new elmapt;
    info(P).IDapotik = x.IDapotik ;
    info(P).namaApotik = x.namaApotik ;
    info(P).noIzin = x.noIzin;
    next(P) = NIL;
    return P;
}

void dealokasi(adrapt &P){
    delete P;
}

void insertFirst(Listapt &L, adrapt P){
    if(isEmpty(L)){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}

void insertAfter(Listapt &L, adrapt Prec, adrapt P){
    if(isEmpty(L)){
        first(L) = P;
        last(L) = P;
    }else if(Prec == last(L)) {
        insertLast(L, P);
    }else{
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void insertLast(Listapt &L, adrapt P){
    if(isEmpty(L)){
        first(L) = P;
        last(L) = P;
    }else{
        next(last(L)) = P;
        last(L) = P;
    }
}

void deleteFirst(Listapt &L, adrapt &P){
    if(!isEmpty(L)){
        P = first(L);
        first(L) = next(P);
        next(P)=NIL;
    }else{
        cout<<"LIST KOSONG"<<endl;
    }
}

void deleteLast(Listapt &L, adrapt &P){
    if(isEmpty(L)){
        cout<<"LIST KOSONG"<<endl;
    }else if(next(first(L))==NIL){
        deleteFirst(L,P);
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

void deleteAfter(Listapt &L, adrapt Prec, adrapt &P){
    if(isEmpty(L)){
        cout<<"LIST KOSONG"<<endl;
    }else if(next(Prec)==last(L)){
        deleteLast(L,P);
    }
    else if (next(Prec) == NULL){
        cout<< "Tidak dapat mendelete"<< endl;
    }else{
        P = next(Prec);
        next(Prec) = next(P);
        next(P)=NIL;
    }
}


void printInfo(Listapt L){
    adrapt P = first(L);
    while(P != NIL)
    {
        cout<< info(P).IDapotik<<" "<< info(P).namaApotik<<" "<< info(P).noIzin<<endl;
        P = next(P);
    }
    cout<<endl;
}

adrapt findElm(Listapt L, string x){
    adrapt P = first(L);
    while(P!=NULL && info(P).namaApotik!= x){
        P = next(P);
    }
    return P;
}

adrapt findElm(Listapt L, int x){
    adrapt P = first(L);
    while(P!=NULL && info(P).IDapotik!= x){
        P = next(P);
    }
    return P;
}

int jumlahApotik(Listapt L){
    adrapt P = first(L);
    int qtnApt = 0;
    while(P != NIL){
        P = next(P);
        qtnApt -= -1;
    }
    return qtnApt;
}
