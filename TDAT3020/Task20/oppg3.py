from math import sqrt,ceil

def DLP(p, alpha, beta):
    m = int(ceil(sqrt(p)))
    L1 = []
    L2 = []
    for j in range(0,m):
        value = pow(alpha,m * j,p)
        L1.append((j,value))
    for i in range(0,m):
        value = (beta * pow(alpha,p-i-1,p)) % p
        L2.append((i,value))

    L1.sort(key=lambda x:x[0])
    L2.sort(key=lambda x:x[0])

    j, i = 0, 0
    for a, pair1 in enumerate(L1):
        for b, pair2 in enumerate(L2):
            if pair1[1] == pair2[1]:
                j, i = a, b
                #print("L1: {}  L2: {}".format(j,i))
                break

    return L1, L2, (m*j + i) % p

if __name__ == '__main__':
    alpha = 6
    beta = 3
    p = 41

    L1, L2, logaB = DLP(p, alpha, beta)
    print("L1: {}\nL2: {}\nLog(alpha) beta: {}".format(L1, L2, logaB))