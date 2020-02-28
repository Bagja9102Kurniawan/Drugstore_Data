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
    next(P) = P;
    prev(P) = P;
    return P;
}

void insertFirst(List_parent &L, address_parent P){
    if(isEmpty(L)){
        First(L) = P;
    }else{
        next(P) = First(L);
        prev(P) = prev(First(L));
        next(prev(First(L))) = P;
        prev(First(L)) = P;
        First(L) = P;
    }
}
void insertAfter(address_parent Prec, address_parent P){
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
    prev(next(P)) = P;
}
void deleteFirst(List_parent &L, address_parent &P){
    P = First(L);
    First(L) = next(P);
    next(prev(P)) = First(L);
    prev(First(L)) = prev(P);
    prev(P) = NIL;
    next(P) = NIL;
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
