#include "KataTerpanjang.h"

#include <stdio.h>

int max(int a, int b) {
    if(a >= b) return a;
    return b;
}

int panjangKataTerpanjang(void) {
    int prev = 0;
    int cnt = 0;

    START();
    while (!EOP()) {
        if (currentChar != ' ') cnt++;
        else {
            prev = max(prev, cnt);
            cnt = 0;
        }
        ADV();
    }
    prev = max(prev, cnt);
    return prev;
}
/* Membaca teks sampai sebelum MARK dan menghasilkan panjang kata terpanjang.
   Memanggil START sendiri dan tidak mencetak keluaran.
   Kata adalah deret huruf yang dipisahkan satu atau lebih spasi.
   Jika tidak ada kata, hasilnya 0.
   I.S. Posisi baca masukan berada di awal teks; teks diakhiri MARK.
   F.S. Semua karakter sebelum MARK telah diproses. */