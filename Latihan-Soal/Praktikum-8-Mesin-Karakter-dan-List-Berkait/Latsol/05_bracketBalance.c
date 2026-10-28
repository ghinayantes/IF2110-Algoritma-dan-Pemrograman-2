/* Nama File: bracketbalance.c */
/* Kompilasi: gcc 05_bracketBalance.c mesinkarakter.c listlinier.c -o bb */

#include "mesinkata.c"
#include "mesinkarakter.c"
#include "listlinier.c"
#include "boolean.h"
#include <stdio.h>

/*
 * CERITA
 * Seorang asisten dosen sedang memeriksa ratusan ekspresi matematika
 * mahasiswa. Ia hanya ingin memastikan satu hal: apakah semua tanda kurung
 * ( ), [ ], dan { } sudah berpasangan dengan benar, yaitu setiap kurung buka
 * ditutup oleh kurung tutup sejenis, dengan urutan yang tidak saling menyilang.
 *
 * TUGAS
 * Anda diberikan sebuah pita karakter berisi ekspresi yang diakhiri MARK '.'
 * (yang bukan bagian dari ekspresi). Karakter selain kurung ( ) [ ] { }
 * diabaikan. Tentukan apakah kurung pada ekspresi seimbang.
 * Gunakan sebuah linked list (listlinier.h) sebagai tumpukan (stack):
 * kurung buka masuk dari depan list (insertFirst), dan kurung tutup
 * dicocokkan dengan elemen terdepan list (deleteFirst).
 *
 * Format Masukan:
 * - Satu baris berisi karakter ekspresi (huruf, angka, operator, spasi, atau
 *   kurung), diakhiri MARK '.' (1 <= panjang <= 1000).
 *
 * Format Keluaran:
 * - Cetak "SEIMBANG" jika kurung seimbang, atau "TIDAK SEIMBANG" jika tidak.
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan            Keluaran        Keterangan
 * 1.  ([]{}).            SEIMBANG
 * 2.  ([)].              TIDAK SEIMBANG  urutan menyilang
 * 3.  ((.                TIDAK SEIMBANG  ada kurung buka yang tidak ditutup
 * 4.  )(.                TIDAK SEIMBANG  kurung tutup muncul lebih dulu
 * 5.  a*(b+c)-{d}.       SEIMBANG        karakter lain diabaikan
 * 6.  xyz.               SEIMBANG        tidak ada kurung sama sekali
 *
 * Catatan:
 * - Pastikan setiap output diakhiri oleh endline ("\n")!
 * - Gunakan ADT mesin karakter (START, ADV, currentChar, EOP).
 * - Karakter dapat disimpan pada list bertype int (ElType = int) apa adanya.
 *
 * Hint: tiga hal yang membuat tidak seimbang: (1) kurung tutup ditemui saat
 *       tumpukan kosong, (2) kurung tutup tidak sejenis dengan kurung buka
 *       teratas, (3) pita habis tetapi tumpukan masih berisi
 */
boolean isBalanced() {
    List st;
    boolean ok = true;
    ElType top;

    CreateList(&st);

    START();
    while (!EOP && ok) {
        if (currentChar == '(' || currentChar == '{' || currentChar == '[') {
            /* kurung buka: push */
            insertFirst(&st, currentChar);
        } else if (currentChar == ')' || currentChar == '}' || currentChar == ']') {
            /* kurung tutup: harus cocok dengan teratas */
            if (st != NULL && ((INFO(st) == '(' && currentChar == ')') ||
                               (INFO(st) == '{' && currentChar == '}') ||
                               (INFO(st) == '[' && currentChar == ']'))) {
                deleteFirst(&st, &top);
            } else {
                ok = false;     /* tumpukan kosong atau tidak sejenis */
            }
        }
        /* karakter lain: diabaikan */
        ADV();
    }

    if (st != NULL) ok = false; /* pita habis, masih ada kurung buka */
    return ok;
}
