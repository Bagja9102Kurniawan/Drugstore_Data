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
    admed ctn; //tunjuk ke child (medicine)
    adrapt apt; //tunjuk ke parent (drugstore)
    adre next;
};

/**LIST*/
struct lire {
    adre first;
    adre last;
};

/**Single Linear !!!!!!!*/

void createListRel(lire &L);

void insertFirstRel(lire &L, adre P);
void insertLastRel(lire &L, adre P);
void insertAfterRel(adre Prec, adre P);

void deleteFirstRel(lire &L, adre &P);
void deleteLastRel(lire &L, adre &P);
void deleteAfterRel(lire &L, adre Prec, adre &P);

adre alokasiRel(adrapt P, admed C);
void dealokasiRel(adre &P);
adre findElmRel(lire L,adrapt P, admed C);
void printInfoRel(lire L);

/**Case Functionality*/
int jumlahJenisObatSatuApotik(lire L);
void deleterelasi(lire &L, adre &P);
bool isempty(lire L);

#endif // RELATION_H_INCLUDED
