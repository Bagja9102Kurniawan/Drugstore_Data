#include "relation.h"

void createList(lire &L) {
    first(L) = NIL;
    last(L) = NIL;
}

bool isempty(lire L){
    return first(L) == NIL && last(L) == NIL;
}

adre alokasi(adrapt P, admed C) {
    adre R = new elmlire;
    apt(R) = P;
    ctn(R) = C;
    next(R) = NIL;
    return R;
}

void dealokasi(adre &P){
    delete P;
}

void insertFirst(lire &L, adre P) {
    if(isempty(L)){
        first(L) = P;
        last(L) = P;
    }
    else {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLast(lire &L, adre P) {
    if(isempty(L)){
        first(L) = P;
        last(L) = P;
    }
    else {
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertAfter(adre &Prec, adre P) {
    next(P) = next(Prec);
    next(Prec) = P;
}

void printInfo(lire L) {
    adre P = first(L);
    while(P !=NIL) {
        cout<<"->"<<apt(P)<<" MEMILIKI OBAT "<<ctn(P)<<endl;
        P = next(P);
    }
}

adre findElm(lire L,adrapt P, admed C) {
    adre R = first(L);
    while(R != NIL) {
        if(ctn(R)== C && apt(R) == P) {
            return R;
        }
        R = next(R);
    }
    return NIL;
}

void deleteFirst(lire &L, adre &P) {
    if(!isempty(L)){
        if(first(L) == last(L)){
            P = first(L);
            first(L) = NIL;
            last(L) = NIL;
        }
        else{
            P = first(L);
            first(L) = next(P);
            next(P) = NIL;
        }
    }

}

void deleteLast(lire &L, adre &P) {
    if(!isempty(L)){
        if(first(L) == last(L)){
            P = first(L);
            first(L) = NIL;
            last(L) = NIL;
        }
        else{
            adre Q;
            Q = first(L);
            while(next(Q) != last(L)){
                Q = next(Q);
            }
            P = last(L);
            last(L) = Q;
            next(Q) = NIL;
        }
    }
}

void deleteAfter(lire &L, adre prec, adre &P){
    if(isempty(L)){
        cout<< "LIST KOSONG"<< endl;
    }
    else if (next(prec) == NIL){
        cout<< "Tidak dapat mendelete"<< endl;
    }else if(next(prec)==last(L)){
        deleteLast(L,P);
    }
    else{
        if (next(prec) == last(L)){
            deleteLast(L,P);
        }
        else {
            P = next(prec);
            next(prec) = next(P);
            next(P) = NIL;
        }
    }
}

void deleterelasi(lire &L, adre &P){
    if(P!=NIL){
        if(P == first(L)){
            deleteFirst(L,P);
        }
        else if(P == last(L)){
            deleteLast(L,P);
        }
        else {
            adre Q = first(L);
            while(next(Q) != P){
                Q = next(Q);
            }
            deleteAfter(L,Q,P);
        }
    }
}
