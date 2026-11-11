/* Nama File: setoperations.c */
/* Kompilasi: gcc 06_setOperations.c list.c -o setops */

#include "list.h"
#include <stdio.h>

/*
 * CERITA
 * Dua ekstrakurikuler, Robotik dan Musik, mencatat nomor induk anggotanya
 * (tiap nomor muncul paling banyak sekali pada satu ekskul). Kepala
 * sekolah ingin tahu: siapa saja yang tergabung di salah satu atau
 * keduanya, siapa yang di kedua ekskul sekaligus, dan siapa yang hanya
 * di Robotik.
 *
 * TUGAS
 * Anggap list A dan B sebagai himpunan (tanpa duplikat di dalam masing-masing).
 * Implementasikan tiga fungsi yang masing-masing mengembalikan list BARU
 * (A dan B tidak boleh berubah):
 *   unionList(A, B)      : semua elemen A (urutan A), lalu elemen B yang
 *                          tidak ada di A (urutan B)
 *   intersectList(A, B)  : elemen A yang juga ada di B (urutan A)
 *   differenceList(A, B) : elemen A yang tidak ada di B (urutan A)
 *
 * ATURAN: dilarang memakai while, for, maupun do-while pada fungsi yang
 * Anda tulis. Boleh memakai search, concat, konso, copy, dan primitif lain.
 *
 * Format Masukan:
 * - Baris 1: n (0 <= n <= 500). Baris 2: n bilangan bulat unik (elemen A).
 * - Baris 3: m (0 <= m <= 500). Baris 4: m bilangan bulat unik (elemen B).
 *   (Baris elemen tidak ada jika n atau m = 0.)
 *
 * Format Keluaran:
 * - Tiga baris: union, intersect, difference (A \ B), masing-masing
 *   dicetak dengan displayList dan diakhiri newline (baris kosong jika kosong).
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan             Keluaran
 * 1.  4                   1 2 3 4 5 6
 *     1 2 3 4             3 4
 *     4                   1 2
 *     3 4 5 6
 * 2.  2                   1 2 3
 *     1 2                 (baris kosong)
 *     1                   1 2
 *     3
 * 3.  0                   (baris kosong)
 *     0                   (baris kosong)
 *                         (baris kosong)
 *
 * Hint: unionList dapat dibangun dari differenceList dengan peran A dan B
 *       ditukar, lalu digabung dengan A
 */
List unionList(List a, List b) {
    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    return NIL;
}

List intersectList(List a, List b) {
    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    return NIL;
}

List differenceList(List a, List b) {
    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    return NIL;
}

int main(void) {
    int n, m;
    List a = NIL, b = NIL;

    if (scanf("%d", &n) != 1) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        a = konsDot(a, value);
    }

    if (scanf("%d", &m) != 1) {
        return 0;
    }
    for (int i = 0; i < m; i++) {
        int value;
        scanf("%d", &value);
        b = konsDot(b, value);
    }

    displayList(unionList(a, b));
    printf("\n");
    displayList(intersectList(a, b));
    printf("\n");
    displayList(differenceList(a, b));
    printf("\n");
    return 0;
}
