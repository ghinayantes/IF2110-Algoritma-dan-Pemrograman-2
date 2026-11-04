/* Nama File: quicksort.c */
/* Kompilasi: gcc 05_quickSort.c list.c -o quicksort */

#include "list.h"
#include <stdio.h>

/*
 * CERITA
 * Seorang guru mengurutkan nilai siswa dengan cara "pivot": ambil nilai
 * pertama sebagai pivot, kelompokkan nilai lain menjadi yang lebih kecil
 * dan yang lebih besar atau sama, lalu urutkan masing-masing kelompok
 * dengan cara yang sama. Guru ingin melihat pivot apa saja yang dipakai.
 *
 * TUGAS
 * Implementasikan fungsi quickSort yang mengembalikan list BARU terurut menaik
 * berisi elemen l, dengan aturan:
 *   1. Jika l kosong atau satu elemen, kembalikan salinannya (tidak mencetak apa pun).
 *   2. Jika tidak, pivot = head(l). Cetak sebuah baris "pivot X" (X = nilai pivot).
 *   3. kecil = elemen tail(l) yang < pivot; besar = elemen tail(l) yang >= pivot
 *      (urutan relatif elemen dipertahankan).
 *   4. Urutkan kecil terlebih dahulu, BARU urutkan besar.
 *   5. Hasil = (kecil terurut) diikuti pivot diikuti (besar terurut).
 * List l tidak boleh berubah.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while pada fungsi yang
 * Anda tulis. Gunakan rekursi dan primitif pada list.h.
 * PERHATIAN: urutan evaluasi argumen fungsi pada C tidak dijamin. Jika
 * menulis concat(quickSort(a), quickSort(b)), baris "pivot" bisa tercetak
 * dalam urutan yang berbeda. Simpan hasil tiap panggilan pada variabel
 * terlebih dahulu agar urutan cetak terjaga.
 *
 * I.S.  : l terdefinisi, mungkin kosong
 * F.S.  : mengembalikan list baru terurut menaik; baris "pivot X" tercetak
 *         sesuai aturan di atas
 *
 * Format Masukan:
 * - Baris pertama: n (0 <= n <= 200).
 * - Baris kedua: n bilangan bulat. Tidak ada jika n = 0.
 *
 * Format Keluaran:
 * - Baris-baris "pivot X" sesuai urutan pemanggilan, diikuti satu baris
 *   list terurut (displayList), diakhiri newline.
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan             Keluaran
 * 1.  5                   pivot 3
 *     3 1 4 1 5           pivot 1
 *                         pivot 4
 *                         1 1 3 4 5
 * 2.  4                   pivot 4
 *     4 3 2 1             pivot 3
 *                         pivot 2
 *                         1 2 3 4
 * 3.  3                   pivot 2
 *     2 2 2               pivot 2
 *                         2 2 2
 * 4.  1                   7
 *     7
 * 5.  0                   (baris kosong)
 */

/* filterLess: list baru berisi elemen l yang < x (urutan terjaga) */
List filterLess(List l, ElType x) {
    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if (isEmpty(l)) {
        return NIL;
    }
    else if (head(l) < x) {
        return konso(head(l), filterLess(tail(l), x));
    }
    else {
        return filterLess(tail(l), x);
    }
}

/* filterGreaterEqual: list baru berisi elemen l yang >= x (urutan terjaga) */
List filterGreaterEqual(List l, ElType x) {
    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if (isEmpty(l)) {
        return NIL;
    }
    else if (head(l) >= x) {
        return konso(head(l), filterGreaterEqual(tail(l), x));
    }
    else {
        return filterGreaterEqual(tail(l), x);
    }
}

List quickSort(List l) {
    /* KAMUS LOKAL
     *
     * kecil, besar : List {kelompok elemen < pivot dan >= pivot}
     * sk, sb       : List {hasil pengurutan kecil dan besar}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if (isEmpty(l) || isEmpty(tail(l))) {
        return copy(l);
    }
    else {
        ElType pivot = head(l);
        printf("pivot %d\n", pivot);

        List kecil = filterLess(tail(l), pivot);
        List besar = filterGreaterEqual(tail(l), pivot);

        List sk = quickSort(kecil);
        List sb = quickSort(besar);

        List hasil = konsDot(sk, pivot);
        hasil = concat(hasil, sb);

        return hasil;
    }
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

    List result = quickSort(l);
    displayList(result);
    printf("\n");
    return 0;
}
