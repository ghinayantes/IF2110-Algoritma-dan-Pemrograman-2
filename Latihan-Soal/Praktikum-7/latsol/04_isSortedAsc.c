/* File: isSortedAsc.c */
/* Memeriksa apakah list terurut menaik */

#include "../listlinier.h"
#include "../listlinier.c"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Menjelang foto bersama, Pak Guru ingin memastikan barisan siswa sudah
 * rapi, yaitu tinggi badan siswa dari depan ke belakang tidak pernah
 * menurun (boleh sama). Tinggi badan setiap siswa disimpan dalam sebuah list.
 *
 * TUGAS
 * Implementasikan fungsi isSortedAsc yang mengembalikan true jika elemen l
 * terurut menaik secara non-decreasing, dan false jika tidak.
 * List kosong dan list satu elemen dianggap terurut.
 *
 * I.S.  : l terdefinisi, mungkin kosong
 * F.S.  : mengembalikan true/false sesuai ketentuan. l tidak berubah
 *
 * Contoh:
 * isSortedAsc([1,2,2,5]) = true
 * isSortedAsc([1,3,2])   = false
 * isSortedAsc([7])       = true
 * isSortedAsc([])        = true
 *
 * Hint: bandingkan setiap node dengan node sesudahnya; berhenti begitu ketemu pelanggaran
 */
boolean isSortedAsc(List l) {
    /* KAMUS LOKAL
     *
     * p     : Address {pointer traversal}
     * sorted : boolean {status keterurutan sejauh ini}
     */
    Address p = FIRST(l);
    boolean sorted = true; 

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    int start = INFO(p);
    while (p != NULL) {
        if (INFO(p) >= start && sorted == true) {
            start = INFO(p);
            p = NEXT(p);
        }
        else {
            sorted = false;
            break;
        }
    }
    return sorted;
}

int main() {
    List l = NULL;
    insertLast(&l, 1);
    insertLast(&l, 1);
    insertLast(&l, 2);
    insertLast(&l, 5);

    if (isSortedAsc(l)) printf("true\n");
    else printf("false\n");

    return 0;
} 