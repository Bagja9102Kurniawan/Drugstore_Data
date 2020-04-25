#include "coba.h"

void createList(List_child &L)
{
    first(L) = NULL;
}

void insertFirst(List_child &L, address_child P)
{
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

void insertAfter(address_child Prec, address_child P)
{
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    next(Prec) = P;
    prev(P) = Prec;
}

void deleteFirst(List_child &L, address_child &P)
{
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

void deleteAfter(address_child Prec, address_child &P)
{
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

address_child alokasi(infotype_child x)
{
    address_child P = NULL;
    P = new elmlist_child;
    info(P).IDobat = x.IDobat;
    info(P).namaObat = x.namaObat;
    info(P).hargaObat = x.hargaObat;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void dealokasi(address_child &P)
{
    delete P ;
}

address_child findElm(List_child L, infotype_child x)
{
    address_child P;
    P = first(L);
    do
    {
        P = next(P);
    }
    while((next(P) != first(L)) && (x.IDobat != info(P).IDobat));
    return P;
}

void printInfo(List_child L)
{
    address_child P = first(L);
    cout << "My output : ";
    do
    {
        cout <<info(P).IDobat<<" "<<info(P).namaObat<<" "<<info(P).hargaObat<<endl;
        P = next(P);
    }
    while (next(P) != NULL);
    cout<<endl;
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
        if (info(P).IDobat != info(prev(P)).IDobat)
        {
            i++;
        }
    }
    while (next(P) != NULL);
    return i;
}

bool obatKosong(List_child L)
{
    return (first(L) = NULL) ;
}
