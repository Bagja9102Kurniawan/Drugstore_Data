#include "List_parent.h"

bool isEmpty(List_parent L)
{
    return (First(L)==NIL) ;
}

void createList_parent(List_parent &L)
{
    First(L) = NIL;
}

address_parent alokasi(infotype_parent x)
{
    address_parent P = new elmList_parent;
    info(P) = x ;
    next(P) = NULL;
    child(P) = NULL;
    return P;
}

void dealokasi(address_parent &P){
    delete P;
}

void insertFirst(List_parent &L, address_parent P){
    if(isEmpty(L)){
        First(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}

void insertAfter(List_parent &L, address_parent Prec, address_parent P){
    if(isEmpty(L)){
        First(L) = P;
    }else if(Prec = last(L)) {
        insertLast(L, P);
    }else{
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void insertLast(List_parent &L, address_parent P){
    if(isEmpty(L)){
        First(L) = P;
    }else{
        next(last(L)) = P;
        last(L) = P;
    }
}

void deleteFirst(List_parent &L, address_parent &P){
        if(!isempty(L)){
            if(first(L) == last(L)){
                deleterelasi(L,P);
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
void deleteAfter(address_parent Prec, address_parent &P){
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    next(P)=NIL;
    prev(P)=NIL;
}

void printInfo(List_parent L){
    address_parent P = First(L);
    while(P != First(L)){
        cout<<info(P)<<", ";
        P = next(P);
    };
    cout<<endl;
}

address_parent findElm(List_parent L, infotype_parent x){
    address_parent P = first(L);
    while(P!=NULL && info(P)!= x){
        P = next(P);
    }
    return P;
}
