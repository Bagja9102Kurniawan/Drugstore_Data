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

void insertFirstApt(Listapt &L, adrapt P);
void insertAfterApt(Listapt &L, adrapt Prec, adrapt P);
void insertLastApt(Listapt &L, adrapt P);

void deleteFirstApt(Listapt &L, adrapt &P);
void deleteLastApt(Listapt &L, adrapt &P);
void deleteAfterApt(Listapt &L, adrapt Prec, adrapt &P);

void dealokasiApt(adrapt &P);
void createListApt(Listapt &L);
adrapt alokasiApt(apotik x);
adrapt findElmApt(Listapt L, string x);
adrapt findElmIDApt(Listapt L, int x);
void printInfoApt(Listapt L);

/**Case Functionality*/
int jumlahApotik(Listapt L);
bool isEmptyApt(Listapt L);

#endif // DRUGSTORE_H_INCLUDED
