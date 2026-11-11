#ifndef RENTANG_SINYAL_H
#define RENTANG_SINYAL_H

#include "listrec.h"
#include "mesinkata.h"

void rentangSinyal(int *min, int *max);
/* Membaca pita sampai MARK dan menghasilkan nilai terkecil dan nilai
   terbesar dari seluruh bilangan pada pita.
   Memanggil startWord sendiri dan tidak mencetak keluaran.
   I.S. Posisi baca berada di awal pita; pita diakhiri MARK dan berisi
        paling sedikit satu kata. Setiap kata adalah bilangan bulat.
        min dan max menunjuk variabel int yang valid.
   F.S. *min berisi bilangan terkecil, *max berisi bilangan terbesar.
        Semua kata telah diakuisisi (endWord true). */

#endif
