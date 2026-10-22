/* File: printReverse.c */
/* Mencetak elemen list statik dari belakang ke depan secara rekursif */

#include "listarray.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Sebuah arsip surat menyimpan nomor surat berurutan dari yang paling
 * lama ke paling baru. Petugas ingin membaca nomor surat dari yang paling
 * baru terlebih dahulu, mulai dari indeks tertentu.
 *
 * TUGAS
 * Implementasikan prosedur printReverse yang mencetak elemen l pada
 * indeks startIdx sampai nEff-1 dalam urutan TERBALIK (dari elemen
 * terakhir ke startIdx). Setiap elemen dicetak dengan format "%d "
 * (diikuti satu spasi), tanpa newline di akhir.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while. Hanya boleh
 * satu kali memanggil printf untuk satu elemen.
 *
 * I.S.  : l terdefinisi, mungkin kosong. startIdx >= 0
 * F.S.  : elemen l.contents[nEff-1] ... l.contents[startIdx] tercetak ke layar
 *
 * Contoh:
 * printReverse([1,2,3], 0) mencetak "3 2 1 "
 * printReverse([1,2,3], 1) mencetak "3 2 "
 * printReverse([1,2,3], 3) tidak mencetak apa pun
 * printReverse([], 0)      tidak mencetak apa pun
 *
 * Hint: urutan terbalik didapat dengan memanggil rekursi untuk sisa list
 *       SEBELUM mencetak elemen saat ini
 */
void printReverse(List l, int startIdx) {
    /* KAMUS LOKAL
     *
     * (tidak ada variabel lokal yang wajib)
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
}
