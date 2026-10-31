#include "VokalJurnal.h"

#include <stdio.h>

int hitungVokal(void) {
    int cnt = 0;

    START();
    while(!EOP()) {
        if (currentChar == 'a' || currentChar == 'A' || currentChar == 'i' || currentChar == 'I' || currentChar == 'u' || currentChar == 'U' || currentChar == 'e' || currentChar == 'E' || currentChar == 'o' || currentChar == 'O') {
                cnt++;
            }
        ADV();
    }

    return cnt;
}
/* Membaca karakter dari awal sampai sebelum MARK dengan mesin karakter.
   Memanggil START sendiri dan tidak mencetak keluaran.
   Menghasilkan banyaknya huruf vokal (a, i, u, e, o), tanpa membedakan
   huruf besar dan kecil. Spasi dan karakter lain tidak dihitung.
   I.S. Posisi baca masukan berada di awal teks; teks diakhiri MARK.
   F.S. Semua karakter sebelum MARK telah diproses. */