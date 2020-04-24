#ifndef GENERAL_H_INCLUDED
#define GENERAL_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define apt(P) P->apt
#define ctn(P) P->ctn
#define last(L) L.last
#define first(L) L.first

/**INFOTYPE*/
struct obat{
    int IDobat;
    string namaObat;
    int hargaObat;
};

struct apotik {
    int IDapotik;
    string namaApotik;
    long noIzin;
};

/**TYPEDEF*/
typedef struct elmlist_relasi *address_relasi;
typedef struct elmlist_child *address_child;
typedef struct elmlist_parent *address_parent;

/**ELMLIST*/
struct elmlist_parent {
    /**SLLL*/
    apotik info;
    address_parent next;
};

struct elmlist_child {
    /**DLLC*/
    obat info;
    address_child next;
    address_child prev;
};

struct elmlist_relasi {
    /**SLLL*/
    address_child ctn;
    address_parent apt;
    address_relasi next;
};

/**LIST*/
struct List_parent {
    address_parent first;
    address_parent last;
};

struct List_child {
    address_child first;
};

struct List_relasi {
    address_parent first;
    address_parent last;
};

#endif // GENERAL_H_INCLUDED
