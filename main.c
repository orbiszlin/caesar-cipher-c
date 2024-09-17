#include <stdio.h>
#include "caesar.h"

int main(void) {
    /*
    // vysvětlení funkce
    char ch = 'Z'; // Písmeno které budu posouvat
    int shift = 5; // o kolik budu posouvat písmeno

    // počítám s čísly A = 65 v ASCI, Z = 90
    // 90 - 65 + 5 => 30
    printf("%d\n", (ch - 'A' + shift));

    // % modulu použiji pro rotaci uvnitř A - Z, tedy 0 - 25 (pro jednodušší práci došlo k posnunu, bylo "- A", tedy "- 65")
    // % 26 je proto, že je 26 písmen, pozice 0-25
    // (90 - 65 + 5) % 26 => 4
    printf("%d\n", ((ch - 'A' + shift) % 26));

    // protože jsem posunul čísla první na 0-25 (skrze jednodušší rotaci Z - A), musím znovu odečtené A přičíst, proto je na konci "+ A"
    // (90 - 65 + 5) % 26 + 65 => 69
    printf("%d\n", (ch - 'A' + shift) % 26 + 'A');

    // Ukázka rozebraných částí uvnitř jednoho řádku
    ch = (ch - 'A' + shift) % 26 + 'A';

    // alternativa pokud se jedná o pole a chci vykonat akce na jednom řádku
    // text[i] = (text[i] - 'A' + shift) % 26 + 'A';

    // ukázka změněného písmena pro kontrolu
    printf("%c", ch);
    */

    char text[] = "AhOj toto je zprava";
    printf("%s", text);
    encrypt(text, 5);
    printf("\n%s", text);
    decrypt(text, 5);
    printf("\n%s", text);
    return 0;
}

