a)
    
    eK(x1)eK(x2) mod n = eK(x1x2) mod n

b)
Vis hvordan RSA er usikker mot valgt chiffertekst-angrep: 
Gitt en chiffertekst y, beskriv hvordan en angriper kan velge chiffertekst y′ ̸= y, 
slik at kjennskap til klarteksten x′ = dK(y′) lar ham beregne x = dK(y)

    y * y´ = eK(x)eK(x´) (mod n) = 1
    Dette virker bare hvis gcd(y´, n) = 1, hvis den ikke blir 1 så er en av disse mulig:
        gcd(y´,n) = p eller gcd(y´,n) = q
    Begge disse er nyttige for en angriper for da å bruke p eller q til å faktorisere n for å finne den private nøkkelen.
    Hvis vi da ser nærmere på gcd(y´,n) = 1, som tilsier at en multiplikativ invers av y´ (mod n) finnes.
    Hvis vi da bruker den multiplikative inversen av y (mod n) som valgt chiffertekst kan vi skrive:
        y * y´ = eK(x) * eK(x´) (mod n) = eK(x*x´ (mod n)) = 1
    Gitt krypteringsregelen til RSA: eK(x) = x^b (mod n) kan vi skrive om den forrige ligningen til:
        (x * x´)^b ≡ 1 (mod n)
    Basert på at 1^b = 1 (mod n), og at x =/= 0 får vi at:
        x * x´ ≡ 1 (mod n)