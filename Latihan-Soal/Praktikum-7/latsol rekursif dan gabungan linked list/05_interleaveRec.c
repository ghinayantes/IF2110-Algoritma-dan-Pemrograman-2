/* File: interleaveRec.c */
/* Menyisipkan selang-seling dua linked list secara rekursif */

#include "listlinier.c"
#include <stdio.h>
#include <stdlib.h>

/*
 * CERITA
 * Dua barisan penari berbaris di panggung: barisan merah dan barisan
 * biru. Koreografer ingin menggabungkan keduanya menjadi satu barisan
 * dengan pola selang-seling: satu penari merah, satu penari biru, satu
 * penari merah, dan seterusnya. Jika salah satu barisan lebih panjang,
 * sisa penarinya berdiri berurutan di bagian akhir.
 *
 * TUGAS
 * Implementasikan fungsi interleaveRec yang menggabungkan l1 dan l2
 * secara selang-seling (mulai dari l1) dengan cara relink node secara
 * rekursif, dan mengembalikan alamat node pertama hasil.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while. Tidak ada
 * alokasi/dealokasi node.
 *
 * I.S.  : l1 dan l2 terdefinisi, mungkin kosong
 * F.S.  : mengembalikan list hasil selang-seling. Setelah pemanggilan, l1 dan l2
 *         tidak boleh dipakai lagi (cara pemakaian: l3 = interleaveRec(l1, l2);)
 *
 * Contoh:
 * interleaveRec([1,3,5], [2,4,6,8,10]) = [1,2,3,4,5,6,8,10]
 * interleaveRec([1,3], [2])            = [1,2,3]
 * interleaveRec([1,2], [])             = [1,2]
 * interleaveRec([], [7,8])             = [7,8]
 * interleaveRec([], [])                = []
 *
 * Hint: basis adalah salah satu list kosong. Pada rekurens, ambil node
 *       pertama l1, lalu sisa l1 dan SELURUH l2 digabung dengan peran yang
 *       ditukar (l2 menjadi yang diambil pertama)
 */
List interleaveRec(List l1, List l2) {
    /* KAMUS LOKAL
     *
     * (tidak ada variabel lokal yang wajib)
     */

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }

    NEXT(l1) = interleaveRec(l2, NEXT(l1));
    return l1;
}

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

int main() {
    List l1, l2;
    CreateList(&l1);
    insertLast(&l1, 1);
    insertLast(&l1, 3);
    insertLast(&l1, 5);
    CreateList(&l2);
    insertLast(&l2, 2);
    insertLast(&l2, 4);
    insertLast(&l2, 6);

    displayListRec(interleaveRec(l1, l2));
    return 0;
}