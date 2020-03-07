#include "List_parent.h"

bool isEmpty(List_parent L)
{
    return (First(L)==NIL) ;
}

void createList_parent(List_parent &L)
{
    First(L) = NIL;
}

address_parent createNewElmt(infotype_parent x)
{
    address_parent P = new elmList_parent;
    info(P) = x ;
    next(P) = NULL;
    child(P) = NULL;
    return P;
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
int countWord(char data[], List_parent L){
    address_parent P = First(L);
    int n = 0;
    do {
        int i = 0;
        address_parent Q = P;
        while(data[i] != NIL){
            if(data[i] == info(Q)){
                Q = next(Q);
                i++;
            } else {
                break;
            }
            if(data[i] == NIL){
                n++;
            }
        }
        P = next(P);
    } while(P != First(L));
    return n;
}
void printInfo(List_parent L){
    address_parent P = First(L);
    do {
        cout<<info(P)<<", ";
        P = next(P);
    } while(P != First(L));
    cout<<endl;
}
