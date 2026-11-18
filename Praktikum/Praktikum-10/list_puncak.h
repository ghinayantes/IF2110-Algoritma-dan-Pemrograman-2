#ifndef LIST_PUNCAK_H
#define LIST_PUNCAK_H

#include "linkedlist.h"

/* LIST PUNCAK */
List ambilPuncak(List l);
/* Mengirimkan list BARU yang berisi semua angka puncak dari l,
   dengan urutan yang sama seperti pada l.
   Angka puncak adalah angka yang LEBIH BESAR (strict) daripada angka tepat
   di sebelah kirinya DAN angka tepat di sebelah kanannya.
   Angka pertama dan angka terakhir tidak pernah menjadi puncak.
   Harus diselesaikan secara rekursif.
   I.S. l terdefinisi, mungkin kosong.
        l berisi paling banyak 100 elemen, setiap elemen bernilai 1..1000.
   F.S. l tidak berubah.
        Jika tidak ada angka puncak, hasilnya list kosong (NIL).
        Node pada hasil dibuat dengan konso, konsdot, atau newNode
        (tidak memakai node milik l).
   Contoh: l = [1,3,2,5,4] menghasilkan [3,5]. */

#endif
