/* File : bintree.h */
/* ADT pohon biner rekursif (header-only). Tidak perlu file .c tambahan. */
/* Catatan: nama makro/fungsi di sini adalah asumsi umum. Sesuaikan dengan ADT praktikum Anda. */

#ifndef BINTREE_H
#define BINTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int infotype;
typedef struct tNode *Address;
typedef struct tNode {
    infotype info;
    Address left;
    Address right;
} TNode;
typedef Address BinTree;

#define NIL NULL
#define ROOT(p)  (p)->info
#define LEFT(p)  (p)->left
#define RIGHT(p) (p)->right

/* Pohon kosong: p = NIL. Pohon satu elemen (daun): LEFT(p) = RIGHT(p) = NIL */

static inline Address newTreeNode(infotype x) {
    /* Mengembalikan node baru berisi x tanpa anak, atau NIL jika alokasi gagal */
    Address p = (Address) malloc(sizeof(TNode));
    if (p != NIL) {
        ROOT(p) = x;
        LEFT(p) = NIL;
        RIGHT(p) = NIL;
    }
    return p;
}

static inline int isTreeEmpty(BinTree p) {
    /* Bernilai 1 jika p pohon kosong */
    return (p == NIL);
}

static inline int isLeaf(BinTree p) {
    /* Bernilai 1 jika p tidak kosong dan tidak memiliki anak kiri maupun kanan */
    return (p != NIL && LEFT(p) == NIL && RIGHT(p) == NIL);
}

static inline BinTree makeTree(infotype x, BinTree l, BinTree r) {
    /* Membentuk pohon dengan akar x, anak kiri l, dan anak kanan r */
    Address p = newTreeNode(x);
    if (p != NIL) {
        LEFT(p) = l;
        RIGHT(p) = r;
    }
    return p;
}

static inline BinTree buildTreePrefix(void) {
    /* Membaca pohon dari stdin dalam urutan PREFIX (akar, kiri, kanan).
       Nilai 0 menandakan pohon kosong; nilai node selalu bilangan bulat positif.
       Contoh: "1 2 0 0 3 0 0" adalah pohon dengan akar 1, anak kiri 2, anak kanan 3. */
    int x;
    BinTree t;
    if (scanf("%d", &x) != 1 || x == 0) {
        return NIL;
    }
    t = newTreeNode(x);
    LEFT(t) = buildTreePrefix();
    RIGHT(t) = buildTreePrefix();
    return t;
}

#endif
