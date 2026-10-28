/* Nama File: rle.c */
/* Kompilasi: gcc 01_rle.c mesinkarakter.c -o rle */

#include <stdio.h>
#include "mesinkarakter.h"
#include "mesinkata.c"
#include "mesinkarakter.c"

/*
 * CERITA
 * Sebuah stasiun radio kecil menyimpan rekaman sinyal berupa deretan huruf
 * kecil. Agar muat pada memori yang terbatas, teknisi ingin mengompres
 * rekaman tersebut dengan run-length encoding: setiap rentetan huruf yang
 * sama berurutan diganti dengan huruf tersebut diikuti banyaknya huruf
 * pada rentetan itu.
 *
 * TUGAS
 * Anda diberikan sebuah pita karakter berisi huruf kecil. Pita diakhiri oleh
 * MARK berupa '.' (titik) yang bukan bagian dari rekaman. Cetak hasil
 * kompresi rekaman tersebut.
 *
 * Format Masukan:
 * - Satu baris berisi deretan huruf kecil a-z tanpa spasi, diakhiri MARK '.'
 *   (1 <= panjang <= 1000).
 *
 * Format Keluaran:
 * - Satu baris hasil kompresi: huruf1 banyak1 huruf2 banyak2 ... tanpa pemisah.
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan          Keluaran
 * 1.  aaabccdddd.      a3b1c2d4
 * 2.  abc.             a1b1c1
 * 3.  zzzzzzzzzzzz.    z12          (12 huruf z)
 * 4.  aabbaa.          a2b2a2
 *
 * Catatan:
 * - Pastikan setiap output diakhiri oleh endline ("\n")!
 * - Gunakan ADT mesin karakter (START, ADV, currentChar, EOP).
 * - Dilarang menyimpan seluruh pita pada array atau string.
 *
 * Hint: cukup dua variabel, yaitu karakter rentetan yang sedang dihitung dan
 *       banyaknya. Cetak sebuah rentetan ketika karakter berganti, dan jangan
 *       lupa mencetak rentetan terakhir ketika pita habis
 */
void compress() {
    /* KAMUS LOKAL
     *
     * prev : char {huruf pada rentetan yang sedang dihitung}
     * cnt  : int {banyaknya huruf berurutan yang sama dengan prev}
     */
    char prev;
    int cnt;

    /* ALGORITMA */
    START();
    prev = currentChar;
    cnt = 1;
    ADV();
    /* TODO: tulis algoritma di sini */
    while (!EOP) {
        if (currentChar == prev) {
            cnt++;
        } else {
            printf("%c%d", prev, cnt);   /* rentetan lama selesai */
            prev = currentChar;          /* mulai rentetan baru */
            cnt = 1;
        }
        ADV();
    }
    printf("%c%d", prev, cnt);           /* rentetan terakhir */
}

int main(void) {
    compress();
    printf("\n");
    return 0;
}
