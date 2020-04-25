#include "List_parent.h"

bool isEmpty(List_parent L)
{
    return (first(L)==NIL);
}

void createList_parent(List_parent &L)
{
    first(L) = NIL;
    last(L) = NIL;
}

address_parent alokasi(apotik x)
{
    address_parent P = new elmList_parent;
    info(P) = x ;
    next(P) = NIL;
    return P;
}

void dealokasi(address_parent &P){
    delete P;
}

void insertFirst(List_parent &L, address_parent P){
    if(isEmpty(L)){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}

void insertAfter(List_parent &L, address_parent Prec, address_parent P){
    if(isEmpty(L)){
        first(L) = P;
        last(L) = P;
    }else if(Prec = last(L)) {
        insertLast(L, P);
    }else{
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void insertLast(List_parent &L, address_parent P){
    if(isEmpty(L)){
        first(L) = P;
        last(L) = P;
    }else{
        next(last(L)) = P;
        last(L) = P;
    }
}

void deleteFirst(List_parent &L, address_parent &P){
    if(!isEmpty(L)){
        P = first(L);
        first(L) = next(P);
        next(P)=NIL;
    }else{
        cout<<"LIST KOSONG"<<endl;
    }
}

void deleteLast(List_parent &L, address_parent &P){
    if(isEmpty(L)){
        cout<<"LIST KOSONG"<<endl;
    }else if(next(first(L))==NIL){
        deleteFirst(L,P);
    }else{
        address_relasi Q = first(L);
        while(next(next(Q))!= NIL){
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = NIL;
        last(L) = Q;
    }
}

void deleteAfter(List_parent &L, address_parent Prec, address_parent &P){
    if(isEmpty(L)){
        cout<<"LIST KOSONG"<<endl;
    }else if(next(Prec)==last(L)){
        deleteLast(L,P);
    }else{
        P = next(Prec);
        next(Prec) = next(P);
        next(P)=NIL;
    }
}

void printInfo(List_parent L){
    address_parent P = first(L);
    while(P != NIL){
        cout<<info(P)<<", ";
        P = next(P);
    };
    cout<<endl;
}

address_parent findElm(List_parent L, apotik x){
    address_parent P = first(L);
    while(P!=NULL && info(P)!= x){
        P = next(P);
    }
    return P;
}

int jumlahApotik(List_parent L){
    address_relasi P = first(L);
    int qtnApt = 0;
    while(P != NIL){
        P = next(P);
        qtnApt -= -1;
    }
    return qtnApt;
}
