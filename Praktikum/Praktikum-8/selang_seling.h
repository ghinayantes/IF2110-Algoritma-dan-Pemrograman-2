#ifndef SELANG_SELING_H
#define SELANG_SELING_H

#include "linkedlist.h"

/* SELANG SELING */
/* DEFINISI DAN SPESIFIKASI */
void selangSeling(List *l);
/* Menyusun ulang list menjadi selang-seling dari kedua ujung.
   Jika list awal adalah L1, L2, ..., Ln maka urutan akhir adalah
   L1, Ln, L2, L(n-1), L3, L(n-2), ... sampai semua elemen terpakai.
   I.S. l terdefinisi, mungkin kosong.
   F.S. l berisi node-node yang sama dengan urutan baru sesuai aturan di atas.
        Tidak ada node yang dialokasikan atau didealokasi.
        INFO setiap node tidak diubah; hanya NEXT (dan *l) yang boleh berubah.
        Node terakhir pada list baru memiliki NEXT Nil. */

#endif