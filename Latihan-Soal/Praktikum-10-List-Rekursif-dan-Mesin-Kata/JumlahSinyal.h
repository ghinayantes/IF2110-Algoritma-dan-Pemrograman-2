#ifndef JUMLAH_SINYAL_H
#define JUMLAH_SINYAL_H

#include "listrec.h"
#include "mesinkata.h"

List jumlahDuaCatatan(void);
/* Membaca pita sampai MARK. Pita berisi dua catatan bilangan yang
   dipisahkan tepat satu kata "SEKAT" dan keduanya sama banyak.
   Fungsi menghasilkan list baru; elemen ke-i adalah jumlah bilangan ke-i
   catatan pertama dan bilangan ke-i catatan kedua.
   Memanggil startWord sendiri dan tidak mencetak keluaran.
   Jika kedua catatan kosong, hasilnya list kosong.
   I.S. Posisi baca berada di awal pita; pita diakhiri MARK dan memuat
        tepat satu kata "SEKAT"; kata lainnya adalah bilangan bulat.
   F.S. Semua kata telah diakuisisi (endWord true). */

#endif
