/* Nama File: reverselist.c */
/* Kompilasi: gcc 01_reverseList.c list.c -o reverselist */

#include "list.h"
#include <stdio.h>

/*
 * CERITA
 * Seorang pustakawan menumpuk kartu katalog dari kartu paling bawah ke
 * paling atas. Karena ingin membaca dari kartu teratas, ia ingin
 * membalik urutan kartu pada daftarnya, tetapi daftar aslinya tidak boleh
 * rusak karena masih dipakai petugas lain.
 *
 * TUGAS
 * Implementasikan fungsi reverseList yang mengembalikan list BARU berisi
 * elemen-elemen l dengan urutan terbalik. List l tidak boleh berubah.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while pada fungsi yang
 * Anda tulis (main boleh). Gunakan rekursi dan hanya primitif pada list.h.
 * PERHATIAN: konsDot(l, e) menyisipkan e di akhir l DENGAN MENGUBAH l itu
 * sendiri (tidak membuat salinan). Jika l tidak boleh berubah, gunakan
 * konsDot(copy(l), e).
 *
 * I.S.  : l terdefinisi, mungkin kosong
 * F.S.  : mengembalikan list baru berisi elemen l dalam urutan terbalik;
 *         l tidak berubah
 *
 * Format Masukan:
 * - Baris pertama: n, banyaknya elemen (0 <= n <= 1000).
 * - Baris kedua: n bilangan bulat (-1000 sampai 1000). Tidak ada jika n = 0.
 *
 * Format Keluaran:
 * - Satu baris berisi isi list hasil, dicetak dengan displayList (setiap
 *   elemen diikuti satu spasi), diakhiri newline. Baris kosong jika list kosong.
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan             Keluaran
 * 1.  5                   5 4 3 2 1
 *     1 2 3 4 5
 * 2.  1                   7
 *     7
 * 3.  0                   (baris kosong)
 *
 * Hint: balik dulu bagian tail(l), lalu letakkan head(l) di akhir hasilnya.
 *       Hasil pembalikan tail(l) adalah list baru, jadi aman diubah
 */
List reverseList(List l) {
    /* KAMUS LOKAL
     *
     * (tidak ada variabel lokal yang wajib)
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */

    if(l == NIL) return l;
    else {
        return konsDot(reverseList(tail(l)), head(l)); 
    }
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    List l = NIL;
    for (int i = 0; i < n; i++) {
        int value;
        if (scanf("%d", &value) != 1) {
            return 0;
        }
        l = konsDot(l, value);
    }

    List result = reverseList(l);
    displayList(result);
    printf("\n");
    return 0;
}
