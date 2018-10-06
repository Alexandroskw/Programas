#include <stdio.h>
#include <math.h> //Se utiliza para usar 'arctan()' y 'sqrt()'.
#include <stdlib.h>

#define pi 3.14159265 //Se declara pi como constante.
#define rad 180/pi //Para convertir de radianes a grados, se crea esta variable.

void distAng(float x[], float y[], int n); //Prototipo de la función.

int main()
{
	int n;

	system("cls"); //Se utiliza para que siempre que se ejecute el programa, la terminal esté vacía.
	printf("De cuantos puntos quieres el angulo y la distancia?\n");
	printf("(Procura que no sean muchos puntos)\n"); //Para que el usuario no escriba muchos puntos, se pone la sugerencia.
	printf(">> ");
	scanf("%d", &n); //Se lee cuántos puntos son los que quiere el usuario.

	float tamx[n], tamy[n]; //Una vez introducido el número de puntos que se desea, se crean 2 arreglos del tamaño introducido por el usuario. 'tamx' hace referencia a 'x', 'tamy' hace referencia a 'y'.

	printf("Ingresa las coordenadas.	(Ej. 5, 3)\n");
	for(int i=0; i<n; i++)
	{
		printf("P: (x[%d], y[%d])>> ", i+1, i+1);
		scanf("%f, %f", &tamx[i], &tamy[i]); //Se almacenan las coordenadas de 'x' y 'y' separadas por una coma. ('tamx' almacena coord de 'x' y 'tamy' almacena las de 'y')
	}

	distAng(tamx, tamy, n); //Se pasan los datos de los puntos por valor a la función.
}

void distAng(float x[], float y[], int n) //La función recibe los parámetros por valor del 'main()' del programa.
{
	float dx[n], dy[n], d[n], th[n]; //Se crean arreglos tipo flotante para recibir los datos.

	for(int i=0; i<n; i++)
	{
		dx[i]=x[i+1]-x[i]; //'dx' es el resultado de restar 'x2-x1'. 'x[i+1]' recorre el arreglo hasta la 'n'-sima posición del arreglo con respecto a 'i'. Si está en la posición '0', se recorre a la posición '1'.
		dy[i]=y[i+1]-y[i]; //'dy' es el resultado de restar 'y2-y1'. 'y[i+1]' recorre el arreglo hasta la 'n'-sima posición del arreglo con respecto a 'i'. Si está en la posición '0', se recorre a la posición '1'.
		d[i]=sqrt((dx[i]*dx[i])+(dy[i]*dy[i])); //'d' es la distancia a calcular de 'dx' y 'dy' (d=[(x2-x1)^2+(y2-y1)^2]^(1/2)).
		th[i]=atan(dy[i]/dx[i])*rad; /*th es el ángulo de los 2 vectores. Una vez que se obtiene 'x2-x1' y 'y2-y1', es decir, 
		'dx' y 'dy' se dividen, y para convertirlos a grados se multiplica por la variable 'rad' declarada al inicio*/

		//printf("\nP[%d]: (%.4f, %.4f)", i+1, x[i], y[i]); Se imprimen los puntos introducidos por el usuario para confirmar que no hay error.
	}

	for (int i=0; i<n-1; i++) //En este ciclo se imprimen la distancia y el ángulo entre los 2 vectores. 'n-1' se agregó ya que hay un error en el recorrido del arreglo, imprime un resultado de mas.
		printf("\nd[%d] = %.4f, theta[%d] = %.4f%c", i+1, d[i], i+1, th[i], 248);

	exit(0);
}