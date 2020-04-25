#ifndef COBA_H_INCLUDED
#define COBA_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define first(L) L.first

typedef struct elmlist_child *address_child;

struct obat{
    int IDobat;
    string namaObat;
    int hargaObat;
};

typedef obat infotype_child ;

struct elmlist_child {
    /**DLLC*/
    infotype_child info;
    address_child next;
    address_child prev;
};

struct List_child {
    address_child first;
};

void createList(List_child &L);
void insertFirst(List_child &L, address_child P);
void insertLast(List_child &L, address_child P);
void insertAfter(address_child Prec, address_child P);
void deleteFirst(List_child &L, address_child &P);
void deleteLast(List_child &L, address_child &P);
void deleteAfter(address_child Prec, address_child &P);
address_child alokasi(infotype_child x);
void dealokasi(address_child &P);
address_child findElm(List_child L, infotype_child x);
void printInfo(List_child L);

/**Case Functionality*/
int jumlahJenisObat(List_child L);
bool obatKosong(List_child L);

#endif // COBA_H_INCLUDED
