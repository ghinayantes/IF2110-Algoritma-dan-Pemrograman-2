#include "BalikPita.h"

List balikList(List l) {
    if(isEmpty(l)) return NIL;
    else {
        List r = balikList(NEXT(l));
        NEXT(l)->next = l;
        NEXT(l) = NIL;
        return r;
    }
}

List bacaPita(void) {
    if(endWord) return NIL;
    int x = kataKeInt(currentWord);
    advWord();
    return makeCons(x, bacaPita());
}

List bacaTerbalik(void) {
    startWord();
    List l = bacaPita();
    return l = balikList(l);
}
/* Membaca pita sampai MARK dan menghasilkan list berisi seluruh bilangan
   pada pita dengan urutan terbalik (bilangan terakhir pada pita menjadi
   elemen pertama list).
   Memanggil startWord sendiri dan tidak mencetak keluaran.
   Setiap kata pada pita adalah bilangan bulat.
   Jika tidak ada kata, hasilnya list kosong.
   I.S. Posisi baca berada di awal pita; pita diakhiri MARK.
   F.S. Semua kata telah diakuisisi (endWord true). */