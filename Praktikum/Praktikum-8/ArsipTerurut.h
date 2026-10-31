#ifndef ARSIP_TERURUT_H
#define ARSIP_TERURUT_H

#include "listberkait.h"

void sisipUrut(List *l, int nilai);
/* Menyisipkan satu simpul baru berisi nilai pada list berkait.
   Gunakan newNode yang sudah disediakan untuk membuat simpul baru.
   I.S. l menunjuk List valid; list mungkin kosong dan elemen-elemennya
        sudah terurut menaik (tidak menurun). Alokasi memori berhasil.
   F.S. Satu simpul baru ditambahkan sehingga list tetap terurut menaik.
        Nilai yang sama boleh muncul lebih dari sekali.
        Tidak ada keluaran yang dicetak oleh prosedur ini. */

#endif