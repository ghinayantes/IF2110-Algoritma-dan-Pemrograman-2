/* File: alternatingSum.c */
/* Menghitung jumlah berselang-seling elemen list */

#include "../listlinier.h"
#include "../listlinier.c"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Pak Joko mencatat pembukuan tokonya dalam satu list. Elemen pada indeks
 * genap (0,2,4,...) adalah pemasukan, sedangkan elemen pada indeks ganjil
 * (1,3,5,...) adalah pengeluaran. Laba bersih adalah total pemasukan
 * dikurangi total pengeluaran.
 *
 * TUGAS
 * Implementasikan fungsi alternatingSum yang mengembalikan
 * e0 - e1 + e2 - e3 + ... dari list l.
 *
 * I.S.  : l terdefinisi, mungkin kosong
 * F.S.  : mengembalikan jumlah berselang-seling elemen l. Mengembalikan 0 jika kosong
 *
 * Contoh:
 * alternatingSum([5,3,8,2]) = 8    (5 - 3 + 8 - 2)
 * alternatingSum([1,2,3])   = 2    (1 - 2 + 3)
 * alternatingSum([4])       = 4
 * alternatingSum([])        = 0
 *
 * Hint: gunakan penanda boolean atau penghitung indeks untuk menentukan tanda
 */
int alternatingSum(List l) {
    /* KAMUS LOKAL
     *
     * p     : Address {pointer traversal}
     * sum   : int {akumulasi hasil}
     * idx   : int {indeks node yang sedang ditinjau}
     */
    Address p = FIRST(l);
    int sum = 0;
    int idx = 1;

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if (p != NULL) {
        sum += INFO(p);
        p = NEXT(p);
        idx++;
    }
    while (p != NULL) {
        if (idx % 2 == 0) sum -= INFO(p);
        else sum += INFO(p);
        idx++;
        p = NEXT(p);
    }
    return sum;
}

int main() {
    List l = NULL;
    insertLast(&l, 5);
    insertLast(&l, 3);
    insertLast(&l, 8);
    insertLast(&l, 2);

    printf("%d\n", alternatingSum(l));

    return 0;
} 