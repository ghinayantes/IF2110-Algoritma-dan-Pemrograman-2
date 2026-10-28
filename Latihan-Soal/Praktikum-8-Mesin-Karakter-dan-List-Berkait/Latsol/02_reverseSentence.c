/* Nama File: reversesentence.c */
/* Kompilasi: gcc 02_reverseSentence.c mesinkata.c mesinkarakter.c -o rs */

#include "mesinkata.c"
#include "mesinkarakter.c"
#include "listword.h"
#include <stdio.h>

/*
 * CERITA
 * Seorang penulis surat iseng menuliskan kalimatnya dalam urutan kata
 * yang terbalik agar tidak mudah dibaca orang lain. Sahabatnya, Dina,
 * ingin membuat program yang membalik urutan kata dalam sebuah kalimat
 * (BUKAN membalik huruf pada kata).
 *
 * TUGAS
 * Anda diberikan sebuah sekuens kata yang dipisahkan oleh satu atau lebih
 * spasi dan diakhiri MARK '.' yang bukan bagian dari kata manapun. Baca
 * kata-kata tersebut dengan mesin kata, simpan pada sebuah linked list
 * (listword.h), lalu cetak kata-kata dengan urutan terbalik.
 *
 * Format Masukan:
 * - Satu baris berisi n buah kata dipisahkan oleh whitespace(s), diakhiri
 *   MARK '.' (1 <= n <= 1000, panjang kata <= 50).
 *
 * Format Keluaran:
 * - Satu baris berisi kata-kata dengan urutan terbalik, dipisahkan tepat satu
 *   spasi, dan diakhiri '.' tanpa spasi di depannya.
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan                          Keluaran
 * 1.  saya suka makan nasi goreng.     goreng nasi makan suka saya.
 * 2.  hello   world .                  world hello.
 * 3.  satu.                            satu.
 *
 * Catatan:
 * - Pastikan setiap output diakhiri oleh endline ("\n")!
 * - Gunakan ADT mesin kata dan mesin karakter.
 * - Dilarang memakai array untuk menyimpan kata. Gunakan list pada listword.h
 *   (insertFirstW, insertLastW, WFIRST, WINFO, WNEXT, printWord).
 *
 * Hint: urutan terbalik dapat diperoleh tanpa membalik list, yaitu dengan
 *       memilih cara menyisipkan yang tepat saat membaca kata
 */
void reverseSentence() {
    /* KAMUS LOKAL
     *
     * l : WList {list penampung kata-kata}
     * p : WAddress {pointer traversal saat mencetak}
     */
    WList l;
    WAddress p;

    CreateWList(&l);

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    STARTWORD();
    while(!EndWord) {
        insertFirstW(&l, currentWord);
        ADVWORD();
    }

    p = WFIRST(l);
    while(p != NULL) {
        printWord(WINFO(p));
        p = WNEXT(p);
        if (p != NULL) printf(" ");
        else printf(".\n");
    }
}

int main(void) {
    reverseSentence();
    return 0;
}
