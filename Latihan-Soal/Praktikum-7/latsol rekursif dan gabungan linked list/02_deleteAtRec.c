/* File: deleteAtRec.c */
/* Menghapus node pada indeks tertentu secara rekursif */

#include "listlinier.h"
#include "01_displayListRec.c"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Sebuah jalur kereta memiliki gerbong yang nomornya tersimpan dalam
 * sebuah linked list dari gerbong terdepan ke terbelakang. Petugas harus
 * melepas gerbong pada urutan ke-idx (dihitung mulai dari 0) dan mencatat
 * nomor gerbong yang dilepas.
 *
 * TUGAS
 * Implementasikan prosedur deleteAtRec yang menghapus node pada indeks idx
 * dari list l secara rekursif, menyimpan nilainya pada *val, dan men-dealokasi
 * node tersebut.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while, dan dilarang
 * memanggil deleteFirst, deleteLast, maupun deleteAt. Gunakan free sendiri.
 *
 * I.S.  : l tidak kosong, 0 <= idx <= banyak elemen l - 1
 * F.S.  : *val berisi nilai elemen indeks idx; node tersebut dihapus dari l
 *
 * Contoh:
 * Jika l = [10,20,30,40], idx = 2, maka setelah deleteAtRec(&l,2,&v): v = 30, l = [10,20,40]
 * Jika l = [10,20,30,40], idx = 0, maka v = 10, l = [20,30,40]
 * Jika l = [10,20,30,40], idx = 3, maka v = 40, l = [10,20,30]
 * Jika l = [5],           idx = 0, maka v = 5,  l = []
 *
 * Hint: basis adalah idx = 0 (node yang dihapus adalah node yang sedang
 *       ditunjuk *l); pada rekurens, turunkan idx dan maju ke &NEXT(*l)
 */
void deleteAtRec(List *l, int idx, ElType *val) {
    /* KAMUS LOKAL
     *
     * del : Address {pointer ke node yang akan di-dealokasi}
     */
    Address del;

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if (idx == 0) {
        del = *l;
        *val = INFO(*l);
        *l = NEXT(del);
        free(del);
    }
    else {
        deleteAtRec(&NEXT(*l), idx-1, val);
    }
}

int main() {
    List l;
    int val;
    CreateList(&l);
    insertLast(&l, 10);
    insertLast(&l, 20);
    insertLast(&l, 30);
    insertLast(&l, 40);

    deleteAtRec(&l,2,&val);
    displayListRec(l);
    return 0;
}
