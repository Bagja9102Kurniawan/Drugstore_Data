#ifndef MEDICINE_H_INCLUDED
#define MEDICINE_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define first(L) L.first
#define NIL NULL

/**INFOTYPE*/
struct obat{
    int IDobat;
    string namaObat;
    int hargaObat;
};

/**TYPEDEF*/
typedef struct elmed *admed;

/**ELMLIST*/
struct elmed {
    /**DLLC*/
    obat info;
    admed next;
    admed prev;
};

/**LIST*/
struct limed {
    admed first;
};

/**Double Circular !!!!!!!*/

void createListMed(limed &L);
void insertFirstMed(limed &L, admed P);
void insertLastMed(limed &L, admed P);
void insertAfterMed(admed Prec, admed P);
void deleteFirstMed(limed &L, admed &P);
void deleteLastMed(limed &L, admed &P);
void deleteAfterMed(admed Prec, admed &P);
admed alokasiMed(obat x);
void dealokasiMed(admed &P);
admed findElmMed(limed L, string x);
admed findElmIDMed(limed L, int x);
void printInfoMed(limed L);

/**Case Functionality*/
int jumlahJenisObat(limed L);
bool obatKosong(limed L);

#endif // MEDICINE_H_INCLUDED
