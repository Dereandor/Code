import numpy as np
#a)
def multiplikasjonstabell(k):
    arr = np.zeros((k,k));
    for i in range(k):
        for j in range(k):
            arr[i][j] = (i*j) % k;

    return arr
#b)
def invers(k):
    arr = []
    for a in range(1,k):
        for s in range(1,k):
            if (a*s) % k == 1:
                arr.append(a)
                break
    return arr

#a)
print(multiplikasjonstabell(12))
#b)
print(invers(12))
#c)
#0 og 1 er ekslusive siden for å få 1 må tallet være relativt primisk med N
#mens hvis vi vil ha 0 kan ikke tallet være relativt porimisk med N