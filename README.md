# Estructura-de-Datos
Despues de copiar y pegar el codigo se utiliza de la siguiente manera:

Al correr el codigo aparecera una representacion grafica del tablero de ajderez de la sigueinte manera:
  a b c d e f g h
8 R N B Q K B N R 8
7 P P P P P P P P 7
6                 6
5                 5
4                 4
3                 3
2 p p p p p p p p 2
1 r n b q k b n r 1
  a b c d e f g h

R/r (Torres)
N/n (Caballos)
B/b (Alfiles)
Q/q (Reinas)
K/k (Reyes)
P/p (Peones)

las letras minusculas son las blancas y las mayusculas las negras.

Una vez aparecido el tablero continuara el siguiente mensaje: "Ingrese movimiento (ejemplo: e2e4) o 'q' para salir:"

El primer conjunto de letra y numero determina la casilla que deseas seleccionar, ejemplo el e2 que viendo el tablero esta seleccionando el peon que se encuentra enfrente del rey.
El segundo conjunto de letra y numero determina la casilla destino, ejemplo e4 moviendo el peon 2 espacios hacia delante.
Por lo tanto si ingresamos e2e4 quedaria de esta manera:
  a b c d e f g h
8 R N B Q K B N R 8
7 P P P P P P P P 7
6                 6
5                 5
4         p       4
3                 3
2 p p p p   p p p 2
1 r n b q k b n r 1
  a b c d e f g h

El codigo permite iniciar primero a cualquier lado ya sea blancas o negras.
