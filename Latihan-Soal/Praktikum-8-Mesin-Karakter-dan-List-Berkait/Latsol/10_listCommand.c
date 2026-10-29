/* Nama File: listcommand.c */
/* Kompilasi: gcc 10_listCommand.c mesinkata.c mesinkarakter.c listlinier.c -o lc */

#include "mesinkata.h"
#include "listlinier.h"
#include "boolean.h"
#include <stdio.h>

/*
 * CERITA
 * Pak Joko mengelola rangkaian gerbong kereta barang. Gerbong dapat
 * ditambahkan di depan atau di belakang, dilepas dari depan atau belakang,
 * dan dicari nomornya. Perintah-perintah itu dituliskan berurutan pada
 * satu baris dan Anda diminta membuat program yang menjalankannya
 * pada sebuah linked list yang awalnya kosong.
 *
 * TUGAS
 * Anda diberikan urutan perintah yang dipisahkan satu atau lebih spasi dan
 * diakhiri MARK '.'. Baca dengan mesin kata, dan jalankan setiap perintah
 * pada list nomor gerbong (listlinier.h):
 *
 *   ADD x      : tambahkan x di akhir list (tidak mencetak apa pun)
 *   PUSH x     : tambahkan x di awal list (tidak mencetak apa pun)
 *   DELFIRST   : hapus elemen pertama dan cetak nilainya;
 *                cetak "KOSONG" jika list kosong
 *   DELLAST    : hapus elemen terakhir dan cetak nilainya;
 *                cetak "KOSONG" jika list kosong
 *   FIND x     : cetak indeks pertama x pada list (mulai dari 0),
 *                atau -1 jika tidak ada
 *   PRINT      : cetak seluruh isi list dengan format [a,b,c] ("[]" jika kosong)
 *
 * Format Masukan:
 * - Satu baris berisi perintah-perintah yang dipisahkan whitespace(s), diakhiri
 *   MARK '.' (1 <= jumlah perintah <= 1000). x adalah bilangan bulat
 *   antara -1000000 dan 1000000 (boleh negatif).
 *
 * Format Keluaran:
 * - Setiap perintah yang mencetak sesuatu menghasilkan satu baris keluaran,
 *   sesuai urutan perintah.
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan                                                         Keluaran
 * 1.  ADD 5 ADD 7 PUSH 3 PRINT DELLAST DELFIRST FIND 5 FIND 9         [3,5,7]
 *     PRINT DELFIRST DELFIRST.                                        7
 *                                                                     3
 *                                                                     0
 *                                                                     -1
 *                                                                     [5]
 *                                                                     5
 *                                                                     KOSONG
 * 2.  PRINT DELLAST.                                                  []
 *                                                                     KOSONG
 * 3.  PUSH -2 ADD 4 PUSH 9 PRINT FIND -2.                             [9,-2,4]
 *                                                                     1
 *
 * Catatan:
 * - Pastikan setiap output diakhiri oleh endline ("\n")!
 * - Gunakan ADT mesin kata, mesin karakter, dan listlinier (insertFirst,
 *   insertLast, deleteFirst, deleteLast, indexOf, displayList, isEmpty).
 * - Dilarang memakai scanf maupun array.
 *
 * Hint: setelah menemukan perintah yang membutuhkan argumen (ADD, PUSH, FIND),
 *       majukan mesin kata untuk mengambil argumennya, lalu ubah dengan wordToInt.
 *       Jangan lupa memajukan mesin kata pada akhir setiap iterasi
 */

/* IsKataSama: true jika w sama persis dengan string str (seperti pada soal telegram) */
boolean IsKataSama(Word w, char *str) {
    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    return false;
}

/* wordToInt: mengubah kata berisi bilangan bulat (boleh diawali '-') menjadi int */
int wordToInt(Word w) {
    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    return 0;
}

void runCommands() {
    /* KAMUS LOKAL
     *
     * l : List {list nomor gerbong, awalnya kosong}
     * v : ElType {penampung nilai yang dihapus}
     */

    List l;
    ElType v;

    /* ALGORITMA */
    CreateList(&l);
    STARTWORD();
    /* TODO: tulis algoritma di sini */
}

int main(void) {
    runCommands();
    return 0;
}
