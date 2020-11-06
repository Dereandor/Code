Oppgave 3
Vi definerer en HMAC som følger:
• K = 1001
• ipad = 0011
• opad = 0101
• h er midtkvadratmetoden, dvs. vi regner x^2(mod 2^8) og henter de midterste fire sifrene ^
(skriv ut tallet med 8 bits, med ledende nuller hvis det trengs)

a) Finn HMAC til meldingen 0110
    
    h((1001 XOR 0101)||h((1001 XOR 0011)||0110))

    h(1100||h(1010||0110))

    h(1100||h(10100110))
    
    h(11000100)

    0100


    

b) Du mottar meldingen 0111 og HMAC 0100. Er det grunn til å tro at
meldingen ikke er autentisk?

    hvis vi tar utgangspunkt i ipad og opad fra forrige oppgave så har vi grunn til å mistenke dette siden vi får samme hmac fra annen melding.