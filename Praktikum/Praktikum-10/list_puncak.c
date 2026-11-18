#include "list_puncak.h"

List ambilPuncak(List l) {
    if (isEmpty(l) || isOneElmt(l) || isOneElmt(tail(l))) {
        return NIL;
    }
    List hasil = ambilPuncak(tail(l));
    ElType kiri = head(l);
    ElType tengah = head(tail(l));
    ElType kanan = head(tail(tail(l)));
    if (tengah > kiri && tengah > kanan) {
        hasil = konso(tengah, hasil);
    }
    return hasil;
}
