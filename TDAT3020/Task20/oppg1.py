print("Orden:\n   1         2         3         4         5         6         7         8\
         9         10")
Z = 11
for i in range(1,Z):
    res = 0
    j = 1
    while res != 1:
        res = pow(i,j,Z)
        print("{}^{} = {} | ".format(i,j,res), end="")
        j += 1
    print()

def finn(base, tall , p):
    res = 0
    for i in range(1,p):
        res = pow(base,i,p)
        if res == tall:
            return i
    return -1

