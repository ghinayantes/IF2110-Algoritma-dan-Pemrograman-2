/* File: removeAllValueRec.c */
/* Menghapus semua kemunculan sebuah nilai dari linked list secara rekursif */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Sebuah aplikasi pesan menyimpan kode pesan masuk dalam sebuah linked
 * list. Pesan berkode x ternyata spam dan harus dihapus dari kotak masuk
 * seluruhnya, dan memorinya dikembalikan ke sistem.
 *
 * TUGAS
 * Implementasikan prosedur removeAllValueRec yang menghapus SEMUA node
 * bernilai x dari list l secara rekursif. Setiap node yang dihapus
 * harus di-dealokasi (free).
 *
 * ATURAN: dilarang memakai while, for, maupun do-while, dan dilarang
 * memanggil deleteFirst, deleteLast, maupun deleteAt.
 *
 * I.S.  : l terdefinisi, mungkin kosong
 * F.S.  : l tidak mengandung nilai x; urutan elemen lain tidak berubah
 *
 * Contoh:
 * Jika l = [1,2,3,2,2,4], x = 2, maka setelah removeAllValueRec(&l, 2), l menjadi [1,3,4]
 * Jika l = [5,5,5],       x = 5, maka l menjadi []
 * Jika l = [1,2,3],       x = 9, maka l tetap [1,2,3]
 * Jika l = [],            x = 1, maka l tetap []
 *
 * Hint: basis adalah *l = NULL. Jika node pertama bernilai x, putuskan
 *       dengan *l = NEXT(*l) lalu free node lama, dan LANJUTKAN rekursi pada
 *       *l yang baru (jangan maju dulu). Jika tidak bernilai x, rekursi
 *       pada &NEXT(*l)
 */
void removeAllValueRec(List *l, ElType x) {
    /* KAMUS LOKAL
     *
     * del : Address {pointer ke node yang akan di-dealokasi}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
}
