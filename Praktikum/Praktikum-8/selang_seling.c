#include "selang_seling.h"

#include <stdio.h>

void selangSeling(List *l) {
	Address p = *l;
    Address sisa, last;

    while (p != NULL && NEXT(p) != NULL && NEXT(NEXT(p)) != NULL) {
        sisa = NEXT(p);                 
        last = lepasTerakhir(&sisa);    
        NEXT(last) = NEXT(p);           
        NEXT(p) = last;                 
        p = NEXT(last);                 
    }
}
/* Menyusun ulang list menjadi selang-seling dari kedua ujung.
   Jika list awal adalah L1, L2, ..., Ln maka urutan akhir adalah
   L1, Ln, L2, L(n-1), L3, L(n-2), ... sampai semua elemen terpakai.
   I.S. l terdefinisi, mungkin kosong.
   F.S. l berisi node-node yang sama dengan urutan baru sesuai aturan di atas.
        Tidak ada node yang dialokasikan atau didealokasi.
        INFO setiap node tidak diubah; hanya NEXT (dan *l) yang boleh berubah.
        Node terakhir pada list baru memiliki NEXT Nil. */