def hcf(x,y):
    if (y==0):
        return x
    else:
        return hcf(y,x%y)

a = (11 ** 72)

b = (11 ** 136)

print(hcf(a,10001))

print(hcf(b,10001))