#include "list_relasi.h"

void createList(List_relasi &L) {
    first(L) = NULL;
    last(L) = NULL;
}

bool isempty(List_relasi L){
    return first(L) == NULL && last(L) == NULL;
}

address_relasi alokasi(address_parent P, address_child C) {
    R = new elmlist_relasi;
    apt(P) = P;
    ctn(P) = C;
    next(P) = NIL;
    return R;
}

void dealokasi(address_child &P){
    delete P;
}

void insertFirst(List_relasi &L, address_relasi P) {
    if(isempty(L)){
        first(L) = P;
        last(L) = P;
    }
    else {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLast(List_relasi &L, address_relasi P) {
    if(isempty(L)){
        first(L) = P;
        last(L) = P;
    }
    else {
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertAfter(address_relasi &Prec, address_relasi P) {
    next(P) = next(Prec);
    next(Prec) = P;
}

void printInfo(List_relasi L) {
    address_relasi P = first(L);
    while(P !=NULL) {
        cout<<"->"<<apt(P)<<" MEMILIKI OBAT "<<ctn(P)<<endl;
        P = next(P);
    }
}

address_relasi findElm(List_relasi L,address_parent P, address_child C) {
    address_relasi R = first(L);
    while(R != NULL) {
        if(ctn(R)== C && apt(R) == P) {
            return R;
        }
        R = next(R);
    }
    return NULL;
}

void deleteFirst(List_relasi &L, address_relasi &P) {
    if(!isempty(L)){
        if(first(L) == last(L)){
            P = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }
        else{
            P = first(L);
            first(L) = next(P);
            next(P) = NULL;
        }
    }

}

void deleteLast(List_relasi &L, address_relasi &P) {
    if(!isempty(L)){
        if(first(L) == last(L)){
            P = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }
        else{
            address_relasi Q;
            Q = first(L);
            while(next(Q) != last(L)){
                Q = next(Q);
            }
            P = last(L);
            last(L) = Q;
            next(Q) = NULL;
        }
    }
}

void deleteAfter(List_relasi &L, address_relasi prec, address_relasi &P){
    if(isempty(L)){
        cout<< "LIST KOSONG"<< endl;
    }
    else if (next(prec) == NULL){
        cout<< "Tidak dapat mendelete"<< endl;
    }else if(next(Prec)==last(L)){
        deleteLast(L,P);
    }
    else{
        if (next(prec) == last(L)){
            deleteLast(L,P);
        }
        else {
            P = next(prec);
            next(prec) = next(P);
            next(P) = NULL;
        }
    }
}

void deleterelasi(List_relasi &L, address_relasi &P){
    if(P!=NULL){
        if(P == first(L)){
            deleteFirst(L,P);
        }
        else if(P == last(L)){
            deleteLast(L,P);
        }
        else {
            adr_relasi Q;
            Q = first(L);
            while(next(Q) != P){
                Q = next(Q);
            }
            deleteAfter(L,Q,P);
        }
    }
}
