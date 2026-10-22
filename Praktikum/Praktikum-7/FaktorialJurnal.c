#include "FaktorialJurnal.h"
#include <stdio.h>

int faktorial(int n) {
    if (n == 0) return 1;
    return n * faktorial(n-1);
}
/* Menghitung faktorial n secara rekursif.
   I.S. 0 <= n <= 12.
   F.S. Mengembalikan n!, dengan 0! = 1. Tidak mencetak keluaran. */
