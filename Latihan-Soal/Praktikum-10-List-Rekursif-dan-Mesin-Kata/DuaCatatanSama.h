#ifndef DUA_CATATAN_SAMA_H
#define DUA_CATATAN_SAMA_H

#include "listrec.h"
#include "mesinkata.h"

int duaCatatanSama(void);
/* Membaca pita sampai MARK. Pita berisi dua catatan bilangan yang
   dipisahkan tepat satu kata "SEKAT". Fungsi menghasilkan 1 jika catatan
   sebelum SEKAT sama persis dengan catatan sesudah SEKAT (banyak elemen
   sama dan urutan elemen sama), dan 0 jika tidak.
   Memanggil startWord sendiri dan tidak mencetak keluaran.
   Salah satu atau kedua catatan boleh kosong.
   I.S. Posisi baca berada di awal pita; pita diakhiri MARK dan memuat
        tepat satu kata "SEKAT"; kata lainnya adalah bilangan bulat.
   F.S. Semua kata telah diakuisisi (endWord true). */

#endif
