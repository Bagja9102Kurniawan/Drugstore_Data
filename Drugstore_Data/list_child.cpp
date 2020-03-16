#include "List_child.h"

void createList_child(List_child &L)
{
    /**
    * FS : set first(L) with Null
    */
    first(L) = NULL;
}

address_child allocate(infotype_child x)
{
    /**
    * FS : return new List_child element with info = x and next element is Null
    */
    address_child P = NULL;
    P = new elmlist_child;
    obat(P).IDobat = x.IDobat;
    obat(P).namaObat = x.namaObat;
    obat(P).jumObat = x.jumObat;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void deallocate(address_child &P)
{
    /**
    * FS : delete element pointed by P
    */
    delete P;
}

void insertFirst(List_child &L, address_child P)
{
    /**
    * IS : List_child L may be empty
    * FS : element pointed by P became the first element in List_child L
    */
    if(obatKosong(L))
    {
        first(L) = P;
        next(P) = P;
        prev(P) = P;
    }
    else
    {
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(first(L))) = P;
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List_child &L, address_child P)
{
    /**
    * IS : List_child L may be empty
    * FS : element pointed by P became the last element in List_child L
    */
    if (first(L) == NULL)
    {
        insertFirst(L,P);
    }
    else
    {
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(first(L))) = P;
        prev(first(L)) = P;
    }
}

address_child findElm(List_child L, infotype_child x)
{
    /**
        * IS : List_child L may be empty
        * FS : returns element with info.ID = x.ID,
               return Null if such ID is not found
        */
    address_child P;
    P = first(L);
    do
    {
        P = next(P);
    }
    while((next(P) != first(L)) && (x.IDobat != obat(P).IDobat));
    return P;
}

void deleteFirst(List_child &L, address_child &P)
{
    /**
    * IS : List_child L may be empty
    * FS : first element in List_child L is removed and is pointed by P
    */
    P = first(L);
    if (next(P) == first(L))
    {
        first(L) = NULL;
        next(P) = NULL;
        prev(P) = NULL;
    }
    else
    {
        first(L) = next(first(L));
        next(prev(P)) = first(L);
        prev(first(L)) = prev(P);
        next(P) = NULL;
        prev(P) = NULL;
    }
}

void deleteLast(List_child &L, address_child &P)
{
    /**
    * IS : List_child L may be empty
    * FS : last element in List_child L is removed and is pointed by P
    */
    P = first(L);
    if (next(P) == first(L))
    {
        next(P) = NULL;
        prev(P) = NULL;
        first(L) = NULL;
    }
    else
    {
        P = prev(first(L));
        next(prev(first(L))) = next(P);
        prev(first(L)) = prev(P);
    }
}

void printInfo(List_child L)
{
    /**
    * FS : view info of all element inside List_child L,
    *      call the view_data function from my_data.h to print the info
    */
    address_child P = first(L);
    cout << "My output : ";
    do
    {
        cout <<obat(P).IDobat<<" "<<obat(P).namaObat<<" "<<obat(P).jumObat<<endl;
        P = next(P);
    }
    while (next(P) != NULL);
    cout<<endl;
}

void insertAfter(List_child &L, address_child Prec, address_child P)
{
    /**
    * IS : Prec and P is not NULL
    * FS : element pointed by P is placed behind the element
    *      pointed by pointer Prec
    */
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    next(Prec) = P;
    prev(P) = Prec;
}

void deleteAfter(List_child &L, address_child Prec, address_child &P)
{
    /**
    * IS : Prec is not NULL
    * FS : element which was before behind an element pointed by Prec
    *      is removed and pointed by pointer P
    */
    P = next(Prec);
    if (next(next(Prec)) == Prec)
    {
        next(P) = NULL;
        prev(P) = NULL;
        next(Prec) = Prec;
        prev(Prec) = Prec;
    }
    else
    {
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
}

int jumlahJenisObat(List_child L)
{
    address_child P;
    P = first(L);
    int i ;
    i = 1;
    do
    {
        P = next(P);
        if (obat(P).IDobat != obat(prev(P)).IDobat)
        {
            i++;
        }
    }
    while (next(P) != NULL);
    return i;
}
