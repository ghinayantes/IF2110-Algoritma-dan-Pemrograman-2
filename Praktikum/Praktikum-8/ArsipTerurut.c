#include "ArsipTerurut.h"

#include <stdio.h>

void sisipUrut(List *l, int nilai) {
    Address new = newNode(nilai);
    Address p = *l;

    if (p == NULL) {
        *l = new;
    }
    else if (nilai <= INFO(p) && (NEXT(p) == NULL || INFO(NEXT(p)) >= nilai)) {
        NEXT(new) = p;
        *l = new;
    }
    else {
        while(p != NULL) {
            if (INFO(p) <= nilai && (NEXT(p) == NULL || INFO(NEXT(p)) > nilai)) {
                NEXT(new) = NEXT(p);
                NEXT(p) = new;
                break;
            }
            p = NEXT(p);
        }
    } 
}
/* Menyisipkan satu simpul baru berisi nilai pada list berkait.
   Gunakan newNode yang sudah disediakan untuk membuat simpul baru.
   I.S. l menunjuk List valid; list mungkin kosong dan elemen-elemennya
        sudah terurut menaik (tidak menurun). Alokasi memori berhasil.
   F.S. Satu simpul baru ditambahkan sehingga list tetap terurut menaik.
        Nilai yang sama boleh muncul lebih dari sekali.
        Tidak ada keluaran yang dicetak oleh prosedur ini. */