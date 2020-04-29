#ifndef GENERALOPERATION_H_INCLUDED
#define GENERALOPERATION_H_INCLUDED
#include "medicine.h"
#include "drugstore.h"
#include "relation.h"

void connect(lire L, Listapt P, limed C); /**menghubungkan apotik dengan obat, jangan dilakukan bila redundan*/ //bagja
void disconnectmed(lire &L, admed C); /**mendiskonek med dari apt*/ //manuel
void disconnectapt(lire &L, adrapt P); /**mendiskonek apt dari med*/ //bagja
void disconnectonerel(lire &L, adrapt P, admed C); /**hanya diskonek 1 relasi*/
int countMed(lire L); /**hitung ada berapa obat yang dimiliki apotik*/ //manuel
int countApt(lire L); /**hitung ada berapa apotik yang punya obat*/ //bagja
void listMedfApt(lire L, admed A); /**obat tersedia di apotik apa aja ? */ //manuel
void listAptfMed(lire L, adrapt A); /**apotik menyediakan obat apa aja ? */ //bagja
bool isredundant(lire L, adrapt P, admed C); /**jika sudah ada obat dan apotik yang sama jangan dilakukan*/ //manuel

#endif // GENERALOPERATION_H_INCLUDED
