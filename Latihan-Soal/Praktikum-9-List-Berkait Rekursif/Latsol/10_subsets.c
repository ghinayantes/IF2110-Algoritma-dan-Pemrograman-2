/* Nama File: subsets.c */
/* Kompilasi: gcc 10_subsets.c list.c -o subsets */

#include "list.h"
#include <stdio.h>

/*
 * CERITA
 * Seorang koki memiliki n bahan masakan dan ingin mencatat semua
 * kemungkinan kombinasi bahan yang bisa dipakai, dari memakai semuanya
 * sampai tidak memakai bahan sama sekali.
 *
 * TUGAS
 * Implementasikan prosedur subsets yang mencetak SEMUA subset dari list l
 * secara rekursif, satu subset per baris. Untuk setiap elemen, pertimbangkan
 * dua pilihan dengan urutan: AMBIL elemen itu dahulu, baru TIDAK AMBIL.
 * Parameter current berisi elemen yang sudah terpilih sejauh ini
 * (urutan sesuai l). Prosedur printSubset (di bawah) sudah disediakan
 * untuk mencetak satu subset dengan format [a,b,c] dan newline.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while pada fungsi yang
 * Anda tulis. Gunakan rekursi dan primitif pada list.h.
 * PERHATIAN: konsDot(l, e) menyisipkan e di akhir l DENGAN MENGUBAH l itu
 * sendiri (tidak membuat salinan). Jika l tidak boleh berubah, gunakan
 * konsDot(copy(l), e).
 * Karena current dipakai bersama dua cabang rekursi, JANGAN mengubahnya
 * secara langsung pada cabang "ambil".
 *
 * I.S.  : l terdefinisi, mungkin kosong. current adalah list terpilih (awalnya NIL)
 * F.S.  : semua 2^n subset tercetak, satu per baris, dengan urutan ambil-dahulu
 *
 * Format Masukan:
 * - Baris pertama: n (0 <= n <= 10).
 * - Baris kedua: n bilangan bulat unik. Tidak ada jika n = 0.
 *
 * Format Keluaran:
 * - 2^n baris, masing-masing berformat [a,b,c] ("[]" untuk subset kosong).
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan             Keluaran
 * 1.  3                   [1,2,3]
 *     1 2 3               [1,2]
 *                         [1,3]
 *                         [1]
 *                         [2,3]
 *                         [2]
 *                         [3]
 *                         []
 * 2.  2                   [5,7]
 *     5 7                 [5]
 *                         [7]
 *                         []
 * 3.  0                   []
 *
 * Hint: basis adalah l kosong, saat itu current adalah satu subset utuh
 *       yang siap dicetak
 */

/* printElems: mencetak elemen l dipisah koma tanpa spasi */
void printElems(List l) {
    if (!isEmpty(l)) {
        printf("%d", head(l));
        if (!isEmpty(tail(l))) {
            printf(",");
        }
        printElems(tail(l));
    }
}

/* printSubset: mencetak l dengan format [a,b,c] diikuti newline (SUDAH DISEDIAKAN) */
void printSubset(List l) {
    printf("[");
    printElems(l);
    printf("]\n");
}

void subsets(List l, List current) {
    /* KAMUS LOKAL
     *
     * (tidak ada variabel lokal yang wajib)
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
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

    subsets(l, NIL);
    return 0;
}
