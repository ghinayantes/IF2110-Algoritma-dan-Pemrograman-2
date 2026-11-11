#include "HapusTemuanPalsu.h"

#include <stdlib.h>

List tail(List l) {
    return l->next;
}

void hapusTemuan(List *l, int target) {

   if(isEmpty(*l)) return;
   else {
      Address p = *l;
      hapusTemuan(&NEXT(p), target);
      if(INFO(*l) == target) {
        *l = NEXT(*l);
        free(p);
      }
   }
}
/* Menghapus semua node bernilai target dari list secara rekursif.
   I.S. l menunjuk List valid, mungkin kosong.
   F.S. Semua node bernilai target dihapus dari list.
        Node lainnya tetap menggunakan alamat dan INFO semula, dengan urutan
        relatif yang sama. *l diperbarui jika node pertama ikut dihapus.
        Tidak mengalokasikan node baru atau menyalin INFO antar node.
   Gunakan rekursi tanpa loop.
   Node yang dilepas sebaiknya dibebaskan dengan free dari <stdlib.h>. */
