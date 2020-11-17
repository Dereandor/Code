p = 263
q = 401

n = p * q
print(n)

e_n = 104800

e = 23

print(e_n ** e)

def sqr_n_mult(x,c,n):
    z = 1
    l = bin(c)[2:]
    for i in range(len(l)):
        z = z ** 2
        if (l[i:i+1] == '1'):
            z = z * x
    return z % n