/* Nama File: sortbylength.c */
/* Kompilasi: gcc 06_sortByLength.c mesinkata.c mesinkarakter.c -o sbl */

#include "mesinkata.c"
#include "mesinkarakter.c"
#include "listword.h"
#include <stdio.h>

/*
 * CERITA
 * Seorang penjaga toko buah ingin menyusun papan nama buah berdasarkan
 * panjang nama, dari yang paling pendek sampai yang paling panjang, supaya
 * papan terlihat rapi seperti tangga. Jika dua nama sama panjang, nama
 * yang ditulis lebih dulu pada daftar tetap lebih dulu.
 *
 * TUGAS
 * Anda diberikan sebuah sekuens kata dipisahkan satu atau lebih spasi dan
 * diakhiri MARK '.'. Baca kata satu per satu, dan setiap kata langsung
 * disisipkan pada posisi yang tepat pada sebuah linked list (listword.h)
 * sehingga list selalu terurut menaik berdasarkan panjang kata
 * (insertion pada list terurut, bukan mengurutkan di akhir).
 * Setelah semua kata terbaca, cetak isi list.
 *
 * Format Masukan:
 * - Satu baris berisi n kata dipisahkan whitespace(s), diakhiri MARK '.'
 *   (1 <= n <= 1000, panjang kata <= 50).
 *
 * Format Keluaran:
 * - n baris. Setiap baris berisi sebuah kata, spasi, lalu panjang kata tersebut.
 *   Baris diurutkan menaik berdasarkan panjang kata, kata yang sama panjang
 *   mengikuti urutan kemunculannya pada masukan.
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan                              Keluaran
 * 1.  pisang apel jeruk kiwi anggur.       apel 4
 *                                          kiwi 4
 *                                          jeruk 5
 *                                          pisang 6
 *                                          anggur 6
 * 2.  abc ab a.                            a 1
 *                                          ab 2
 *                                          abc 3
 * 3.  halo.                                halo 4
 *
 * Catatan:
 * - Pastikan setiap output diakhiri oleh endline ("\n")!
 * - Gunakan ADT mesin kata dan mesin karakter.
 * - Dilarang memakai array dan fungsi sort pustaka. Gunakan listword.h.
 */

/* insertByLength: menyisipkan w pada l yang sudah terurut menaik menurut
 * panjang kata, sehingga l tetap terurut. Jika ada kata dengan panjang yang
 * sama, w diletakkan SETELAH semuanya (agar urutan kemunculan terjaga).
 * I.S. l terurut menaik menurut panjang, mungkin kosong
 * F.S. w berada pada l pada posisi yang tepat */
void insertByLength(WList *l, Word w) {
    /* KAMUS LOKAL
     *
     * p   : WAddress {pointer traversal pencari posisi sisip}
     * new : WAddress {node baru, gunakan newWNode}
     */
    WAddress p = WFIRST(*l);
    WAddress new = newWNode(w);

    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    if (p == NULL) {
        *l = new;
    }
    while (p != NULL) {
        if (w.Length < WINFO(p).Length) {
            WNEXT(new) = p;
            *l = new;
            break;
        }
        else if (WINFO(p).Length <= w.Length && (WNEXT(p) == NULL || (WINFO(WNEXT(p))).Length > w.Length)) {
            if (WNEXT(p) == NULL) {
                WNEXT(p) = new; 
            }
            else {
                WNEXT(new) = WNEXT(p);
                WNEXT(p) = new;
            }
            break;
        }
        else p = WNEXT(p);
    }
}

void sortByLength() {
    /* KAMUS LOKAL
     *
     * l : WList {list kata terurut menurut panjang}
     * p : WAddress {pointer traversal saat mencetak}
     */
    WList l;
    WAddress p;

    CreateWList(&l);

    STARTWORD();
    while (!EndWord) {
        insertByLength(&l, currentWord);
        ADVWORD();
    }
    /* ALGORITMA */
    /* TODO: tulis algoritma di sini */
    p = WFIRST(l);
    while (p != NULL) {
        printWord(WINFO(p));
        printf(" %d\n", WINFO(p).Length);
        p = WNEXT(p);
    }
}

int main(void) {
    sortByLength();
    return 0;
}
