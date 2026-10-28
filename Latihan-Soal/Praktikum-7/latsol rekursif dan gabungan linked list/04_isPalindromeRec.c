/* File: isPalindromeRec.c */
/* Memeriksa palindrom linked list secara rekursif */

#include "listlinier.c"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Sebuah pabrik gelang manik-manik ingin memastikan pola warna manik
 * pada gelang bersifat simetris, yaitu urutannya sama jika dibaca dari
 * ujung mana pun. Kode warna manik disimpan dalam sebuah linked list.
 *
 * TUGAS
 * Implementasikan fungsi isPalindromeRec yang mengembalikan true jika
 * list l palindrom, false jika bukan. List kosong dan list satu elemen
 * dianggap palindrom.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while, dilarang memakai
 * array, dan list l tidak boleh berubah isinya. Boleh membuat fungsi bantu.
 *
 * I.S.  : l terdefinisi, mungkin kosong
 * F.S.  : mengembalikan true jika l palindrom, false jika bukan. l tidak berubah
 *
 * Contoh:
 * isPalindromeRec([1,2,3,2,1]) = true
 * isPalindromeRec([1,2,2,1])   = true
 * isPalindromeRec([1,2,3])     = false
 * isPalindromeRec([4])         = true
 * isPalindromeRec([])          = true
 *
 * Hint: fungsi bantu checkPal(right, &left) turun rekursif sampai ujung
 *       list lewat pointer right. Saat kembali dari rekursi, right berada
 *       pada posisi dari belakang, sedangkan *left (pointer yang dipegang
 *       bersama oleh semua level) berada pada posisi yang sama dari depan.
 *       Bandingkan keduanya, lalu majukan *left
 */

/* checkPal: true jika elemen dari depan (mulai *left) sama dengan elemen dari belakang (right) */
boolean checkPal(List right, List *left) {
    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if (right == NULL) {
        return true;
    }

    if (!checkPal(NEXT(right), left)) {
        return false;
    }

    if (INFO(right) != INFO(*left)) {
        return false;
    }

    *left = NEXT(*left);
    return true;
}

boolean isPalindromeRec(List l) {
    /* KAMUS LOKAL
     *
     * left : List {pointer ke node dari depan yang akan dibandingkan}
     */
    List left = l;

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    return checkPal(l, &left);
}

int main() {
    List l;
    CreateList(&l);
    insertLast(&l, 1);
    insertLast(&l, 2);
    insertLast(&l, 3);
    insertLast(&l, 2);
    insertLast(&l, 1);

    printf("%s", isPalindromeRec(l) ? "true\n" : "false\n");
    return 0;
}
