/* File: reverseRec.c */
/* Membalik linked list secara rekursif */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Di sebuah restoran, tumpukan piring bersih disimpan dalam sebuah linked
 * list dari piring paling atas ke paling bawah. Saat shift berganti,
 * tumpukan harus dibalik sehingga piring yang tadinya paling bawah menjadi
 * paling atas.
 *
 * TUGAS
 * Implementasikan fungsi reverseRec yang membalik list l dengan cara
 * mengubah pointer NEXT (relink), secara rekursif, dan mengembalikan
 * alamat node pertama list hasil. Tidak ada alokasi/dealokasi node baru.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while.
 *
 * I.S.  : l terdefinisi, mungkin kosong
 * F.S.  : mengembalikan alamat node pertama list yang sudah dibalik.
 *         Cara pemakaian: l = reverseRec(l);
 *
 * Contoh:
 * Jika l = [1,2,3,4], maka setelah l = reverseRec(l), l menjadi [4,3,2,1]
 * Jika l = [9],       maka l tetap [9]
 * Jika l = [],        maka l tetap []
 *
 * Hint: ada DUA basis, yaitu list kosong dan list satu node (keduanya
 *       sudah "terbalik"). Pada rekurens, balik dulu sisa list (NEXT(l)),
 *       lalu sambungkan node saat ini menjadi node terakhir pada hasil
 *       tersebut. Ingat bahwa NEXT(l) sebelum dibalik kini adalah ekor list hasil
 */
List reverseRec(List l) {
    /* KAMUS LOKAL
     *
     * newFirst : List {alamat node pertama dari sisa list yang sudah dibalik}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    return NULL;
}
