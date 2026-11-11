#include "RentetanAnomali.h"

List tail(List l) {
    return l->next;
}

int rentetanRekursif(List l, int batas, int count, int max) {
    if (isEmpty(l)) {
        return max;
    } else {
        if (INFO(l) > batas) {
            count++;

            if (count > max) {
                max = count;
            }
        } else {
            count = 0;
        }

        return rentetanRekursif(tail(l), batas, count, max);
    }
}

int rentetanTerpanjang(List l, int batas) {
    return rentetanRekursif(l, batas, 0, 0);
}
/* Menghitung panjang rentetan sinyal berbahaya terpanjang secara rekursif.
   I.S. l terdefinisi, mungkin kosong.
   F.S. Mengembalikan panjang maksimum deretan node berturut-turut dengan INFO > batas.
        Hasilnya 0 jika l kosong atau tidak memiliki sinyal berbahaya.
        List tidak berubah dan tidak ada node yang dialokasikan atau didealokasi.
        Tidak membaca masukan atau mencetak keluaran.
   Gunakan rekursi tanpa loop; fungsi bantuan rekursif boleh dibuat. */
