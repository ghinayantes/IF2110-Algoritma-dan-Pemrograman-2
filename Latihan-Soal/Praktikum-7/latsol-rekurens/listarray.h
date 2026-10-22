/* File : listarray.h */
/* List statik (array) sesuai slide "Pemrosesan List secara Rekursif" */
/* Header-only: tidak perlu file .c tambahan. Letakkan sejajar dengan boolean.h */

#ifndef LISTARRAY_H
#define LISTARRAY_H

#include "boolean.h"

#define CAPACITY 100
#define IDX_UNDEF (-999)

typedef int ElType;
typedef struct {
    ElType contents[CAPACITY]; /* memori tempat penyimpan elemen */
    int nEff;                  /* banyaknya elemen efektif, >= 0 */
} List;
/* List kosong adalah List dengan nEff = 0 */

static inline void CreateList(List *l) {
    /* I.S. sembarang; F.S. terbentuk list kosong */
    l->nEff = 0;
}

static inline void insertLast(List *l, ElType val) {
    /* I.S. l terdefinisi; F.S. val ditambahkan di akhir jika masih ada tempat */
    if (l->nEff < CAPACITY) {
        l->contents[l->nEff] = val;
        l->nEff++;
    }
}

#endif
