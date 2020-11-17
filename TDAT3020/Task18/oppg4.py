  
from math import gcd
import numpy as np

def pollard_rho(n, x1, f):
    x = np.zeros(100000, dtype='int')
    x[0] = x1
    x[1] = f(x[0],n)
    d = gcd(x[1]-x[0],n)
    i = 2
    iterasjon = 1
    while d == 1:
        x[i] = f(x[i-1],n)
        x[i+1] = f(x[i],n)
        i+=2
#        print(x[i-1])
        d = gcd(x[i-1]-x[i//2-1],n)
        iterasjon+=1
    if(d==n): return('failure');
    else: return d, iterasjon;

def f(x,n):
    return (x**2+1) % n

if __name__ == '__main__':
    n = [851, 1517, 31861]
    x1 = 1
    for _n in n:
        print(pollard_rho(_n,x1,f))