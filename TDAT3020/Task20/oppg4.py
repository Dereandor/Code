def sig(x, a, n):
    return pow(x, a, n)

def ver(melding, b, n):
    return melding[0]==pow(melding[1],b,n)

def powr(y, b, n):
    return pow(y,b,n)

def knownx(meldinger, n):
    x, y = 1, 1
    for _ in meldinger:
        x = (x*melding[0])%n
        y = (y*melding[1])%n
    return (x,y)
if __name__ == '__main__':
    n, b, p, q, a = 437, 13, 23, 19, 61

    print("\nOppg1")
    meldinger = [(78,394),(123,289)]
    for melding in meldinger:
        print("x:{:4}  y:{:4}".format(melding[0],melding[1]), end="  ")
        print("verification: {}".format(ver(melding,b,n)))

    print("\nOppg2")
    y = 123
    x = powr(y,b,n)
    par = (x,y)
    print("x:{:4}  y:{:4}  ver: {}".format(x, y, ver(par,b,n)))

    print("\nOppg3")
    meldinger = [(38,171),(97,337)]
    ny_melding = knownx(meldinger,n)
    print("Ny melding: {}  verification: {}".format(ny_melding,ver(ny_melding, b, n)))

    print("\nOppg4")
    An, Aa, Ab = 731, 19, 283
    x = 109
    y = sig(x, a, n)
    kryptert = [sig(i, Aa, An) for i in (x, y)]
    print("melding(x):{:4}  signer(y):{:4}  krypter(x,y): {}".format(x, y, kryptert))

    dekryptert = [sig(i, Ab, An) for i in kryptert]
    print("dekrypter: {}  verifiser: {}".format(dekryptert, ver(dekryptert, b, n)))