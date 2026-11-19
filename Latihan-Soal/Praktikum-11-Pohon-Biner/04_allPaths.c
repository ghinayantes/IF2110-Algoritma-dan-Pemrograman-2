/* Nama File: allpaths.c */
/* Kompilasi: gcc 04_allPaths.c -o allpaths */

#include "bintree.h"
#include <stdio.h>

/*
 * CERITA
 * Sebuah gedung memiliki lorong yang bercabang dua pada setiap ruangan
 * (kiri dan kanan). Petugas keselamatan ingin membuat daftar semua jalur
 * evakuasi, yaitu setiap jalur dari ruang masuk (akar) sampai ruang
 * ujung (daun), beserta nomor ruangan yang dilalui.
 *
 * TUGAS
 * Implementasikan prosedur rekursif printPaths yang mencetak SEMUA jalur
 * dari akar sampai daun pohon p, satu jalur per baris, dengan format
 * a->b->c. Jalur dicetak berurutan dari daun paling kiri sampai paling kanan.
 * Parameter path adalah array penampung nomor ruangan pada jalur yang
 * sedang dibentuk, dan len adalah banyaknya nomor yang sudah terisi
 * pada path sebelum memproses p.
 *
 * ATURAN: dilarang memakai while, for, maupun do-while untuk menelusuri pohon
 * (penelusuran harus rekursif). Pencetakan satu jalur boleh memakai
 * pengulangan (misalnya for) atau rekursi.
 *
 * I.S.  : p terdefinisi, mungkin kosong. path memiliki ruang minimal sebanyak
 *         tinggi pohon. len = 0 pada pemanggilan pertama
 * F.S.  : semua jalur akar-daun tercetak. Pohon kosong tidak mencetak apa pun
 *
 * Format Masukan:
 * - Satu baris berisi pohon dalam urutan PREFIX dengan 0 sebagai subpohon
 *   kosong. Banyak node paling banyak 100.
 *
 * Format Keluaran:
 * - Satu baris untuk setiap jalur. Tidak ada keluaran jika pohon kosong.
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan                      Keluaran
 * 1.  1 2 4 0 0 5 0 0 3 0 0        1->2->4
 *                                  1->2->5
 *                                  1->3
 * 2.  7 0 0                        7
 * 3.  0                            (tidak ada keluaran)
 * 4.  1 0 2 0 0                    1->2
 *     (akar 1, hanya anak kanan 2)
 * 5.  1 2 0 0 0                    1->2
 *     (akar 1, hanya anak kiri 2)
 *
 * Catatan:
 * - Pastikan setiap output diakhiri oleh endline ("\n")!
 * - Node yang hanya punya satu anak BUKAN daun, jadi jalur tidak berhenti di sana.
 *
 * Hint: isi path[len] dengan akar p, lalu jika p adalah daun cetak jalurnya
 *       (path[0..len]), jika bukan lanjutkan ke anak kiri dan anak kanan
 *       dengan len + 1
 */
void printPaths(BinTree p, int path[], int len) {
    /* KAMUS LOKAL
     *
     * (tidak ada variabel lokal yang wajib selain untuk mencetak jalur)
     */
    int i;

    /* ALGORITMA */
    if (isTreeEmpty(p)) {
        return;
    }
    path[len] = ROOT(p);
    if (isLeaf(p)) {
        for (i = 0; i <= len; i++) {
            if (i > 0) {
                printf("->");
            }
            printf("%d", path[i]);
        }
        printf("\n");
    } else {
        printPaths(LEFT(p), path, len + 1);
        printPaths(RIGHT(p), path, len + 1);
    }
}

int main(void) {
    BinTree t = buildTreePrefix();
    int path[101];
    printPaths(t, path, 0);
    return 0;
}
