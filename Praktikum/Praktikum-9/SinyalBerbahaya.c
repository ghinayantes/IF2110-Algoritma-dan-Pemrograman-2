#include "SinyalBerbahaya.h"

#include <stdio.h>

int hitungBerbahaya(List l, int batas) {
    if (isEmpty(l)) return 0;
    else {
        Address p = l;
        if (INFO(p) > batas) {
            return 1 + hitungBerbahaya(NEXT(p), batas);
        }
        if (INFO(p) <= batas) return hitungBerbahaya(NEXT(p), batas);
    }
}
/* Menghitung banyaknya sinyal dengan nilai lebih besar dari batas.
   I.S. l terdefinisi, mungkin kosong.
   F.S. Mengembalikan banyaknya node dengan INFO > batas; 0 jika l kosong.
        Nilai sama dengan batas tidak dihitung.
   Gunakan rekursi tanpa loop. */
