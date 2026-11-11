#ifndef POSISI_API_H
#define POSISI_API_H

#include "listrec.h"
#include "mesinkata.h"

List posisiApi(void);
/* Membaca pita sampai MARK dan menghasilkan list berisi nomor urut
   (dimulai dari 1) setiap kata yang sama persis dengan "API",
   terurut menaik.
   Memanggil startWord sendiri dan tidak mencetak keluaran.
   Huruf besar dan huruf kecil dibedakan.
   Jika tidak ada kata "API", hasilnya list kosong.
   I.S. Posisi baca berada di awal pita; pita diakhiri MARK.
   F.S. Semua kata telah diakuisisi (endWord true). */

#endif
