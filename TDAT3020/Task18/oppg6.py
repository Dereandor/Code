import math
from math import sqrt

n = 152416580095517

k = 0

x = math.ceil(math.sqrt(n)) + k
print(x)
d = math.sqrt((x**2) - n)
print(d)

q = 12345713
p = 12345709

y = (((p+q)/2)**2) - d**2

print(y)

print("done")