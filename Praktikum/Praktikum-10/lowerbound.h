#ifndef LOWERBOUND_H
#define LOWERBOUND_H

#include <stdio.h>
#include "listrec.h"

/* DEFINISI DAN SPESIFIKASI */
List lowerBound(List l, int k);
/* Menyaring elemen yang lebih besar dari k secara rekursif.
   I.S. l terdefinisi, mungkin kosong, dengan paling banyak 1000 node.
        Nilai setiap elemen dan k berada pada rentang -1000..1000.
   F.S. Mengirimkan list baru berisi semua elemen l yang lebih besar
        dari k, dengan urutan yang sama seperti pada l.
        l tidak berubah. Jika tidak ada elemen yang lebih besar dari k,
        mengirimkan list kosong (NIL).
        Semua node hasil adalah node baru, bukan node milik l.
        Tidak membaca masukan atau mencetak keluaran. */

#endif
