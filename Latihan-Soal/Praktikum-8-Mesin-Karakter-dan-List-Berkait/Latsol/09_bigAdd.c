/* Nama File: bigadd.c */
/* Kompilasi: gcc 09_bigAdd.c mesinkata.c mesinkarakter.c listlinier.c -o ba */

#include "mesinkata.h"
#include "listlinier.h"
#include <stdio.h>

/*
 * CERITA
 * Sebuah kalkulator lama hanya mampu menyimpan bilangan sampai sepuluh
 * digit. Seorang insinyur ingin mengakalinya dengan menyimpan setiap digit
 * bilangan pada sebuah linked list, sehingga dua bilangan yang sangat
 * besar dapat dijumlahkan digit demi digit seperti menjumlah di atas kertas.
 *
 * TUGAS
 * Anda diberikan dua buah bilangan bulat nonnegatif yang ditulis sebagai
 * dua kata digit, dipisahkan spasi, dan diakhiri MARK '.'. Tuliskan
 * hasil penjumlahan keduanya.
 *
 * Tiap bilangan harus disimpan pada sebuah list dengan digit TERENDAH
 * (satuan) sebagai elemen PERTAMA, sehingga penjumlahan dapat dilakukan
 * dengan satu kali traversal bersama kedua list dari depan, lengkap
 * dengan carry (sisa penjumlahan).
 *
 * Format Masukan:
 * - Satu baris berisi dua kata digit (masing-masing 1 sampai 40 digit,
 *   tanpa nol di depan kecuali bilangan 0 itu sendiri), dipisahkan
 *   whitespace(s), diakhiri MARK '.'.
 *
 * Format Keluaran:
 * - Satu baris berisi hasil penjumlahan tanpa nol di depan.
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan                          Keluaran
 * 1.  123 989.                         1112
 * 2.  999 1.                           1000
 * 3.  0 0.                             0
 * 4.  99999999999999999999 1.          100000000000000000000
 * 5.  5 12345.                         12350
 *
 * Catatan:
 * - Pastikan setiap output diakhiri oleh endline ("\n")!
 * - Gunakan ADT mesin kata, mesin karakter, dan listlinier. Dilarang memakai
 *   tipe data bilangan bulat besar maupun array untuk menyimpan digit.
 *
 * Hint: wordToDigits cukup menyisipkan setiap digit dengan insertFirst
 *       (digit pertama yang dibaca menjadi elemen paling belakang). Selama
 *       masih ada digit pada salah satu list ATAU carry masih bernilai 1,
 *       jumlahkan digit-digit yang tersedia (anggap 0 jika list sudah habis).
 *       Hasil penjumlahan juga berurutan digit terendah di depan, jadi cetak
 *       dengan urutan dari belakang ke depan
 */

/* wordToDigits: mengubah kata digit menjadi list digit, digit terendah di depan.
 * Contoh: "123" menjadi [3,2,1] */
List wordToDigits(Word w) {
    /* KAMUS LOKAL
     *
     * l : List {list hasil}
     * i : int {indeks karakter pada w}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    return NULL;
}

/* addDigitLists: mengembalikan list BARU hasil penjumlahan a dan b (digit
 * terendah di depan). a dan b tidak berubah.
 * Contoh: a = [3,2,1] (123), b = [9,8,9] (989) menghasilkan [2,1,1,1] (1112) */
List addDigitLists(List a, List b) {
    /* KAMUS LOKAL
     *
     * r     : List {list hasil}
     * p, q  : Address {pointer traversal pada a dan b}
     * carry : int {sisa penjumlahan yang dibawa ke digit berikutnya}
     * sum   : int {jumlah digit pada posisi saat ini beserta carry}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    return NULL;
}

/* printDigitsMSB: mencetak list digit yang digit terendahnya di depan, dari
 * digit tertinggi ke terendah, tanpa spasi dan tanpa newline.
 * Contoh: [2,1,1,1] tercetak 1112 */
void printDigitsMSB(List l) {
    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
}

int main(void) {
    Word w1, w2;
    List a, b, r;

    STARTWORD();
    w1 = currentWord;
    ADVWORD();
    w2 = currentWord;

    a = wordToDigits(w1);
    b = wordToDigits(w2);
    r = addDigitLists(a, b);
    printDigitsMSB(r);
    printf("\n");
    return 0;
}
