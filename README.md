# push_swap
Push_swap 42

Metodologia del programa Push_swap
===============================================
//Declara punteros a dos estructuras de datos/listas enlazadas, una para la pila `a` y otra para `b
	//Poner ambos punteros a NULL para evitar comportamientos indefinidos e indicar que empezamos con pilas vacías

//Maneja los errores de recuento de entrada. El número de argumentos debe ser 2 o más, y la segunda entrada no debe estar vacía.
	//Si hay errores de entrada, devuelve error

//Maneja ambos casos de entrada, ya sea un número variable de argumentos de línea de comandos, o como una cadena
	//Si la entrada de números es una cadena, llama a split() para dividir las subcadenas

//Inicializa la pila `a` añadiendo cada número de entrada como un nodo a la pila `a`.
	//Maneja el desbordamiento de enteros, duplicados, y errores de sintaxis, por ejemplo, la entrada sólo debe contener dígitos, o signos `-` `+`.
		//Si se encuentran errores, libera la pila `a` y devuelve error
	//Comprueba para cada entrada, si es un entero largo
		//Si la entrada es una cadena, convertirla en un entero largo 
	//Agrega los nodos a la pila `a`.

//Comprueba si la pila `a` está ordenada
	//Si no está ordenada, implementa nuestro algoritmo de ordenación 
		//Comprueba si hay 2 números
			//Si es así, simplemente intercambia los números
		//Comprobar si hay 3 números
			//Si es así, implementa nuestro sencillo algoritmo sort three
		//Comprueba si la pila tiene más de 3 números
			//Si es así, implanta nuestro algoritmo Turco (buscar referencias en internet) Hace el orden buscando el medio del stack y trabaja rotando 			con el valor que nos va definiendo.

//Limpia la pila


🔷 Utilizar el comprobador proporcionado por 42
============================================================

    Descarga el archivo correcto de la página del tema, por ejemplo para Mac, o Linux, dentro del mismo directorio que tu ejecutable.
    Ejecutar el comprobador probablemente no funcionará, ya que no tendrá el permiso del ejecutable. Compruébalo escribiendo en el terminal ls -l
    Para darle permiso, haga chmod +x <nombredearchivo>.
    Pruebe su ejecutable con todo lo que necesitamos que haga nuestro push_swap:
        por ejemplo, las salidas correctas para todos los tipos de error
        por ejemplo, ejecute ARG="4 10 1 3 2"; ./push_swap $ARG | ./checker_Mac $ARG 
        Para ver cuántas instrucciones, ejecute ARG="4 10 1 3 2"; ./push_swap $ARG | wc -l
        Para que nuestro programa pase la evaluación, tendrá que devolver n tamaño de instrucciones para ordenar x número de valores:
            Si x = 3 entonces n <= 3
            Si x = 5 entonces n <= 12
            Si x = 100 entonces n < 1500
            Si x = 500 entonces n < 11500
            Nota: cuantas menos instrucciones devuelva nuestro algoritmo, más puntos de evaluación obtendremos.

¿Qué es un algoritmo?
============================================

    Un conjunto de instrucciones para resolver un problema.


¿Qué es el concepto de complejidad?
====================================================

    Análisis de algoritmos: Análisis de las instrucciones paso a paso del algoritmo para comprender su rendimiento.
    Eficiencia del algoritmo: Observar la rapidez con la que un algoritmo resuelve un problema y los recursos que consume, como tiempo y memoria.
    Notación asintótica: Uso de notaciones matemáticas como Big O, Omega y Theta para analizar el tiempo de ejecución de un algoritmo a medida que el problema aumenta de tamaño.
    Complejidad temporal: Utilizando Big O, se observa el mejor, el peor y la media de los casos en que se completa un algoritmo.
    Complejidad espacial: Utilizando Big 0, se observa la cantidad de espacio de memoria que utiliza un algoritmo.

Solo se permiten estos movimientos:
=======================================

• El objetivo es ordenar los números del stack a en orden ascendente. Para hacerlo
tienes las siguientes operaciones a tu disposición:

sa swap a: Intercambia los dos primeros elementos del stack a. No hace nada si
hay uno o menos elementos.

sb swap b: Intercambia los dos primeros elementos del stack b. No hace nada si
hay uno o menos elementos.

ss swap a y swap b a la vez.

pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack
a. No hace nada si b está vacío.

pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack
b. No hace nada si a está vacío.

ra rotate a: Desplaza hacia arriba todos los elementos del stack a una posición,
de forma que el primer elemento se convierte en el último.

rb rotate b: Desplaza hacia arriba todos los elementos del stack b una posición,
de forma que el primer elemento se convierte en el último.

rr ra y rb al mismo tiempo.

rra reverse rotate a: Desplaza hacia abajo todos los elementos del stack a una
posición, de forma que el último elemento se convierte en el primero.

rrb reverse rotate b: Desplaza hacia abajo todos los elementos del stack b una
posición, de forma que el último elemento se convierte en el primero.

rrr rra y rrb al mismo tiempo.

El proyecto
Crea dos programas: checker y push_swap.
=========================================

El checker programa lee una lista aleatoria de números enteros de la entrada estándar, los almacena y comprueba si están ordenados.

