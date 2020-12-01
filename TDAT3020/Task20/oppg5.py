def sig(K, x, k):
    alpha, p, beta, a = K
    gamma = pow(alpha, k, p)
    k_invers = pow(k, p-3, p-1)
    delta = (x-(a*gamma)%(p-1))*(k_invers)%(p-1)
    return (gamma, delta)

def ver(K, x, signert):
    alpha, p, beta, _ = K
    gamma, delta = signert
    return (pow(beta, gamma, p)*pow(gamma, delta, p))%p == pow(alpha, x, p)


if __name__ == '__main__':
    k = 3
    alpha, a, p, beta = 13, 15, 37, 29
    K = (alpha, p, beta, a)
    print("\nOppg1")
    print("Offentlig: alpha={:3}  p={:3}  beta={:3}\nPrivat: a={:3}"
        .format(alpha, p, beta, a))
    print("\nOppg2")
    meldinger = [14, 3]
    k = [11, 5]
    for i, _ in enumerate(meldinger):
        signatur = sig(K, meldinger[i], k[i])
        verifisert = ver(K, meldinger[i], signatur)
        print("melding: {}  k: {}  signatur: {}  verifisert: {}"
            .format(meldinger[i], k[i], signatur, verifisert))
    print("\nOppg3")
    meldinger = [32, 9]
    signaturer = [(19,6), (32,16)]
    for i, _ in enumerate(meldinger):
        verifisert = ver(K, meldinger[i], signaturer[i])
        print("mld: {}  signatur: {}  verifisert: {}"
        .format(meldinger[i], signaturer[i], verifisert))