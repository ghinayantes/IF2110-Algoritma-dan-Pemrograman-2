#ifndef HAPUS_BERULANG_H
#define HAPUS_BERULANG_H

#include "linkedlist.h"

/* HAPUS BERULANG */
/* DEFINISI DAN SPESIFIKASI */
void hapusBerulang(List *l);
/* Menghapus semua node yang angkanya muncul lebih dari sekali pada list.
   Harus diselesaikan secara rekursif.
   I.S. l terdefinisi, mungkin kosong.
        l berisi paling banyak 100 elemen, setiap elemen bernilai -1000..1000.
   F.S. l hanya berisi node yang angkanya muncul tepat satu kali pada list awal,
        dengan urutan semula.
        Node lainnya dihapus dan didealokasi dengan dealokasi.
        Node yang tersisa adalah node yang sama; tidak ada node baru, INFO tidak diubah.
        Jika semua angka muncul lebih dari sekali, l menjadi NIL.
   Contoh: [4,1,4,2,1,5] menjadi [2,5]; [3,3,3] menjadi []. */

#endif
