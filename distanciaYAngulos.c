#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define pi 3.14159265
#define rad 180/pi

float distAng(float *x, float *y, int n); //Prototipo de la función.

int main()
{
	size_t n;
	float *tamx, *tamy; //Se usan apuntadores tipo flotantes para utilizar memoria dinámica e ingresar números enteros o con decimales.

	system("cls"); //Se utiliza para que siempre que se ejecute el programa, la terminal esté vacía.
	printf("De cuantos puntos quieres el angulo y la distancia?\n");
	printf("(Procura que no sean muchos puntos)\n"); //Para que el usuario no escriba mucho, se pone la sugerencia.
	printf(">> ");
	scanf("%d", &n); //Se lee cuántos puntos son los que quiere el usuario.

	tamx=(float *)calloc(n, sizeof(float));
	tamy=(float *)calloc(n, sizeof(float));

	printf("Ingresa las coordenadas. 	(Ej. 5,3)\n");
	for(int i=0; i<n; i++)
	{
		printf("P: (x[%d], y[%d])>> ", i+1, i+1);
		scanf("%f, %f", &tamx[i], &tamy[i]);
	}

	distAng(tamx, tamy, n);

	free(tamx);
	free(tamy);
}

float distAng(float *x, float *y, int n)
{
	float *dx, *dy, *d, *th;

	dx=(float *)calloc(n, sizeof(float));
	dy=(float *)calloc(n, sizeof(float));
	d=(float *)calloc(n, sizeof(float));
	th=(float *)calloc(n, sizeof(float));

	for(int i=0; i<n; i++)
	{
		dx[i]=x[i+1]-x[i];
		dy[i]=y[i+1]-y[i];
		d[i]=sqrt((dx[i]*dx[i])+(dy[i]*dy[i]));
		th[i]=atan(dy[i]/dx[i])*rad;
	}

	for(int i=0; i<n; i++)
		printf("d[%d] = %.4f, theta[%d] = %.4f%c", i+1, d[i], i+1, th[i], 248);

	free(dx);
	free(dy);
	free(d);
	free(th);

	return 0;
}