/* File: displayListRec.c */
/* Mencetak linked list dengan format [a,b,c] secara rekursif */

#include "listlinier.c"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Papan skor sebuah turnamen menyimpan skor para peserta dalam sebuah
 * linked list. Panitia ingin menampilkannya di layar dengan format
 * [skor1,skor2,...,skorN], yaitu dipisah koma tanpa spasi, tanpa koma di
 * akhir, dan tanpa karakter apa pun di awal maupun di akhir selain kurung siku.
 *
 * TUGAS
 * Implementasikan prosedur displayListRec yang mencetak list l dengan
 * format di atas. Tidak ada newline di akhir.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while, dan dilarang
 * memanggil displayList. Boleh membuat fungsi bantu (misalnya displayRest
 * di bawah) bila diperlukan.
 *
 * I.S.  : l terdefinisi, mungkin kosong
 * F.S.  : isi l tercetak dengan format [e1,e2,...,en]; "[]" jika l kosong
 *
 * Contoh:
 * displayListRec([1,20,30]) mencetak [1,20,30]
 * displayListRec([7])       mencetak [7]
 * displayListRec([])        mencetak []
 *
 * Hint: elemen pertama dicetak tanpa koma di depannya, sedangkan setiap
 *       elemen sisanya dicetak dengan koma di depannya. Pisahkan kedua
 *       perlakuan itu dalam dua fungsi
 */

/* displayRest: mencetak ",e" untuk setiap elemen l (bukan elemen pertama keseluruhan) */
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

/*int main() {
    List l;
    CreateList(&l);
    insertLast(&l, 1);
    insertLast(&l, 20);
    insertLast(&l, 30);

    displayListRec(l);

    return 0;
}*/
