from math import gcd,factorial

def pollard_Pminus1(n,B):
    a = 2
    for j in range(2,B+1):
        a = (a ** j) % n
    d = gcd(a-1,n)
    if 1 < d < n:
        return d
    else:
        return "failure"
# ====================

n = 1829
B = 5
print("Oppgave 3 a):\npollard_Pminus1({},{}) = {}\n".format(n,B,pollard_Pminus1(n,B)))

# ====================
n_1 = 18779
n_1B = 211
n_2 = 42583
n_2B = 439
print("Oppgave 3 b):\nn_1 = {}\nn_1B = {}".format(n_1,n_1B))
print("Setter B til høyeste faktor og regner 2^B! (mod n)\na = 2^B! (mod n) \
= 2^{}! (mod {}) = ".format(n_1B,n_1,), end="")
a = 2
for i in range(2,n_1B): a = (a ** i) % n_1
print(a)
print("2^B! ≡ 2^(p-1)*noe ≡ (2^(p-1))^noe ≡ (2^ø(p))^noe ≡ 1 (mod p)")
print("2^B! ≡ 2^(p-1)*noe ≡ (2^(p-1))^noe ≡ (2^ø(p))^noe ≡ 1 (mod p)")

for B in range(2,20):
    if pollard_Pminus1(n_1,B) != 'failure': print(B);break
for B in range(2,20):
    if pollard_Pminus1(n_2,B) != 'failure': print(B);break


# ====================
n = 6319
print("\nOppgave 3 c):\nn = {}\nFinner B, starter på 4:\n".format(n))
for B in range(4,100):
    print("B = {}".format(B))
    a = 2
    for j in range(2,B+1):
        print("{}^{} % {} = ".format(a,j,n),end="")
        a = (a ** j) % n
        print(a)
    print("gcd({}-1,{}) = {} => ".format(a,n,gcd(a-1,n)),end="")
    d = gcd(a-1,n)
    if 1 < d < n:
        print("Treff! B = {}".format(B))
        break
    else:
        print("Fant ingen faktor, prøver neste B\n")