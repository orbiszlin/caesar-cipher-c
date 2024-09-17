# Caesarova šifra v jazyce `C`

Caesarova šifra je jednoduchou substituční šifrou, jejíž princip spočívá v posunu každého písmene otevřeného textu o
konstantní počet míst v abecedě. Ačkoliv se v době Julia Caesara používala jen varianta posunu o 3 písmena, tak název se
Caesarova šifra používá pro všechny varianty tohoto šifrovacího systému.

[Informace jak funguje tato šifra](https://www.algoritmy.net/article/34/Caesarova-sifra)

## Princip `encrypt` vysvětlený na jednom pismenu

Tento princip využívá pouze velká písmena A-Z, lze však to samé použít u malých písmen. Ukázka je vysvětlena na jednom
písmenu a rozebraná po jednotlivých krocích co algoritmus dělá.

> Tato varianta nepočítá s mezerou

```c
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

// ukázka změněného písmena pro kontrolu
printf("%c", ch);
```

## Princip `decryp` vysvětlený na jednom pismenu

`decrypt` funguje stejně jako `encrypt`, jen místo `+ shift` používáme `- shift`, mínus docílí obráceného efektu.
Jelikož bychom se dostali do mínusových čásel tedy `< 0`, musíme přičíst ještě `+ 26`.

```c
// vysvětlení funkce
char ch = 'Z'; // Písmeno které budu posouvat
int shift = 5; // o kolik budu posouvat písmeno

// počítám s čísly A = 65 v ASCI, Z = 90
// 90 - 65 - 5 + 26 => 46
printf("%d\n", (ch - 'A' + shift + 26));

// % modulu použiji pro rotaci uvnitř A - Z, tedy 0 - 25 (pro jednodušší práci došlo k posnunu, bylo "- A", tedy "- 65")
// % 26 je proto, že je 26 písmen, pozice 0-25
// (90 - 65 - 5 + 26) % 26 => 20
printf("%d\n", ((ch - 'A' - shift + 26) % 26));

// protože jsem posunul čísla první na 0-25 (skrze jednodušší rotaci Z - A), musím znovu odečtené A přičíst, proto je na konci "+ A"
// (90 - 65 - 5 + 26) % 26 + 65 => 85
printf("%d\n", (ch - 'A' - shift + 26) % 26 + 'A');

// Ukázka rozebraných částí uvnitř jednoho řádku
ch = (ch - 'A' - shift + 26) % 26 + 'A';

// ukázka změněného písmena pro kontrolu
printf("%c", ch);
```