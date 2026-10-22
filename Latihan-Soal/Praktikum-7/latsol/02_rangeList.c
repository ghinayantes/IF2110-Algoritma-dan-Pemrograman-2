/* File: rangeList.c */
/* Menghitung selisih nilai terbesar dan terkecil dalam list */

#include "../listlinier.h"
#include "../listlinier.c"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Stasiun cuaca di Lembang mencatat suhu setiap jam dalam sebuah list.
 * Petugas ingin mengetahui seberapa besar fluktuasi suhu hari itu, yaitu
 * selisih antara suhu tertinggi dan suhu terendah.
 *
 * TUGAS
 * Implementasikan fungsi rangeList yang mengembalikan (nilai maksimum - nilai minimum)
 * dari seluruh elemen l. Dilarang mengurutkan list dan dilarang memanggil
 * fungsi lain selain primitif dasar; cukup satu kali traversal.
 *
 * I.S.  : l terdefinisi, tidak kosong
 * F.S.  : mengembalikan max - min dari elemen l. l tidak berubah
 *
 * Contoh:
 * rangeList([25,30,22,28]) = 8
 * rangeList([7])           = 0
 * rangeList([-3,4,-8,1])   = 12
 *
 * Hint: inisialisasi max dan min dengan elemen pertama
 */
int rangeList(List l) {
    /* KAMUS LOKAL
     *
     * p   : Address {pointer traversal}
     * max : int {nilai terbesar yang ditemukan sejauh ini}
     * min : int {nilai terkecil yang ditemukan sejauh ini}
     */
    Address p = FIRST(l);
    int max, min = INFO(p);

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    while (p != NULL) {
        if (INFO(p) > max) max = INFO(p);
        else if (INFO(p) < min) min = INFO(p);
        p = NEXT(p);
    }
    return max - min;
}

int main() {
    List l = NULL;
    insertLast(&l, 25);
    insertLast(&l, 30);
    insertLast(&l, 22);
    insertLast(&l, 28);

    printf("%d\n", rangeList(l));

    return 0;
} 
