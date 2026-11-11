/* Nama File: prefixsum.c */
/* Kompilasi: gcc 08_prefixSum.c list.c -o prefixsum */

#include "list.h"
#include <stdio.h>

/*
 * CERITA
 * Dina menabung dan mencatat setoran harian dalam sebuah list (nilai negatif
 * berarti penarikan). Ia ingin mengubah catatan itu menjadi catatan saldo:
 * saldo hari ke-i adalah jumlah semua setoran dari hari pertama sampai hari ke-i.
 *
 * TUGAS
 * Implementasikan fungsi prefixSum yang mengembalikan list BARU berisi jumlah
 * kumulatif elemen l. List l tidak boleh berubah.
 * Gunakan fungsi bantu rekursif yang membawa parameter akumulator
 * (jumlah sampai elemen sebelumnya).
 *
 * ATURAN: dilarang memakai while, for, maupun do-while pada fungsi yang
 * Anda tulis. Gunakan rekursi dan primitif pada list.h.
 *
 * I.S.  : l terdefinisi, mungkin kosong
 * F.S.  : elemen ke-i hasil = e0 + e1 + ... + ei
 *
 * Format Masukan:
 * - Baris pertama: n (0 <= n <= 1000).
 * - Baris kedua: n bilangan bulat (-1000 sampai 1000). Tidak ada jika n = 0.
 *
 * Format Keluaran:
 * - Satu baris isi list hasil (displayList), diakhiri newline.
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan             Keluaran
 * 1.  4                   1 3 6 10
 *     1 2 3 4
 * 2.  3                   3 2 4
 *     3 -1 2
 * 3.  1                   5
 *     5
 * 4.  0                   (baris kosong)
 *
 * Hint: elemen pertama hasil adalah acc + head(l); sisanya adalah prefixSum
 *       dari tail(l) dengan akumulator yang sudah diperbarui
 */

/* prefixSumAcc: prefix sum l dengan akumulator awal acc */
List prefixSumAcc(List l, int acc) {
    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    return NIL;
}

List prefixSum(List l) {
    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    return NIL;
}

int main(void) {
    int n;
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

    List result = prefixSum(l);
    displayList(result);
    printf("\n");
    return 0;
}
