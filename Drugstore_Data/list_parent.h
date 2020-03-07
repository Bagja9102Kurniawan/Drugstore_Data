#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED

#include "general.h"

/**Single Linear !!!!!!!*/

void createList(List_parent &L);
address_parent alokasi(infotype_parent x);
void insertFirst(List_parent &L, address_parent P);
void insertAfter(List_parent &L, address_parent Prec, address_parent P);
void insertLast(List_parent &L, address_parent P);
void deleteFirst(List_parent &L, address_parent &P);
void deleteLast(List_parent &L, address_parent &P);
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P);
void dealokasi(address_parent &P);
address_parent findElm(List_parent L, infotype_parent x);
void printInfo(List_parent L);

/**Case Functionality*/
int jumlahApotik(List_parent L);
bool isEmpty(List_parent L);

#endif // LIST_PARENT_H_INCLUDED
