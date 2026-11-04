/* Nama File: splitat.c */
/* Kompilasi: gcc 04_splitAt.c list.c -o splitat */

#include "list.h"
#include <stdio.h>

/*
 * CERITA
 * Sebuah antrean tiket dibagi menjadi dua loket: k orang pertama dilayani
 * loket A, dan sisanya dilayani loket B, dengan urutan tetap sama seperti
 * pada antrean semula. Jika antrean lebih pendek dari k, semuanya
 * dilayani loket A.
 *
 * TUGAS
 * Implementasikan prosedur splitAt yang membagi list l menjadi *front
 * (k elemen pertama; atau seluruh l jika panjang l kurang dari k) dan *back
 * (sisanya). Kedua hasil adalah list BARU (salinan); l tidak boleh berubah.
 * Prosedur ini bergaya seperti mCopy/mConcat pada list.h (hasil lewat parameter).
 *
 * ATURAN: dilarang memakai while, for, maupun do-while pada fungsi yang
 * Anda tulis. Boleh memakai copy, konso, dan primitif lain pada list.h.
 *
 * I.S.  : l terdefinisi, mungkin kosong. k >= 0. *front dan *back sembarang
 * F.S.  : *front berisi min(k, length(l)) elemen pertama l, *back berisi sisanya
 *
 * Format Masukan:
 * - Baris pertama: n (0 <= n <= 1000).
 * - Baris kedua: n bilangan bulat. Tidak ada jika n = 0.
 * - Baris berikutnya: k (0 <= k <= 2000).
 *
 * Format Keluaran:
 * - Baris pertama: isi *front (displayList). Baris kedua: isi *back (displayList).
 *   Setiap baris diakhiri newline; baris kosong jika listnya kosong.
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan             Keluaran
 * 1.  5                   1 2
 *     1 2 3 4 5           3 4 5
 *     2
 * 2.  5                   (baris kosong)
 *     1 2 3 4 5           1 2 3 4 5
 *     0
 * 3.  3                   1 2 3
 *     1 2 3               (baris kosong)
 *     9
 *
 * Hint: basis adalah l kosong atau k = 0. Pada rekurens, pisahkan tail(l)
 *       dengan k-1, lalu tambahkan head(l) di depan hasil bagian depan
 */
void splitAt(List l, int k, List *front, List *back) {
    /* KAMUS LOKAL
     *
     * tmp : List {hasil bagian depan dari pemisahan tail(l)}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if(isEmpty(l)) {
        *front = NIL;
        *back = NIL;
    }
    else if (k == 0) {
        *front = NIL;
        *back = l;
    }
    else {
        List tmp;
        splitAt(tail(l), k - 1, &tmp, back);
        *front = konso(head(l), tmp);
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

    List front, back;
    splitAt(l, k, &front, &back);
    displayList(front);
    printf("\n");
    displayList(back);
    printf("\n");
    return 0;
}
