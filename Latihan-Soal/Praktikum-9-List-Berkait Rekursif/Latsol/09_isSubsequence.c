/* Nama File: issubsequence.c */
/* Kompilasi: gcc 09_isSubsequence.c list.c -o issub */

#include "list.h"
#include <stdio.h>

/*
 * CERITA
 * Sebuah mesin sandi menerima kode utama (list B) dan sebuah pola (list A).
 * Pola dianggap COCOK jika seluruh elemen pola muncul pada kode utama
 * dengan urutan yang sama, tetapi tidak harus bersebelahan
 * (boleh ada elemen lain di antaranya).
 *
 * TUGAS
 * Implementasikan fungsi isSubsequence yang bernilai true jika A adalah
 * subsekuens dari B, dan false jika bukan. List kosong adalah subsekuens
 * dari list apa pun. A dan B tidak boleh berubah.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while pada fungsi yang
 * Anda tulis. Gunakan rekursi dan primitif pada list.h.
 *
 * I.S.  : a dan b terdefinisi, mungkin kosong
 * F.S.  : mengembalikan true jika a subsekuens b, false jika tidak
 *
 * Format Masukan:
 * - Baris 1: n (0 <= n <= 500). Baris 2: n bilangan bulat (elemen A).
 * - Baris 3: m (0 <= m <= 500). Baris 4: m bilangan bulat (elemen B).
 *   (Baris elemen tidak ada jika n atau m = 0.)
 *
 * Format Keluaran:
 * - Satu baris: "YA" jika A subsekuens B, atau "TIDAK" jika bukan.
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan             Keluaran
 * 1.  3                   YA
 *     1 3 5
 *     5
 *     1 2 3 4 5
 * 2.  2                   TIDAK
 *     3 1
 *     3
 *     1 2 3
 * 3.  0                   YA
 *     3
 *     1 2 3
 * 4.  2                   TIDAK
 *     1 1
 *     1
 *     1
 *
 * Hint: ada dua basis: A kosong (berarti cocok) dan B kosong sementara
 *       A belum kosong (berarti tidak cocok). Jika head(a) = head(b), kedua
 *       list maju bersama; jika tidak, hanya B yang maju
 */
boolean isSubsequence(List a, List b) {
    /* KAMUS LOKAL
     *
     * (tidak ada variabel lokal yang wajib)
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    return false;
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

    if (isSubsequence(a, b)) {
        printf("YA\n");
    } else {
        printf("TIDAK\n");
    }
    return 0;
}
