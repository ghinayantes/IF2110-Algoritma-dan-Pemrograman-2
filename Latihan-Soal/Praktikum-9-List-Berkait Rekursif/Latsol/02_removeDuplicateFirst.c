/* Nama File: removeduplicatefirst.c */
/* Kompilasi: gcc 02_removeDuplicateFirst.c list.c -o rdf */

#include "list.h"
#include <stdio.h>

/*
 * CERITA
 * Panitia lomba mencatat nomor peserta yang mendaftar, dan ada peserta
 * yang mendaftar berkali-kali. Berbeda dengan aturan tahun lalu (yang
 * dipertahankan adalah pendaftaran TERAKHIR), tahun ini yang dipertahankan
 * adalah pendaftaran PERTAMA setiap nomor.
 *
 * TUGAS
 * Implementasikan fungsi removeDuplicateFirst yang mengembalikan list BARU
 * berisi elemen l tanpa duplikat, dengan mempertahankan kemunculan
 * PERTAMA setiap nilai dan urutan relatifnya. List l tidak boleh berubah.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while pada fungsi yang
 * Anda tulis. Boleh memakai search, deleteX, copy, konso, dan primitif
 * lain pada list.h.
 * PERHATIAN: deleteX MENGUBAH list yang diberikan (dan membebaskan node),
 * jadi jangan memanggilnya langsung pada bagian dari l. Gunakan copy dulu.
 *
 * I.S.  : l terdefinisi, mungkin kosong
 * F.S.  : mengembalikan list baru tanpa duplikat (kemunculan pertama yang
 *         dipertahankan); l tidak berubah
 *
 * Format Masukan:
 * - Baris pertama: n (0 <= n <= 1000).
 * - Baris kedua: n bilangan bulat (-1000 sampai 1000). Tidak ada jika n = 0.
 *
 * Format Keluaran:
 * - Satu baris isi list hasil (displayList), diakhiri newline.
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan             Keluaran
 * 1.  5                   1 2 3
 *     1 2 1 3 1
 * 2.  3                   5
 *     5 5 5
 * 3.  4                   1 2 3 4
 *     1 2 3 4
 * 4.  0                   (baris kosong)
 *
 * Hint: head(l) pasti dipertahankan. Sisanya adalah tail(l) yang sudah
 *       dibuang semua nilai yang sama dengan head(l), lalu diproses dengan
 *       cara yang sama
 */
List removeDuplicateFirst(List l) {
    /* KAMUS LOKAL
     *
     * t : List {salinan tail(l) yang boleh dimodifikasi}
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if(isEmpty(l)) return NIL;
    else {
        List t = copy(tail(l));
        if(search(t, head(l))) deleteX(&t, head(l));
        
        return (konso(head(l), removeDuplicateFirst(t)));
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

    List result = removeDuplicateFirst(l);
    displayList(result);
    printf("\n");
    return 0;
}
