crossing = node
street = edge


# nota eficiencia:
    cuando k == i OR k == j, descartar iteracion, SIEMPRE sera falsa

# nota funcionamiento:
    la matriz siempre sera un espejo, which means to mirror it at building time
    para implementar en wicho: para sumar, lo cambias a un MAX(a, b)
    si el lado derecho de la desigualdad es inf, NO ES POSIBLE
    si al final del algo la distancia es inf, no path

#design triangle
    en cada acceso a matrix[x][y]:
        y NO puede ser MAYOR a x

#innermost for: 
    for j from 1 to i

    1 2 3
    2 3 6
    3 1 3

    0   3   
        0   6
    3       0


    i = 3 
    j = 1
    k = 2

    i,j < i,k + k,j

    3,1, < 3,2 + 2,1
    inf < inf + 4