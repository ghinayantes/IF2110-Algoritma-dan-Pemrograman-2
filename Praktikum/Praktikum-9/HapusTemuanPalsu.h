#ifndef HAPUS_TEMUAN_PALSU_H
#define HAPUS_TEMUAN_PALSU_H

#include "listrec.h"

/* HAPUS TEMUAN PALSU */
/* DEFINISI DAN SPESIFIKASI */
void hapusTemuan(List *l, int target);
/* Menghapus semua node bernilai target dari list secara rekursif.
   I.S. l menunjuk List valid, mungkin kosong.
   F.S. Semua node bernilai target dihapus dari list.
        Node lainnya tetap menggunakan alamat dan INFO semula, dengan urutan
        relatif yang sama. *l diperbarui jika node pertama ikut dihapus.
        Tidak mengalokasikan node baru atau menyalin INFO antar node.
   Gunakan rekursi tanpa loop.
   Node yang dilepas sebaiknya dibebaskan dengan free dari <stdlib.h>. */

#endif
