#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define pi 3.14159265
#define rad 180/pi

float distAng(float *x, float *y, int n); //Prototipo de la función.

int main()
{
	int n;
	float *tamx, *tamy; //Se usan apuntadores tipo flotantes para utilizar memoria dinámica e ingresar números enteros o con decimales.

	do
	{
		system("cls"); //Se utiliza para que siempre que se ejecute el programa, la terminal esté vacía.
		printf("De cuantos puntos quieres el angulo y la distancia?\n");
		printf("(Procura que no sean muchos puntos)\n"); //Para que el usuario no escriba mucho, se pone la sugerencia.
		printf(">> ");
		scanf("%d", &n); //Se lee cuántos puntos son los que quiere el usuario.
	}while(n<=1);

	/*Se usa memoria dinámica para usar arreglos*/
	tamx=(float *)calloc(n, sizeof(float));
	tamy=(float *)calloc(n, sizeof(float));

	printf("Ingresa las coordenadas. 	(Ej. 5,3)\n");
	for(int i=0; i<n; i++)
	{
		printf("P: (x[%d], y[%d])>> ", i+1, i+1);
		scanf("%f, %f", &tamx[i], &tamy[i]);
	}

	distAng(tamx, tamy, n); //Se pasan los datos de los puntos por valor a la función

	/*Se libera la memoria*/
	free(tamx);
	free(tamy);
}

float distAng(float *x, float *y, int n) //La función recibe los parámetros por valor del 'main()' del programa.
{
	float *dx, *dy, *d, *th; //Se crean apuntadores para recibir los datos de la función

	/*Se usa memoria dinámica para usar arreglos*/
	dx=(float *)calloc(n, sizeof(float));
	dy=(float *)calloc(n, sizeof(float));
	d=(float *)calloc(n, sizeof(float));
	th=(float *)calloc(n, sizeof(float));

	for(int i=0; i<n; i++)
	{
		dx[i]=x[i+1]-x[i]; //'dx' es el resultado de restar 'x2-x1'. 'x[i+1]' recorre el arreglo hasta la 'n'-sima posición del arreglo con respecto a 'i'. Si está en la posición '0', se recorre a la posición '1'.
		dy[i]=y[i+1]-y[i]; //'dy' es el resultado de restar 'y2-y1'. 'y[i+1]' recorre el arreglo hasta la 'n'-sima posición del arreglo con respecto a 'i'. Si está en la posición '0', se recorre a la posición '1'.
		d[i]=sqrt((dx[i]*dx[i])+(dy[i]*dy[i])); //'d' es la distancia a calcular de 'dx' y 'dy' (d=[(x2-x1)^2+(y2-y1)^2]^(1/2)).
		th[i]=atan(dy[i]/dx[i])*rad; /*th es el ángulo de los 2 vectores. Una vez que se obtiene 'x2-x1' y 'y2-y1', es decir, 
		'dx' y 'dy' se dividen, y para convertirlos a grados se multiplica por la variable 'rad' declarada al inicio*/
	}

	for(int i=0; i<n-1; i++)
		printf("\nd[%d] = %.4f, theta[%d] = %.4f%c", i+1, d[i], i+1, th[i], 248);

	free(dx);
	free(dy);
	free(d);
	free(th);

	puts("\n");
	system("pause");
}