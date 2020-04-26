#include "relation.h"

void createListRel(lire &L) {
    /**Bagja 9102 Kurniawan (1301194020)*/
    first(L) = NIL;
    last(L) = NIL;
}

bool isempty(lire L){
    /**Bagja 9102 Kurniawan (1301194020)*/
    return first(L) == NIL && last(L) == NIL;
}

adre alokasiRel(adrapt P, admed C) {
    /**Bagja 9102 Kurniawan (1301194020)*/
    adre R = new elmlire;
    apt(R) = P;
    ctn(R) = C;
    next(R) = NIL;
    return R;
}

void dealokasiRel(adre &P){
    /**Bagja 9102 Kurniawan (1301194020)*/
    delete P;
}

void insertFirstRel(lire &L, adre P) {
    /**Bagja 9102 Kurniawan (1301194020)*/
    if(isempty(L)){
        first(L) = P;
        last(L) = P;
    }
    else {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLastRel(lire &L, adre P) {
    /**Bagja 9102 Kurniawan (1301194020)*/
    if(isempty(L)){
        first(L) = P;
        last(L) = P;
    }
    else {
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertAfterRel(adre &Prec, adre P) {
    /**Bagja 9102 Kurniawan (1301194020)*/
    next(P) = next(Prec);
    next(Prec) = P;
}

void printInfoRel(lire L) {
    /**Bagja 9102 Kurniawan (1301194020)*/
    adre P = first(L);
    while(P !=NIL) {
        cout<<"->"<<apt(P)<<" MEMILIKI OBAT "<<ctn(P)<<endl;
        P = next(P);
    }
}

adre findElmRel(lire L,adrapt P, admed C) {
    /**Bagja 9102 Kurniawan (1301194020)*/
    adre R = first(L);
    while(R != NIL) {
        if(ctn(R)== C && apt(R) == P) {
            return R;
        }
        R = next(R);
    }
    return NIL;
}

void deleteFirstRel(lire &L, adre &P) {
    /**Bagja 9102 Kurniawan (1301194020)*/
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

void deleteLastRel(lire &L, adre &P) {
    /**Bagja 9102 Kurniawan (1301194020)*/
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

void deleteAfterRel(lire &L, adre prec, adre &P){
    /**Bagja 9102 Kurniawan (1301194020)*/
    if(isempty(L)){
        cout<< "LIST KOSONG"<< endl;
    }
    else if (next(prec) == NIL){
        cout<< "Tidak dapat mendelete"<< endl;
    }else if(next(prec)==last(L)){
        deleteLastRel(L,P);
    }
    else{
        if (next(prec) == last(L)){
            deleteLastRel(L,P);
        }
        else {
            P = next(prec);
            next(prec) = next(P);
            next(P) = NIL;
        }
    }
}

void deleterelasi(lire &L, adre &P){
    /**Bagja 9102 Kurniawan (1301194020)*/
    if(P!=NIL){
        if(P == first(L)){
            deleteFirstRel(L,P);
        }
        else if(P == last(L)){
            deleteLastRel(L,P);
        }
        else {
            adre Q = first(L);
            while(next(Q) != P){
                Q = next(Q);
            }
            deleteAfterRel(L,Q,P);
        }
    }
}
