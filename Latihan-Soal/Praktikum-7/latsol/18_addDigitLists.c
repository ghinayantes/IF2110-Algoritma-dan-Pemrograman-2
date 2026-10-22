/* File: addDigitLists.c */
/* Menjumlahkan dua bilangan yang direpresentasikan list digit */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Sebuah kalkulator kuno hanya bisa menyimpan bilangan sangat besar
 * sebagai list digit. Digit pertama pada list adalah satuan, digit kedua
 * puluhan, dan seterusnya (urutan terbalik dari penulisan biasa).
 * Misalnya bilangan 342 disimpan sebagai [2,4,3].
 *
 * TUGAS
 * Implementasikan fungsi addDigitLists yang mengembalikan list BARU berisi
 * hasil penjumlahan bilangan l1 dan l2 dalam representasi yang sama
 * (setiap elemen 0..9). l1 dan l2 tidak boleh berubah. Perhatikan carry
 * (sisa penjumlahan) di akhir.
 *
 * I.S.  : l1 dan l2 terdefinisi, setiap elemennya bernilai 0..9, mungkin kosong
 *         (list kosong dianggap tidak punya digit)
 * F.S.  : mengembalikan list baru hasil penjumlahan; [] jika l1 dan l2 sama-sama kosong
 *
 * Contoh:
 * addDigitLists([2,4,3], [5,6,4]) = [7,0,8]     (342 + 465 = 807)
 * addDigitLists([9,9], [1])       = [0,0,1]     (99 + 1 = 100)
 * addDigitLists([], [1,2])        = [1,2]
 * addDigitLists([0], [0])         = [0]
 *
 * Hint: traversal kedua list bersamaan; elemen yang tidak ada dianggap 0
 *       sampai kedua list habis dan carry = 0
 */
List addDigitLists(List l1, List l2) {
    /* KAMUS LOKAL
     *
     * result : List {list hasil}
     * p1     : Address {pointer traversal l1}
     * p2     : Address {pointer traversal l2}
     * carry  : int {sisa penjumlahan yang dibawa ke digit berikutnya}
     * sum    : int {jumlah digit pada posisi saat ini beserta carry}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    return NULL;
}
