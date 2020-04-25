#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED

#include <iostream>
#include "drugstore.h"
#include "medicine.h"
using namespace std;

#define next(P) P->next
#define apt(P) P->apt
#define ctn(P) P->ctn
#define last(L) L.last
#define first(L) L.first
#define NIL NULL

/**TYPEDEF*/
typedef struct elmlire *adre;

/**ELMLIST*/
struct elmlire {
    /**SLLL*/
    admed ctn;
    adrapt apt;
    adre next;
};

/**LIST*/
struct lire {
    adre first;
    adre last;
};

/**Single Linear !!!!!!!*/

void createList(lire &L);

void insertFirst(lire &L, adre P);
void insertLast(lire &L, adre P);
void insertAfter(adre Prec, adre P);

void deleteFirst(lire &L, adre &P);
void deleteLast(lire &L, adre &P);
void deleteAfter(adre Prec, adre &P);

adre alokasi(adrapt P, admed C);
void dealokasi(adre &P);
adre findElm(lire L,adrapt P, admed C);
void printInfo(lire L);

/**Case Functionality*/
int jumlahJenisObatSatuApotik(lire L);
void deleterelasi(lire &L, adre &P);

#endif // RELATION_H_INCLUDED
