/* Nama File: mergeseq.c */
/* Kompilasi: gcc 08_mergeSeq.c mesinkata.c mesinkarakter.c listlinier.c -o ms */

#include "mesinkata.h"
#include "listlinier.h"
#include <stdio.h>

/*
 * CERITA
 * Dua loket pengumpulan tugas mencatat nilai mahasiswa yang masuk, masing-
 * masing sudah terurut menaik. Kedua catatan itu dituliskan dalam satu baris
 * dengan tanda "|" sebagai pemisah antar loket. Dosen ingin menggabungkannya
 * menjadi satu daftar nilai yang terurut menaik.
 *
 * TUGAS
 * Anda diberikan dua barisan bilangan bulat yang masing-masing terurut
 * menaik (non-decreasing), dipisahkan oleh sebuah token "|", dan diakhiri
 * MARK '.'. Baca dengan mesin kata, ubah setiap token menjadi bilangan
 * bulat, simpan pada dua buah linked list (listlinier.h), lalu gabungkan
 * menjadi satu list terurut menaik dan cetak.
 *
 * Format Masukan:
 * - Satu baris: barisan A, token "|" (berdiri sendiri, dipisah spasi),
 *   barisan B, diakhiri MARK '.'. Setiap barisan memiliki 1 sampai 500
 *   bilangan bulat dengan nilai antara -1000000 dan 1000000 (boleh negatif).
 *
 * Format Keluaran:
 * - Satu baris berisi list hasil penggabungan dengan format [a,b,c,...]
 *   tanpa spasi (sama dengan keluaran displayList).
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan                              Keluaran
 * 1.  1 4 7 | 2 4 9.                       [1,2,4,4,7,9]
 * 2.  -5 0 3 | -10 -5 8 20.                [-10,-5,-5,0,3,8,20]
 * 3.  5 | 1.                               [1,5]
 *
 * Catatan:
 * - Pastikan setiap output diakhiri oleh endline ("\n")!
 * - Gunakan ADT mesin kata, mesin karakter, dan listlinier. Dilarang memakai
 *   scanf maupun array.
 *
 * Hint: wordToInt harus menangani tanda '-' di depan. readSequences berhenti
 *       mengisi list A ketika bertemu token "|" (Length = 1 dan TabWord[0] = '|')
 */

/* wordToInt: mengubah kata berisi bilangan bulat (boleh diawali '-') menjadi int */
int wordToInt(Word w) {
    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    return 0;
}

/* readSequences: membaca masukan, mengisi *a dengan barisan sebelum "|"
 * dan *b dengan barisan sesudah "|" (urutan sesuai masukan) */
void readSequences(List *a, List *b) {
    /* KAMUS LOKAL
     *
     * (tidak ada variabel lokal yang wajib)
     */

    /* ALGORITMA */
    CreateList(a);
    CreateList(b);
    STARTWORD();
    /* TODO: tulis algoritma di sini */
}

/* mergeLists: mengembalikan list baru terurut menaik berisi semua elemen a dan b.
 * I.S. a dan b terurut menaik, mungkin kosong. a dan b tidak berubah */
List mergeLists(List a, List b) {
    /* KAMUS LOKAL
     *
     * c : List {list hasil}
     * p : Address {pointer traversal pada a}
     * q : Address {pointer traversal pada b}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    return NULL;
}

int main(void) {
    List a, b, c;
    readSequences(&a, &b);
    c = mergeLists(a, b);
    displayList(c);
    printf("\n");
    return 0;
}
