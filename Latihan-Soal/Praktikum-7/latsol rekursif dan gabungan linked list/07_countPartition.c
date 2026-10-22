/* File: 07_countPartition.c */
/* Menghitung banyaknya cara membayar dengan pecahan uang (jenis soal seperti parentheses.c) */

#include <stdio.h>

/*
 * CERITA
 * Sebuah mesin vending menerima koin bernilai 1, 2, 3, ..., k rupiah,
 * masing-masing tersedia dalam jumlah tak terbatas. Mesin harus
 * mengembalikan kembalian tepat n rupiah. Dua cara dianggap SAMA jika
 * banyaknya masing-masing jenis koin yang dipakai sama (urutan koin
 * tidak diperhatikan).
 *
 * TUGAS
 * Implementasikan fungsi countPartition(n, k) yang mengembalikan banyaknya
 * cara berbeda membentuk n dari koin bernilai 1..k, secara rekursif.
 *
 * FORMAT MASUKAN
 * Satu baris berisi dua bilangan bulat n dan k (1 <= n <= 30, 1 <= k <= n)
 *
 * FORMAT KELUARAN
 * Satu baris berisi banyaknya cara
 *
 * CONTOH MASUKAN 1
 * 4 4
 * CONTOH KELUARAN 1
 * 5
 * (4, 3+1, 2+2, 2+1+1, 1+1+1+1)
 *
 * CONTOH MASUKAN 2
 * 5 3
 * CONTOH KELUARAN 2
 * 5
 * (3+2, 3+1+1, 2+2+1, 2+1+1+1, 1+1+1+1+1)
 *
 * CONTOH MASUKAN 3
 * 6 2
 * CONTOH KELUARAN 3
 * 4
 *
 * Hint: untuk setiap pecahan terbesar k ada dua pilihan: (1) pakai
 *       setidaknya satu koin k, sehingga sisa n-k masih boleh memakai
 *       koin 1..k, atau (2) tidak pakai koin k sama sekali, sehingga
 *       pecahan terbesar menjadi k-1. Tentukan basisnya untuk n = 0,
 *       n < 0, dan k = 0
 */
int countPartition(int n, int k) {
    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if (n == 0 || n < 0) return 0;
    if (n > 0) {
        if (n >= k) return 1 + countPartition(n-k, k);
        return 1 + k + countPartition (n-k+1, k);
    }
    return 0;
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", countPartition(n, k));
    return 0;
}
