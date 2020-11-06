Oppgave 6
Gitt følgende 128-bits AES-nøkkel, i heksadesimal notasjon,
    2B7E1516 28AED2A6 ABF71588 09CF4F3C
Kjør KEYEXPANSION, begrenset som følger:
    • Bare de første 6 ordene, w[0], ..., w[5]
    • Ikke bruk SUBWORD.
Algoritmen jobber med 32-bits ord, og hver heksadesimale tegn er 4 bits.

    W_0 = 2b7e1516
    W_1 = 28aed2a6
    W_2 = abf71588
    W_3 = 09cf4f3c

    Skjønner ikke helt hvordan jeg skal utføre AES uten SUBWORD, er ikke denne en essensiell del av prossessen?
    Skal man da gjøre kun RotWord mellom hver? siden rcon og xor rcon avhenger av subword?
    Eller XOR RotWord kolonnen med RC kolonnen for å få W_4? Dette fører jo da til mye lavere sikkerhet?
    Prøver å demonstrere det siste alternativet (RotWord XOR Rcon)

    RW = RotWord
    RC = RoundConstant
    XR = XOR Rcon

    W0  W1  W2  W3  RW  RC  XR  W4  W5 

    2B  28  AB  09  CF  01  CE  E5  CD
    7E  AE  F7  CF  4F  00  4F  31  9F
    15  D2  15  4F  3C  00  3C  29  FB
    16  A6  88  3C  09  00  09  1F  B9
    
