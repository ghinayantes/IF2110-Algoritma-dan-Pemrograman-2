#include <stdio.h>
#include "CatatanMebel.h"

int faktorial(int n) {
    if (n == 0) return 1;
    return n * faktorial(n-1);
}

void faktorialP(int n, int *hasil) {
    *hasil = faktorial(n);
}
/* Menghitung faktorial n secara rekursif melalui parameter output hasil.
   I.S. 0 <= n <= 12. hasil menunjuk variabel int yang valid;
        nilai awal variabel tersebut sembarang.
   F.S. *hasil berisi n!, dengan 0! = 1. Tidak mencetak keluaran. */