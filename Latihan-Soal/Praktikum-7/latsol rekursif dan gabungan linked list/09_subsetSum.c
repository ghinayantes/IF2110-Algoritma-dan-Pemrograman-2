/* File: 09_subsetSum.c */
/* Mencetak semua subset berjumlah tertentu (jenis soal seperti subsets.c) */

#include <stdio.h>

/*
 * CERITA
 * Seorang kasir memiliki n lembar uang dengan nominal berbeda-beda. Ia
 * ingin tahu kombinasi lembar uang mana saja yang jumlahnya tepat sama
 * dengan target tagihan.
 *
 * TUGAS
 * Implementasikan prosedur subsetSum yang mencetak semua subset elemen
 * arr (berdasarkan posisi, jadi dua elemen bernilai sama di posisi
 * berbeda dianggap berbeda) yang jumlahnya tepat target.
 *
 * Tiap subset dicetak dengan format [a,b,c] dengan elemen mengikuti urutan
 * kemunculannya pada arr. Urutan pencetakan antar subset ditentukan oleh
 * rekursi: untuk setiap elemen, coba AMBIL terlebih dahulu, baru TIDAK
 * AMBIL (seperti pada subsets.c).
 *
 * Parameter: idx = indeks elemen yang sedang dipertimbangkan, size = banyak
 * elemen terpilih pada temp, sum = jumlah elemen terpilih sejauh ini.
 *
 * ATURAN: gunakan rekursi, bukan loop bertingkat/bitmask.
 *
 * FORMAT MASUKAN
 * Baris 1: bilangan bulat n (1 <= n <= 15)
 * Baris 2: n bilangan bulat positif (elemen arr)
 * Baris 3: bilangan bulat positif target
 *
 * FORMAT KELUARAN
 * Setiap subset yang jumlahnya target pada satu baris.
 * Tidak mencetak apa pun jika tidak ada subset yang memenuhi.
 *
 * CONTOH MASUKAN 1
 * 4
 * 3 1 2 4
 * 6
 * CONTOH KELUARAN 1
 * [3,1,2]
 * [2,4]
 *
 * CONTOH MASUKAN 2
 * 3
 * 1 2 3
 * 3
 * CONTOH KELUARAN 2
 * [1,2]
 * [3]
 *
 * Hint: basis adalah idx = n. Cetak temp[0..size-1] hanya bila sum = target
 */
void subsetSum(int idx, int n, int size, int sum, int *temp, int *arr, int target) {
    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
}

int main(void) {
    int n, target;
    scanf("%d", &n);

    int arr[n], temp[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    scanf("%d", &target);

    subsetSum(0, n, 0, 0, temp, arr, target);
    return 0;
}
