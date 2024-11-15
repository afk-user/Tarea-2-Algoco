print('funcion:')
funcion = input()
archivo = f"costos/cost_{funcion}.txt"

costoIgual = 0
filas = range(1)

print('cantidad args funcion:')
argumentos = int(input())
if argumentos == 2:
    filas = range(26)
    print('costo si los argumentos son iguales')
    costoIgual = int(input())

print('costo si los argumentos son distintos (o uno solo)')
costoDistinto = int(input())


try:
    with open(archivo, "w") as f:
    # las matrices siempre son 26x26
        for r in filas:
            for c in range(26):
                if c == r and argumentos==2:
                    f.write(str(costoIgual))
                else:
                    f.write(str(costoDistinto))
                if c!=25:
                    f.write(' ')
            f.write('\n')

        print(f"{archivo[7:-4]} generado exitosamente")
except:
    print("Un error ha ocurrido al generar el archivo")