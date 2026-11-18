#ifndef TIMBANG_KATA_H
#define TIMBANG_KATA_H

#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"

/* DEFINISI DAN SPESIFIKASI */
void timbang(void);
/* I.S. Pita belum dibaca. Pita dijamin mengandung tepat satu kata "@"
        Kata-kata sebelum "@" dianggap sebagai bagian kiri
        Kata-kata sesudah "@" dianggap sebagai bagian kanan
   F.S. Mencetak:
        "KIRI"     jika jumlah kata bagian kiri > jumlah kata bagian kanan,
        "KANAN"    jika jumlah kata bagian kanan > jumlah kata bagian kiri,
        "SEIMBANG" jika jumlah kata keduanya sama.
        Kata "@" tidak dihitung. Pita dibaca sampai MARK dan hasil diakhiri newline. */

#endif
