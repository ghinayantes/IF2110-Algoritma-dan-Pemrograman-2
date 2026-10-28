/* Nama File: uniquewords.c */
/* Kompilasi: gcc 04_uniqueWords.c mesinkata.c mesinkarakter.c -o uw */

#include "mesinkata.c"
#include "mesinkarakter.c"
#include "listword.h"
#include <stdio.h>

/*
 * CERITA
 * Panitia sebuah pesta mencatat nama setiap tamu yang mengisi buku tamu.
 * Karena beberapa tamu mengisi lebih dari sekali, namanya tercatat
 * berkali-kali. Panitia ingin mendapatkan daftar nama unik (tanpa duplikat)
 * sesuai urutan KEMUNCULAN PERTAMA masing-masing nama, beserta banyaknya
 * nama yang berbeda.
 *
 * TUGAS
 * Anda diberikan sebuah sekuens kata (nama) dipisahkan satu atau lebih spasi
 * dan diakhiri MARK '.'. Simpan hanya kemunculan pertama setiap kata pada
 * sebuah linked list (listword.h), lalu cetak hasilnya.
 *
 * Format Masukan:
 * - Satu baris berisi n kata dipisahkan whitespace(s), diakhiri MARK '.'
 *   (1 <= n <= 1000, panjang kata <= 50). Perbandingan kata case-sensitive.
 *
 * Format Keluaran:
 * - Baris pertama: banyaknya kata unik.
 * - Baris kedua: kata-kata unik dengan urutan kemunculan pertamanya,
 *   dipisahkan tepat satu spasi, tanpa spasi tambahan di akhir baris.
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan                          Keluaran
 * 1.  budi ani budi cici ani dedi.     4
 *                                      budi ani cici dedi
 * 2.  a a a a.                         1
 *                                      a
 * 3.  Ani ani ANI.                     3
 *                                      Ani ani ANI
 *
 * Catatan:
 * - Pastikan setiap output diakhiri oleh endline ("\n")!
 * - Gunakan ADT mesin kata dan mesin karakter.
 * - Dilarang memakai array untuk menyimpan kata. Gunakan listword.h
 *   (isWordEqual boleh dipakai).
 */

/* isMemberW: true jika w sudah ada pada list l */
boolean isMemberW(WList l, Word w) {
    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    WAddress p = WFIRST(l);
    boolean ada = false;
    while (p != NULL && !ada) {
        if (isWordEqual(WINFO(p), w)) ada = true;
        p = WNEXT(p);
    }
    return ada;
}

void uniqueWords() {
    /* KAMUS LOKAL
     *
     * l : WList {list kata unik}
     * n : int {banyaknya kata unik}
     * p : WAddress {pointer traversal saat mencetak}
     */
    WList l;
    int n = 0;
    WAddress p;

    CreateWList(&l);

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    STARTWORD();
    while (!EndWord) {
        if (!isMemberW(l, currentWord)) {
            insertLastW(&l, currentWord);
            n++;
        }
        ADVWORD();
    }

    printf("%d\n", n);

    p = WFIRST(l);
    while (p != NULL) {
        printWord(WINFO(p));
        p = WNEXT(p);
        if (p != NULL) printf(" ");
    }
    printf("\n");
}

int main(void) {
    uniqueWords();
    return 0;
}
