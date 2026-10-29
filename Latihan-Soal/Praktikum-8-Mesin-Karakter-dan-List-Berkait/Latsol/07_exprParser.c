/* Nama File: exprparser.c */
/* Kompilasi: gcc 07_exprParser.c mesinkata.c mesinkarakter.c -o ep */

/* Grammar yang digunakan:
 * <Ekspresi> ::= <Operand> { <Operator> <Operand> }*
 * <Operand>  ::= angka (satu atau lebih digit 0-9) ATAU variabel (satu atau lebih huruf A-Z/a-z)
 * <Operator> ::= "+" | "-" | "*" | "/"
 *
 * Setiap token dipisahkan oleh satu atau lebih spasi. Pita diakhiri MARK '.'.
 *
 * Contoh ekspresi valid:
 * - "3 + 4 * 2."
 * - "x * 12 - y."
 * - "7."
 *
 * Contoh ekspresi tidak valid:
 * - "3 + ."       (berakhir dengan operator)
 * - "+ 3."        (diawali operator)
 * - "3 4."        (dua operand berurutan)
 * - "3 ++ 4."     (bukan operator yang dikenal)
 * - "a1 + 2."     (operand campuran huruf dan angka)
 * - "."           (tidak ada token sama sekali)
 */

#include "mesinkata.c"
#include "mesinkarakter.c"
#include "boolean.h"
#include <stdio.h>

/* ====== FSM Parser ====== */
typedef enum {
    S_EXPECT_FIRST_OPERAND = 0,
    S_EXPECT_OPERATOR_OR_END,
    S_EXPECT_OPERAND,
    S_INVALID
} State;

/*
 * CERITA
 * Seorang mahasiswa membuat kalkulator sederhana dan ingin memastikan
 * ekspresi yang diketik pengguna sesuai tata bahasa sebelum dihitung.
 * Bantulah ia membuat pemeriksa ekspresi dengan mesin kata.
 *
 * TUGAS
 * Anda diminta mengimplementasikan grammar parser untuk memeriksa apakah
 * sebuah ekspresi (dibaca dari stdin dengan mesin kata) valid terhadap
 * grammar di atas. Parser disarankan dibuat dengan state transition / FSM.
 *
 * Format Masukan:
 * - Satu baris berisi token-token ekspresi dipisahkan whitespace(s),
 *   diakhiri MARK '.' (0 <= jumlah token <= 1000).
 *
 * Format Keluaran:
 * - Cetak 1 jika ekspresi valid sesuai grammar, atau 0 jika tidak valid.
 *
 * Contoh Masukan dan Keluaran:
 * No  Masukan            Keluaran
 * 1.  3 + 4 * 2.         1
 * 2.  x * 12 - y.        1
 * 3.  7.                 1
 * 4.  3 + .              0
 * 5.  + 3.               0
 * 6.  3 4.               0
 * 7.  3 ++ 4.            0
 * 8.  a1 + 2.            0
 * 9.  .                  0
 *
 * Catatan:
 * - Pastikan setiap output diakhiri oleh endline ("\n")!
 * - Gunakan ADT mesin kata dan mesin karakter.
 * - Hati-hati: pada state S_INVALID, mesin kata tetap harus dimajukan
 *   (ADVWORD) atau keluar dari loop dengan break. Jika tidak, program
 *   berputar tanpa henti.
 *
 * Hint:
 *   S_EXPECT_FIRST_OPERAND   : token wajib operand -> S_EXPECT_OPERATOR_OR_END
 *   S_EXPECT_OPERATOR_OR_END : token wajib operator -> S_EXPECT_OPERAND
 *   S_EXPECT_OPERAND         : token wajib operand -> S_EXPECT_OPERATOR_OR_END
 *   Ekspresi valid jika pita habis dan state terakhir adalah S_EXPECT_OPERATOR_OR_END
 */

/* isOperator: true jika w adalah tepat satu karakter dari + - * / */
boolean isOperator(Word w) {
    /* KAMUS LOKAL
     * c : char
     */
    char c;

    /* ALGORITMA */
    if (w.Length != 1) return false;           /* "++" panjangnya 2, langsung ditolak */
    c = w.TabWord[0];
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

/* isOperand: true jika w seluruhnya digit (angka) ATAU seluruhnya huruf (variabel),
 * minimal satu karakter */
boolean isOperand(Word w) {
    /* KAMUS LOKAL
     * i        : int
     * allDigit : boolean {true selama semua karakter digit}
     * allAlpha : boolean {true selama semua karakter huruf}
     * c        : char
     */
    int i;
    boolean allDigit = true, allAlpha = true;
    char c;

    /* ALGORITMA */
    if (w.Length == 0) return false;
    for (i = 0; i < w.Length; i++) {
        c = w.TabWord[i];
        if (!(c >= '0' && c <= '9')) allDigit = false;
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) allAlpha = false;
    }
    return (allDigit || allAlpha);             /* "a1" gagal di keduanya */
}

int expr_parser() {
    /* KAMUS LOKAL
     *
     * currState : State {state FSM saat ini}
     */
    State currState = S_EXPECT_FIRST_OPERAND;

    /* ALGORITMA */
    STARTWORD();
    while (!EndWord && currState != S_INVALID) {
        switch (currState) {
            case S_EXPECT_FIRST_OPERAND:
            case S_EXPECT_OPERAND:
                if (isOperand(currentWord)) currState = S_EXPECT_OPERATOR_OR_END;
                else currState = S_INVALID;
                break;
            case S_EXPECT_OPERATOR_OR_END:
                if (isOperator(currentWord)) currState = S_EXPECT_OPERAND;
                else currState = S_INVALID;
                break;
            default:
                break;
        }
        ADVWORD();
    }
    return (currState == S_EXPECT_OPERATOR_OR_END) ? 1 : 0;
}

int main(void) {
    printf("%d\n", expr_parser());
    return 0;
}
