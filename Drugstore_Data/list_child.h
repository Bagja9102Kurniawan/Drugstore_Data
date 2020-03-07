#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED

#include "general.h"

/**Double Circular !!!!!!!!!*/

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

#endif // LIST_CHILD_H_INCLUDED
