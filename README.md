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


   Operations - Description
   ===============================================================
sa : swap a - Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
sb : swap b - Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa : push a - take the first element at the top of b and put it at the top of a. Do - nothing if B is empty.
pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if A is empty.
ra : rotate a - shift up all elements of stack A by 1. The first element becomes the last one.
rb : rotate b - shift up all elements of stack B by 1. The first element becomes the last one.
rr : ra and rb at the same time.
rra : reverse rotate a - shift down all elements of stack A by 1. The last element becomes the first one.
rrb : reverse rotate b - shift down all elements of stack B by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.



