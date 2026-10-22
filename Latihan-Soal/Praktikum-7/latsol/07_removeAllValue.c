/* File: removeAllValue.c */
/* Menghapus semua kemunculan sebuah nilai dari list */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Pak Budi seorang kurir. Setiap paket yang ia bawa punya kode yang
 * tercatat dalam sebuah list. Ternyata semua paket berkode x ikut basah
 * kehujanan dan harus dibuang dari daftar pengiriman.
 *
 * TUGAS
 * Implementasikan prosedur removeAllValue yang menghapus SEMUA node
 * bernilai x dari list l. Setiap node yang dihapus harus di-dealokasi (free).
 *
 * I.S.  : l terdefinisi, mungkin kosong
 * F.S.  : l tidak mengandung nilai x; urutan elemen lain tidak berubah
 *
 * Contoh:
 * Jika l = [1,2,3,2,2,4], x = 2, maka setelah removeAllValue(&l, 2), l menjadi [1,3,4]
 * Jika l = [5,5,5],       x = 5, maka l menjadi []
 * Jika l = [1,2,3],       x = 9, maka l tetap [1,2,3]
 * Jika l = [],            x = 1, maka l tetap []
 *
 * Hint: waspadai kasus beberapa node pertama bernilai x, FIRST(l) harus ikut diperbarui
 */
void removeAllValue(List *l, ElType x) {
    /* KAMUS LOKAL
     *
     * curr : Address {pointer ke node yang sedang diperiksa}
     * prev : Address {pointer ke node tepat sebelum curr, NULL jika curr node pertama}
     * del  : Address {pointer ke node yang akan di-dealokasi}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
}
