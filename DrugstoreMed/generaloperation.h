#ifndef GENERALOPERATION_H_INCLUDED
#define GENERALOPERATION_H_INCLUDED
#include "medicine.h"
#include "drugstore.h"
#include "relation.h"

void connect(lire L, adrapt P, admed C);
void disconnect(lire &L, adrapt P, admed C);
int countMed(lire L);
int countApt(lire L);
void listMedfApt(lire L); /**obat tersedia di apotik ? */
void listAptfMed(lire L); /**apotuk mentediakan obat ? */
bool isredundant(lire L);

#endif // GENERALOPERATION_H_INCLUDED
