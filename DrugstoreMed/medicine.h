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

void createList(limed &L);
void insertFirst(limed &L, admed P);
void insertLast(limed &L, admed P);
void insertAfter(admed Prec, admed P);
void deleteFirst(limed &L, admed &P);
void deleteLast(limed &L, admed &P);
void deleteAfter(admed Prec, admed &P);
admed alokasi(obat x);
void dealokasi(admed &P);
admed findElm(limed L, obat x);
void printInfo(limed L);

/**Case Functionality*/
int jumlahJenisObat(limed L);
bool obatKosong(limed L);

#endif // MEDICINE_H_INCLUDED
