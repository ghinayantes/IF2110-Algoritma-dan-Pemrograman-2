/* Nama File: zipadd.c */
/* Kompilasi: gcc 07_zipAdd.c list.c -o zipadd */

#include "list.h"
#include <stdio.h>

/*
 * CERITA
 * Dua kasir mencatat pemasukan tiap jam dalam daftar masing-masing. Pemilik
 * toko ingin daftar pemasukan gabungan: pemasukan jam ke-i adalah jumlah
 * pemasukan jam ke-i dari kedua kasir. Jika salah satu kasir bekerja
 * lebih lama, jam-jam sisanya dicatat apa adanya.
 *
 * TUGAS
 * Implementasikan fungsi zipAdd yang mengembalikan list BARU hasil
 * penjumlahan elemen-elemen a dan b yang berposisi sama. Jika panjang
 * keduanya berbeda, sisa elemen list yang lebih panjang disalin apa adanya
 * di akhir hasil. a dan b tidak boleh berubah.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while pada fungsi yang
 * Anda tulis. Gunakan rekursi dan primitif pada list.h.
 *
 * I.S.  : a dan b terdefinisi, mungkin kosong
 * F.S.  : mengembalikan list baru sesuai ketentuan
 *
 * Format Masukan:
 * - Baris 1: n (0 <= n <= 1000). Baris 2: n bilangan bulat (elemen a).
 * - Baris 3: m (0 <= m <= 1000). Baris 4: m bilangan bulat (elemen b).
 *   (Baris elemen tidak ada jika n atau m = 0.)
 *
 * Format Keluaran:
 * - Satu baris isi list hasil (displayList), diakhiri newline.
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan             Keluaran
 * 1.  3                   11 22 3
 *     1 2 3
 *     2
 *     10 20
 * 2.  1                   6 6 7
 *     1
 *     3
 *     5 6 7
 * 3.  0                   4 5
 *     2
 *     4 5
 * 4.  0                   (baris kosong)
 *     0
 *
 * Hint: ada dua basis (salah satu list kosong). Pada rekurens, jumlahkan
 *       head(a) dan head(b), lalu lanjutkan dengan kedua tail
 */
List zipAdd(List a, List b) {
    /* KAMUS LOKAL
     *
     * (tidak ada variabel lokal yang wajib)
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    return NIL;
}

int main(void) {
    int n, m;
    List a = NIL, b = NIL;

    if (scanf("%d", &n) != 1) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        a = konsDot(a, value);
    }

    if (scanf("%d", &m) != 1) {
        return 0;
    }
    for (int i = 0; i < m; i++) {
        int value;
        scanf("%d", &value);
        b = konsDot(b, value);
    }

    List result = zipAdd(a, b);
    displayList(result);
    printf("\n");
    return 0;
}
