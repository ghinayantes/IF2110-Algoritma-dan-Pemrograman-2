/* File: 08_noAdjacent.c */
/* Mencetak semua string biner tanpa dua '1' bersebelahan (jenis soal backtracking seperti password.c) */

#include <stdio.h>

/*
 * CERITA
 * Di sebuah jalan terdapat n lampu berjajar. Untuk menghemat listrik,
 * tidak boleh ada dua lampu bersebelahan yang menyala bersamaan. Petugas
 * ingin mendaftar semua konfigurasi lampu yang diperbolehkan, dengan '1'
 * berarti menyala dan '0' berarti mati.
 *
 * TUGAS
 * Implementasikan prosedur generate(pos, n, buf) yang mencetak semua
 * string biner sepanjang n yang tidak mengandung "11", satu per baris,
 * dalam urutan leksikografis menaik (000 mendahului 001, dst).
 *
 * ATURAN: dilarang memakai library tambahan; gunakan rekursi (backtracking),
 * bukan menghasilkan semua 2^n string lalu menyaringnya.
 *
 * FORMAT MASUKAN
 * Satu baris berisi bilangan bulat n (1 <= n <= 10)
 *
 * FORMAT KELUARAN
 * Setiap konfigurasi pada satu baris, urut menaik
 *
 * CONTOH MASUKAN 1
 * 3
 * CONTOH KELUARAN 1
 * 000
 * 001
 * 010
 * 100
 * 101
 *
 * CONTOH MASUKAN 2
 * 2
 * CONTOH KELUARAN 2
 * 00
 * 01
 * 10
 *
 * CONTOH MASUKAN 3
 * 1
 * CONTOH KELUARAN 3
 * 0
 * 1
 *
 * Hint: buf adalah string yang sedang dibangun (indeks 0..pos-1 sudah
 *       terisi). Basis adalah pos = n (cetak buf). Pada setiap posisi coba
 *       '0' terlebih dahulu, lalu '1' hanya jika posisi sebelumnya bukan '1'
 */
void generate(int pos, int n, char *buf) {
    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
}

int main(void) {
    int n;
    scanf("%d", &n);

    char buf[n + 1];
    buf[n] = '\0';

    generate(0, n, buf);
    return 0;
}
