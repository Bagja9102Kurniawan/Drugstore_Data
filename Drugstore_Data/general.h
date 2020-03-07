#ifndef GENERAL_H_INCLUDED
#define GENERAL_H_INCLUDED

/**INFOTYPE*/
struct obat{
    int IDobat;
    string namaObat;
    int jumObat;
};

struct apotik {
    int IDapotik;
    string namaApotik;
    long noIzin;
};

/**TYPEDEF*/
typedef obat infotype_child;
typedef apotik infotype_parent;
typedef struct elmlist_relasi *address_relasi;
typedef struct elmlist_child *address_child;
typedef struct elmlist_parent *address_parent;

/**ELMLIST*/
struct elmlist_parent {
    /**SLLL*/
    infotype_parent apotik;
    List_relasi child;
    address_parent next;
};

struct elmlist_child {
    /**DLLC*/
    infotype_child obat;
    address_child next;
    address_child prev;
};

struct elmlist_relasi {
    /**SLLL*/
    address_child contain;
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
