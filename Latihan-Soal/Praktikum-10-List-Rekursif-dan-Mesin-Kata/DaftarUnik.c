#include "DaftarUnik.h"

static void sisipUnik(List *l, int x) {
    if (isEmpty(*l) || x < INFO(*l)) {
        *l = makeCons(x, *l);
    } else if (x > INFO(*l)) {
        sisipUnik(&NEXT(*l), x);
    }
    /* x == INFO(*l): sudah ada, tidak melakukan apa-apa */
}

static void bacaKe(List *l) {
    if (!endWord) {
        sisipUnik(l, kataKeInt(currentWord));
        advWord();
        bacaKe(l);
    }
}

List daftarUnik(void) {
    List l = NIL;
    startWord();
    bacaKe(&l);
    return l;
}
/* Membaca pita sampai MARK dan menghasilkan list berisi bilangan-bilangan
   yang berbeda pada pita, terurut menaik. Bilangan yang muncul lebih dari
   sekali hanya muncul satu kali pada list.
   Memanggil startWord sendiri dan tidak mencetak keluaran.
   Setiap kata pada pita adalah bilangan bulat.
   Jika tidak ada kata, hasilnya list kosong.
   I.S. Posisi baca berada di awal pita; pita diakhiri MARK.
   F.S. Semua kata telah diakuisisi (endWord true). Tidak ada simpul yang
        dibuat untuk bilangan yang sudah ada pada list. */