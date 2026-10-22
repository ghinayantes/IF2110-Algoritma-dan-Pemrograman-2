/* File: 06_countJump.c */
/* Menghitung banyaknya cara melompat (jenis soal seperti lantai.c) */

#include <stdio.h>

/*
 * CERITA
 * Seekor kodok ingin menyeberangi sungai lewat n batu yang berjajar
 * (bernomor 1 sampai n). Ia berdiri di tepi sungai (anggap batu nomor 0).
 * Sekali melompat, kodok dapat maju 1, 2, atau 3 batu sekaligus. Berapa
 * banyak urutan lompatan berbeda yang bisa membawa kodok tepat ke batu nomor n?
 *
 * TUGAS
 * Implementasikan fungsi countJump(n) yang mengembalikan banyaknya cara
 * tersebut, secara rekursif (tanpa loop, tanpa array memoisasi).
 *
 * FORMAT MASUKAN
 * Satu baris berisi bilangan bulat n (1 <= n <= 30)
 *
 * FORMAT KELUARAN
 * Satu baris berisi banyaknya cara
 *
 * CONTOH MASUKAN 1
 * 3
 * CONTOH KELUARAN 1
 * 4
 * (1+1+1, 1+2, 2+1, 3)
 *
 * CONTOH MASUKAN 2
 * 5
 * CONTOH KELUARAN 2
 * 13
 *
 * Nilai lain: n=1 -> 1, n=2 -> 2, n=4 -> 7, n=6 -> 24
 *
 * Hint: ada tiga basis (n = 1, 2, 3). Untuk n yang lebih besar, lompatan
 *       terakhir bisa berupa 1, 2, atau 3 batu
 */
int countJump(int n) {
    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;

    return countJump(n-1) + countJump(n-2) + countJump(n-3);
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", countJump(n));
    return 0;
}
