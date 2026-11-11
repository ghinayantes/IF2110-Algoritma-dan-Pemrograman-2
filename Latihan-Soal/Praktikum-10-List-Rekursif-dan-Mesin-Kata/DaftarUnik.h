#ifndef DAFTAR_UNIK_H
#define DAFTAR_UNIK_H

#include "listrec.h"
#include "mesinkata.h"

List daftarUnik(void);
/* Membaca pita sampai MARK dan menghasilkan list berisi bilangan-bilangan
   yang berbeda pada pita, terurut menaik. Bilangan yang muncul lebih dari
   sekali hanya muncul satu kali pada list.
   Memanggil startWord sendiri dan tidak mencetak keluaran.
   Setiap kata pada pita adalah bilangan bulat.
   Jika tidak ada kata, hasilnya list kosong.
   I.S. Posisi baca berada di awal pita; pita diakhiri MARK.
   F.S. Semua kata telah diakuisisi (endWord true). Tidak ada simpul yang
        dibuat untuk bilangan yang sudah ada pada list. */

#endif
