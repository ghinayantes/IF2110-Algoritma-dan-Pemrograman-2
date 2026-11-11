#ifndef SINYAL_BERBAHAYA_H
#define SINYAL_BERBAHAYA_H

#include "listrec.h"

/* SINYAL BERBAHAYA */
/* DEFINISI DAN SPESIFIKASI */
int hitungBerbahaya(List l, int batas);
/* Menghitung banyaknya sinyal dengan nilai lebih besar dari batas.
   I.S. l terdefinisi, mungkin kosong.
   F.S. Mengembalikan banyaknya node dengan INFO > batas; 0 jika l kosong.
        Nilai sama dengan batas tidak dihitung.
   Gunakan rekursi tanpa loop. */

#endif
