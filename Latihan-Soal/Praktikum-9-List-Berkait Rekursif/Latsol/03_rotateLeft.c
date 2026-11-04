/* Nama File: rotateleft.c */
/* Kompilasi: gcc 03_rotateLeft.c list.c -o rotateleft */

#include "list.h"
#include <stdio.h>

/*
 * CERITA
 * Sebuah papan nama berjalan menampilkan deretan kode secara melingkar.
 * Setiap kali papan bergeser satu langkah ke kiri, kode paling depan
 * pindah ke paling belakang. Teknisi ingin tahu susunan kode setelah
 * papan bergeser sebanyak k langkah.
 *
 * TUGAS
 * Implementasikan fungsi rotateLeft yang mengembalikan list BARU hasil
 * rotasi l sebanyak k posisi ke kiri. Jika k lebih besar dari panjang
 * list, gunakan k modulo panjang list. List l tidak boleh berubah.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while pada fungsi yang
 * Anda tulis. Gunakan rekursi dan primitif pada list.h.
 * PERHATIAN: konsDot(l, e) menyisipkan e di akhir l DENGAN MENGUBAH l itu
 * sendiri (tidak membuat salinan). Jika l tidak boleh berubah, gunakan
 * konsDot(copy(l), e).
 *
 * I.S.  : l terdefinisi, mungkin kosong. k >= 0
 * F.S.  : mengembalikan list baru hasil rotasi kiri sebanyak k; l tidak berubah
 *
 * Format Masukan:
 * - Baris pertama: n (0 <= n <= 1000).
 * - Baris kedua: n bilangan bulat. Tidak ada jika n = 0.
 * - Baris berikutnya: k (0 <= k <= 1000000000).
 *
 * Format Keluaran:
 * - Satu baris isi list hasil (displayList), diakhiri newline.
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan             Keluaran
 * 1.  5                   3 4 5 1 2
 *     1 2 3 4 5
 *     2
 * 2.  5                   3 4 5 1 2      (7 mod 5 = 2)
 *     1 2 3 4 5
 *     7
 * 3.  5                   1 2 3 4 5
 *     1 2 3 4 5
 *     0
 * 4.  3                   1 2 3          (k kelipatan panjang)
 *     1 2 3
 *     3
 * 5.  0                   (baris kosong)
 *     4
 *
 * Hint: satu langkah rotasi kiri memindahkan head(l) ke akhir list.
 *       Hitung dulu k mod length(l) agar rekursi tidak sampai 10^9 kali
 */
List rotateLeft(List l, int k) {
    /* KAMUS LOKAL
     *
     * m : int {banyaknya langkah rotasi setelah dimodulo panjang list}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if(l == NIL) return NIL;
    else {
        int m = k % length(l);
        List t = copy(l);
        if (m > 0) {
            m--;
            t = rotateLeft(konsDot(copy(tail(l)), head(l)), m);
        }
        return t;
    }
    
}

int main(void) {
    int n, k;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    List l = NIL;
    for (int i = 0; i < n; i++) {
        int value;
        if (scanf("%d", &value) != 1) {
            return 0;
        }
        l = konsDot(l, value);
    }
    if (scanf("%d", &k) != 1) {
        return 0;
    }

    List result = rotateLeft(l, k);
    displayList(result);
    printf("\n");
    return 0;
}
