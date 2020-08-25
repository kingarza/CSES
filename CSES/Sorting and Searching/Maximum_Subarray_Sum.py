
n = int(input())
ar = list(map(int, input().split())) 

inicio = min(ar)
fin = max(ar)

Min = 1000000001
val = -1

def f(x):
    c = 0
    for i in ar:
        c += abs(i - x)
    return c

while inicio <= fin:
    mitad = (inicio + fin) // 2
    cuanto = f(mitad)
    if cuanto < Min:
        Min = cuanto
        val = mitad
        fin = mitad - 1
    else:
        inicio = mitad + 1

print(f(val))

-----------
servicios
-----------
masaje de relajación
masaje con aromaterapia
masaje shiat-su
masaje descontracturante
faciales
-----------
venta de productos
-----------
jabones
cremas
aceites

