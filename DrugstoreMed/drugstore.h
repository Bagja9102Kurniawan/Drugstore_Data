#ifndef DRUGSTORE_H_INCLUDED
#define DRUGSTORE_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define last(L) L.last
#define first(L) L.first
#define NIL NULL

/**INFOTYPE*/

struct apotik {
    int IDapotik;
    string namaApotik;
    long noIzin;
};

/**TYPEDEF*/
typedef struct elmapt *adrapt;

/**ELMLIST*/
struct elmapt {
    /**SLLL*/
    apotik info;
    adrapt next;
};

/**LIST*/
struct Listapt {
    adrapt first;
    adrapt last;
};

/**Single Linear !!!!!!!*/

void insertFirst(Listapt &L, adrapt P);
void insertAfter(Listapt &L, adrapt Prec, adrapt P);
void insertLast(Listapt &L, adrapt P);

void deleteFirst(Listapt &L, adrapt &P);
void deleteLast(Listapt &L, adrapt &P);
void deleteAfter(Listapt &L, adrapt Prec, adrapt &P);

void dealokasi(adrapt &P);
void createList(Listapt &L);
adrapt alokasi(apotik x);
adrapt findElm(Listapt L, string x);
adrapt findElmID(Listapt L, int x);
void printInfo(Listapt L);

/**Case Functionality*/
int jumlahApotik(Listapt L);
bool isEmpty(Listapt L);

#endif // DRUGSTORE_H_INCLUDED
