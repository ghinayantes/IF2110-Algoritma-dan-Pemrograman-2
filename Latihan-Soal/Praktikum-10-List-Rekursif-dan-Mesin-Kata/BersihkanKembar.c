#include "BersihkanKembar.h"
#include <stdio.h>

static List bacaSisa(void) {
    if (endWord) return NIL;
    int x = kataKeInt(currentWord);
    advWord();
    return makeCons(x, bacaSisa());
}

static void bersihkan(List l) {
    if (!isEmpty(l)) {
        bersihkan(NEXT(l));
        if (NEXT(l) != NIL && INFO(l) == INFO(NEXT(l))) {
            Address p = NEXT(l);
            NEXT(l) = NEXT(p);
            dealokasi(p);
        }
    }
}

List bersihkanKembar(void) {
    startWord();
    List l = bacaSisa();
    bersihkan(l);
    return l;
}

/* Membaca pita sampai MARK dan menghasilkan list berisi bilangan pada
   pita sesuai urutan kemunculan, dengan setiap deretan bilangan kembar
   yang bersebelahan hanya disisakan satu.
   Memanggil startWord sendiri dan tidak mencetak keluaran.
   Setiap kata pada pita adalah bilangan bulat.
   Bilangan yang sama tetapi tidak bersebelahan tetap dipertahankan.
   Jika tidak ada kata, hasilnya list kosong.
   I.S. Posisi baca berada di awal pita; pita diakhiri MARK.
   F.S. Semua kata telah diakuisisi (endWord true).
        Setiap simpul yang dibuang dari list telah didealokasi
        (tidak ada kebocoran memori). */