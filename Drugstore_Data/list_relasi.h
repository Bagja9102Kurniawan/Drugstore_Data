#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED

#include "general.h"

/**Single Linear !!!!!!!*/

void createList(List_relasi &L);
void insertFirst(List_relasi &L, address_relasi P);
void insertLast(List_relasi &L, address_relasi P);
void insertAfter(address_relasi Prec, address_relasi P);
void deleteFirst(List_relasi &L, address_relasi &P);
void deleteLast(List_relasi &L, address_relasi &P);
void deleteAfter(address_relasi Prec, address_relasi &P);
address_relasi alokasi(address_child C);
void dealokasi(address_relasi &P);
address_relasi findElm(List_relasi L, address_child C);
void printInfo(List_relasi L);

/**Case Functionality*/
int jumlahJenisObatSatuApotik(List_relasi L);
void deleterelasi(List_relasi &L, address_relasi &P);

#endif // LIST_RELASI_H_INCLUDED
