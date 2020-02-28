#include "List_child.h"

void createList_child(List_child &L) {
    /**
    * FS : set first(L) with Null
    */

    first(L) = NULL;

}

address_child allocate(infotype_child x) {
    /**
    * FS : return new List_child element with info = x and next element is Null
    */

    address_child P = NULL;

    P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;

    return P;
}

void deallocate(address_child &P) {
    /**
    * FS : delete element pointed by P
    */

    delete P;

}

void insertFirst(List_child &L, address_child P) {
    /**
    * IS : List_child L may be empty
    * FS : element pointed by P became the first element in List_child L
    */

    next(P) = first(L);
    first(L) = P;

}

void insertLast(List_child &L, address_child P) {
    /**
    * IS : List_child L may be empty
    * FS : element pointed by P became the last element in List_child L
    */

    address_child Q = first(L);
    while(next(Q) != NULL){
        Q = next(Q);
    }
    next(Q) = P;

}

address_child findElm(List_child L, infotype_child x) {
/**
    * IS : List_child L may be empty
    * FS : returns element with info.ID = x.ID,
           return Null if such ID is not found
    */

    address_child P;

    P = first(L);
    while((P != NULL) && (x != info(P))) {
        P = next(P);
    }
    return P;
}

void deleteFirst(List_child &L, address_child &P) {
    /**
    * IS : List_child L may be empty
    * FS : first element in List_child L is removed and is pointed by P
    */

    if (first(L) != NULL)
    {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }

}

void deleteLast(List_child &L, address_child &P) {
    /**
    * IS : List_child L may be empty
    * FS : last element in List_child L is removed and is pointed by P
    */

    address_child Q = first(L);
    if (next(Q)==NULL){
        first(L)=NULL;
    } else {
        while(next(next(Q)) != NULL){
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = NULL;
    }

}

void printInfo(List_child L) {
    /**
    * FS : view info of all element inside List_child L,
    *      call the view_data function from my_data.h to print the info
    */

    address_child P = first(L);
    cout << "My output : ";
    while (P != NULL)
    {
        cout << info(P)<<", ";
        P = next(P);
    }

    cout<<endl;
}


void insertAfter(List_child &L, address_child Prec, address_child P) {
    /**
    * IS : Prec and P is not NULL
    * FS : element pointed by P is placed behind the element
    *      pointed by pointer Prec
    */

    next(P) = next(Prec);
    next(Prec) = P;


}
void deleteAfter(List_child &L, address_child Prec, address_child &P) {
    /**
    * IS : Prec is not NULL
    * FS : element which was before behind an element pointed by Prec
    *      is removed and pointed by pointer P
    */

    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;

}
