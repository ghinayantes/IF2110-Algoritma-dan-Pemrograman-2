#ifndef HITUNG_KATA_H
#define HITUNG_KATA_H

#include "boolean.h"
#include "mesinkata.h"

/* HITUNG KATA */
/* Pita dibaca dari masukan standar dan diakhiri MARK ('.').
   Kata dipisahkan oleh satu atau beberapa BLANK (spasi, tab, atau baris baru).
   Setiap kata terdiri dari huruf kecil dan panjangnya paling banyak NMax. */

int hitungKemunculan(Word w);
/* Mengirimkan berapa kali kata w muncul pada pita.
   Sebuah kata pada pita dihitung hanya jika sama persis dengan w
   (panjangnya sama dan setiap hurufnya sama).
   I.S. Pita belum dibaca (STARTWORD belum dipanggil). w tidak kosong.
   F.S. Seluruh pita sudah dibaca sampai MARK.
        Jika w tidak ada pada pita, hasilnya 0. */

#endif