El push_swap programa calcula los movimientos para ordenar los números enteros ( empujarlos, sacarlos, intercambiarlos y rotarlos entre la pila a y la pila b ) y muestra esas direcciones en la salida estándar.

Puede ingresar push_swap a checker, y checker verificará que push_swaplas instrucciones de se hayan realizado correctamente.

Ambos programas deben analizar obligatoriamente la entrada en busca de errores, incluidas cadenas vacías, ausencia de parámetros, parámetros no numéricos, duplicados e instrucciones no válidas o inexistentes.

Push_Swap debe cumplir con la Norma 42.
Está estrictamente prohibido usar funciones normales . libc Sin embargo, los estudiantes pueden usar: write, read, malloc, free, exit. No debe tener fugas de memoria. Los errores deben manejarse con cuidado.
De ninguna manera puede cerrarse de manera inesperada (error de segmentación, error de bus, doble liberación, etc.).

EL ALGORITMO
============================
Este algoritmo no tiene nobre como tal, si tuviera un nombre seria; Shortest Move Sort. Por que busca el movimiento más corto posible en cada caso y lo ejecuta, para ello debe cumplir estas condiciones:

El numero elegido del Stack A debe ser menor al número top del Stack B y Mayor al Numero del fondo del Stack B. Ejemplo:

Stack A	Stack B
6	7
...	...
...	5
Por que nos interesa? Por que es el movimiento más rápido para pasar los valores de manera ordenada desde el stack A al stack B. No buscamos un número en concreto, buscamos el número que necesite menos movimientos. Para eso creamos un mapa de movimientos donde rotamos todos los números del Stack B por cada número del Stack A para comprobar cuanto hay que rotar A y cuanto hay que rotar B para que:

Cumpla la primera condición.
Consuma los minimos movimientos necesarios para enviarlos al Stack B de manera ordenada.
Ejemplo práctico:

Stack A	Stack B
5	1
4	3
2	6
Movimientos para cumplir condición 1	Stack B + 0	Stack B + 1	Stack B + 2	Stack B + 3
Stack A + 0 rotación hacia arriba	No cumple	No cumple	Cumple, 0 + 2 = 2	No cumple
Stack A + 1 rotación hacia arriba	No cumple	No cumple	Cumple, 1 + 2 = 3	No cumple
Stack A + 2 rotación hacia arriba	No cumple	Cumple, 2 + 1 = 3	No cumple	No cumple
Stack A + 3 rotación hacia arriba	No cumple	No cumple	Cumple, 3 + 2 = 5	No cumple
En este pequeño y básico ejemplo, vemos el mapa de movimientos y cual consume los minimos, que seria rotar dos veces el stack B y añadir el numero en su lugar correspondiente. Ahora no se ve tan necesario, pero con una cantidad elevada de números marca la diferencia.

Esa es la base, ahora falta optimizarlo, el primer paso es que las rotaciones pueden ser tanto por arriba o por abajo, Para ello, cuando la condición se cumple, comprobamos tanto del Stack A como del Stack B si es mas rápido rotando hacia arriba o hacia abajo:

Ejemplo práctico:
***********************

Stack A
25
42
200
6
73
Imaginemos que opción óptima es el 6; si vamos por arriba serán 3 movimientos pero, si vamos por abajo (numeros del stack; 5 - movimientos hacia arriba; 3) vemos que serian 2.

Como hemos visto importa el sentido de los movimientos, y esto nos ayudará a elegir mejor los movimientos para hacer, pero todavia se puede optimizar mucho más:

Una vez encontramos una opción que cumpla la condición 1, guardamos cuantos movimientos hacia arriba y hacia abajo se harian tanto en el Stack A como en el Stack B:

Ejemplo práctico:
*************************************

Movimientos	Stack A (300 numeros)	Stack B (100 numeros)
Hacia arriba	192 movimientos	5 movimientos
Hacia abajo	300 - 192 = 108 mov.	100 - 5 = 95 mov.
Aqui se pueden solapar movimientos ya que si los dos van hacia arriba o hacia abajo, se pueden hacer a la vez y ahorrar muchos movimientos, asi que aqui hay 4 posibilidades:

Stack A arriba y Stack B arriba: Solapan - 192 y 5 = 192 movimientos
Stack A abajo y Stack B abajo: Solapan - 108 y 95 = 108 movimientos
Stack A arriba y Stack B abajo: 192 + 95 = 287 movimientos
Stack A abajo y Stack B arriba: 108 y 5 = 113 movimientos
En este caso la mejor opcion seria solapar movimientos rotativos hacia abajo y luego el stack que falte por rotar rote solo.

CON TODO ESTO YA ESTAS LISTO PARA CREAR TU ALGORITMO(casi):

Debes de ver cuando se cumple la condición 1.
En cada uno de los nodos que se cumpla deberás ver que unión de movimientos es el más eficaz. Una vez hecho esto en cada posibilidad, deberas ejecutar la que utilize menos movimientos. Cuando este todo en el Stack B, solo te queda ordenarlo en el stack A.

Me he saltado la explicación de que hacer en caso de encontrarte con el numero más pequeño, el más grande o lo de ordenar los tres últimos numeros ya que sé que serás capaz de averiguarlo sin mi ayuda, te deseo suerte!





