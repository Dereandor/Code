Oppgave 5

En (dårlig) variant av AES er nesten som AES: Den har samme blokkstørrelse på 128 bits, samme nøkkellengde på 128 bits, og utfører følgende
tre trinn som i AES, men bare en gang:

• ADDROUNDKEY (original nøkkel) (XOR mellom nøkkel og melding)
• SUBBYTES (Bruk en tabell til å bytte ut hver byte: https://en.wikipedia.org/wiki/Rijndael_S-box)
• SHIFTROWS (Sett opp en 4x4 matrise for meldingen, der du shifter rad 2 én mot venstre, rad 3 to mot venstre og rad 4 tre mot venstre)

NB! Første rundenøkkel er samme som original nøkkel. Ingen XOR på slutten.

Bruk nøkkelen
67 71 35 c4 ff da e5 ff 1c 54 e1 fd 7f 2e 88 b7

a) Krypter meldingen 24 59 66 0c 99 da 9b 00 d6 55 fd 20 e9 ff 46 95

    ADDROUNDKEY:
    43 28 53 c8 66 00 7e ff ca 01 1c dd 96 d1 ce 22
    SUBBYTES:
    1a 34 ed e8 33 63 f3 16 74 7c 9c c1 90 3e 8b 93
    SHIFTROWS:
    1a 33 74 90     1a 33 74 90
    34 63 7c 3e     63 7c 3e 34
    ed f3 9c 8b     9c 8b ed f3
    e8 16 c1 93     93 e8 16 c1

    ENCRYPTED MESSAGE:
    1a 63 9c 93 33 7c 8b e8 74 3e ed 16 90 34 f3 c1

b) Dekrypter meldingen 26 FA 83 E7 2D CD 5D B8 C4 DC EB 12 70 CF D6 1E

    REVERSE SHIFTROW:
    26 2d c4 70     26 2d c4 70
    fa cd dc cf     cf fa cd dc
    83 5d eb d6     eb d6 83 5d
    e7 b8 12 1e     b8 12 1e e7

    26 cf eb b8 2d fa d6 12 c4 cd 83 1e 70 dc 5d e7
    
    REVERSE SUBBYTES:
    23 5f 3c 9a fa 14 4a 39 88 80 41 e9 d0 93 8d b0

    REVERSE ADDROUNDKEY:
    44 2e 09 5e 05 ce af c6 94 d4 a0 14 af bd 05 07

    DECRYPTED MESSAGE:
    44 2e 09 5e 05 ce af c6 94 d4 a0 14 af bd 05 07