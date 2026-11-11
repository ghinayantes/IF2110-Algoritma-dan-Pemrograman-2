#ifndef BERSIHKAN_KEMBAR_H
#define BERSIHKAN_KEMBAR_H

#include "listrec.h"
#include "mesinkata.h"

List bersihkanKembar(void);
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

#endif
