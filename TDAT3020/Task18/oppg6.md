I denne oppgaven skal vi se på måte å angripe RSA på, hvis differansen q −p
er liten. Anta q > p > 2, dvs. begge primtallene er oddetall.

a) Forklar hvorfor vi kan skrive q − p = 2d, hvor d er et heltall (dvs. at
q − p er et partall. Det er ikke noe spesielt med d.)

    Hvis vi tar et stort oddetall minus et mindre oddetall får vi alltid et positivt partall, og alle partall kan deles på 2.

b) Vis at n + d^2 er et kvadrattall

    q-p = 2d
    d = (q-p)/2
    d^2 = (q-p)^2/2^2 = (q^2 - 2pq + p^2) / 4
    n + d^2 = pq + (q^2 - 2pq + p^2) / 4
    n + d^2 = (4pq + q^2 - 2pq + p^2) / 4
    = (p^2 + 2pq + q^2) / 4
    = (p + q)^2 / 4
    = { (p + q) / 2 }^2
    Dette blir et perfekt kvadrat.

c) Vis hvordan vi kan faktorisere n hvis n + d^2
er et kvadrattall. Vi antar her at at d^2 er “liten nok”.

    Siden d^2 er liten, kan vi anta at p og q er liten også, så vi kan bruke formelen vi fant i b)
    n = {(q+p)/2}^2 - d^2
    siden det første leddet der er bare litt større enn n, kan vi ta kvadratroten av formelen og runde opp til nærmeste heltall
    deretter kan vi iterere gjennom følgende lgining til den blir kvadratisk i Z
        x = |sqrt(n)| + k for k = 0, 1, 2, ...
    
    Når den blir kvadratisk kan q og p bli funnet ved å kalkulere q = x+d og p = x-d ved å bruke
        d = sqrt(x^2 - n) fra n + d^2 = x^2 der x = (p + q)/2

d) Faktoriser n = 152416580095517 med denne metoden.

    Vi bruker formelen og iterer gjennom k for å finne et heltall
        ceil(sqrt(n)) + 0 = 12345711
    videre bruker vi formelen 
        d = sqrt(12345711^2 - 152416580095517) = 2
    deretter prøver vi å regne ut p og q med d = 2
        q = 12345711 + 2 = 12345713
        p = 12345711 - 2 = 12345709
    Vi sjekker deretter dette ved å regne ut n
        n = {(p+q)/2}^2 - d^2 = 152416580095517 
