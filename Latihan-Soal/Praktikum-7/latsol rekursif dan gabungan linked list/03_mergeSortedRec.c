/* File: mergeSortedRec.c */
/* Menggabungkan dua linked list terurut secara rekursif */

#include "listlinier.c"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Dua cabang sebuah toko buku masing-masing menyimpan harga buku dalam
 * linked list terurut menaik. Kantor pusat ingin menggabungkan keduanya
 * menjadi satu daftar harga terurut menaik, tanpa membuat node baru
 * (cukup menyambung ulang node yang ada).
 *
 * TUGAS
 * Implementasikan fungsi mergeSortedRec yang menggabungkan l1 dan l2
 * menjadi satu list terurut menaik dengan cara relink node secara
 * rekursif, dan mengembalikan alamat node pertama hasil. Jika ada nilai
 * yang sama, node dari l1 didahulukan.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while. Tidak ada
 * alokasi/dealokasi node.
 *
 * I.S.  : l1 dan l2 terdefinisi, masing-masing terurut menaik, mungkin kosong
 * F.S.  : mengembalikan list terurut menaik berisi semua node l1 dan l2.
 *         Setelah pemanggilan, l1 dan l2 tidak boleh dipakai lagi
 *         (cara pemakaian: l3 = mergeSortedRec(l1, l2);)
 *
 * Contoh:
 * mergeSortedRec([1,4,7], [2,4,9]) = [1,2,4,4,7,9]
 * mergeSortedRec([], [3,5])        = [3,5]
 * mergeSortedRec([1,2], [])        = [1,2]
 * mergeSortedRec([], [])           = []
 *
 * Hint: ada dua basis (salah satu list kosong). Pada rekurens, pilih node
 *       pertama yang lebih kecil, lalu sambungkan NEXT-nya dengan hasil
 *       penggabungan sisa kedua list
 */
List mergeSortedRec(List l1, List l2) {
    /* KAMUS LOKAL
     *
     * (tidak ada variabel lokal yang wajib)
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if (l1 == NULL) {
        return l2;
    } else if (l2 == NULL) {
        return l1;
    } else if (INFO(l1) <= INFO(l2)) {
        NEXT(l1) = mergeSortedRec(NEXT(l1), l2);
        return l1;
    } else {
        NEXT(l2) = mergeSortedRec(l1, NEXT(l2));
        return l2;
    }
}

void displayRest(List l) {
    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if (l == NULL) printf("]\n");
    else {
        printf(",%d", INFO(l));
        l = NEXT(l);
        displayRest(l);
    }
}

void displayListRec(List l) {
    /* KAMUS LOKAL
     *
     * (tidak ada variabel lokal yang wajib)
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if (l == NULL) {
        printf("[");
        displayRest(l);
    }
    else {
        printf("[%d", INFO(l));
        displayRest(NEXT(l));
    }
}

int main() {
    List l1, l2;
    CreateList(&l1);
    insertLast(&l1, 1);
    insertLast(&l1, 4);
    insertLast(&l1, 7);
    CreateList(&l2);
    insertLast(&l2, 2);
    insertLast(&l2, 4);
    insertLast(&l2, 9);

    displayListRec(mergeSortedRec(l1, l2));
    return 0;
}