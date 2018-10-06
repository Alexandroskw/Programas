#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <cmath>

#define s scanf

void suma_resta();
void mult();
void der_int();
void punto();

int main()
{
	int op, r, o;

	INICIO:
		do
		{
			system("cls");
			printf("\tQue deseas hacer?");
			printf("\n1. Sumar y restar dos polinomios.\n");
			printf("2. Multiplicar dos polinomios.\n");
			printf("3. Derivar e integrar un polinomio.\n");
			printf("4. Evaluar un polinomio en un punto.\n");
			printf("  %c%c>", 196, 196);
			s("%d", &op);

			system("cls");

			switch(op)
			{
				case 1:
				{
					printf("\tSuma y resta de polinomios:\n\n");
					suma_resta();
					printf("\n\nDesea realizar otra opcion?:\n");
					printf("1.Si      0.No\n");
					printf("%c%c>", 196, 196);
					s("%d", &o);
					if(o==1)
						goto INICIO;
					else
						goto FIN;
				}
				break;
				case 2:
				{
					printf("\tMultiplicacion de polinomios:\n\n");
					mult();
					printf("\n\nDesea realizar otra opcion?:\n");
					printf("1.Si      0.No\n");
					printf("%c%c>", 196, 196);
					s("%d", &o);
					if(o==1)
						goto INICIO;
					else
						goto FIN;
				}
				break;
				case 3:
				{
					printf("\tDerivada de un polinomio:\n\n");
					der_int();
					printf("\n\nDesea realizar otra opcion?:\n");
					printf("1.Si      0.No\n");
					printf("%c%c>", 196, 196);
					s("%d", &o);
					if(o==1)
						goto INICIO;
					else
						goto FIN;
				}
				break;
				case 4:
				{
					printf("\tEvaluacion de un polinomio en un punto:\n\t");
					punto();
					printf("\n\nDesea realizar otra opcion?:\n");
					printf("1.Si      0.No\n");
					printf("%c%c>", 196, 196);
					s("%d", &o);
					if(o==1)
						goto INICIO;
					else
						goto FIN;
				}
				break;
				default:
				{
					printf("\nLa opcion no existe, por favor trata de nuevo.\n");
					printf("Deseas repetir el programa?\n");
					printf("1.Si 		0.No\n");
					printf("%c%c>", 196, 196);
					s("%d", &r);
				}
				break;
			}
		}while(r==1);

	FIN:
		system("cls");
		printf("\tHasta pronto.\n");
		system("pause");
}

void suma_resta()
{
	int n, m;
	float pol[100], pol1[100], ps[100], pr[100];

	printf("\tDefine el grado del polinomio 1>> ");
	scanf("%d", &n);

	printf("\n\tIngresa los coeficientes del polinomio 1>>\n");
	for(int i=0; i<=n; i++)
	{
		printf("\tcoef[%d]: ", i);
		scanf("%f", &pol[i]);
	}

	system("cls");

	printf("\tDefine el grado del polinomio 2>> ");
	scanf("%d", &m);

	printf("\n\tIngresa los coeficientes del polinomio 2>>\n");
	for(int i=0; i<=m; i++)
	{
		printf("\tcoef[%d]: ", i);
		scanf("%f", &pol1[i]);
	}

	system("cls");

	printf("El polinomio 1 es:\n");
	for(int i=0; i<=n; i++)
		printf("+(%.0f)x^(%d)", pol[i], i);

	printf("\nEl polinomio 2 es:\n");
	for(int i=0; i<=m; i++)
		printf("+(%.0f)x^(%d)", pol1[i], i);

	printf("\n\nLa suma del polinomio es:\n");
	for(int i=0; i<=m; i++)
	{	
		ps[i]=pol[i]+pol1[i];
		printf("+(%.0f)x^(%d)", ps[i], i);
	}

	printf("\n\nLa resta del polinomio es:\n");
	for(int i=0; i<=m; i++)
	{
		pr[i]=pol[i]-pol1[i];
		printf("+(%.0f)x^(%d)", pr[i], i);
	}

	printf("\n\n");
	system("pause");
}

void mult()
{
	int n, m;

	printf("\tDefine el grado del polinomio 1>> ");
	scanf("%d", &n);

	float pol[n];

	printf("\n\tIngresa los coeficientes del polinomio 1>>\n");
	for(int i=n; i>=0; i--)
	{
		printf("\tcoef[%d]: ", i);
		scanf("%f", &pol[i]);
	}

	printf("\tDefine el grado del polinomio 2>> ");
	scanf("%d", &m);

	float pol1[m];

	printf("\n\tIngresa los coeficientes del polinomio 2>>\n");
	for(int k=m; k>=0; k--)
	{
		printf("\tcoef[%d]: ", k);
		scanf("%f", &pol1[k]);
	}

	system("cls");

	printf("\tEl polinomio 1 es:\n");
	for(int i=n; i>=0; i--)
	{
		if(i>1)
			printf(" %.0fx^%d ", pol[i], i);
		else if(i==1)
			printf(" %.0fx ", pol[i]);
		else if(i==0)
			printf(" %.0f ", pol[i]);
		if(i!=0)
			printf(" + ");
	}

	printf("\n\n\tEl polinomio 2 es:\n");
	for(int i=m; i>=0; i--)
	{
		if(i>1)
			printf(" %.0fx^%d ", pol1[i], i);
		else if(i==1)
			printf(" %.0fx ", pol1[i]);
		else if(i==0)
			printf(" %.0f ", pol1[i]);
		if(i!=0)
			printf(" + ");
	}

	float pm[n+m];

	for(int i=0; i<=n+m; i++)
		pm[i]=0;

	for (int i=0; i<=n; i++)
		for(int j=0; j<=m; j++)
			pm[i+j]+=pol[i]+pol1[j];

	printf("\n\t\nLa multiplicacion del polinomio es:\n");
	for(int i=n+m; i>=0; i--)
	{
		if(i>1)
			printf(" %0.fx^%d ", pm[i], i);
		else if(i==1)
			printf(" %0.fx ", pm[i]);
		else if(i==0)
			printf(" %.0f ", pm[i]);
		if(i!=0)
			printf(" + ");
	}

	printf("\n");
	system("pause");
}

void der_int()
{
	int n;

	printf("\tDefine el tamano del polinomio>> ");
	scanf("%d", &n);

	float pol[n], d[n-1];

	printf("\n\tIngresa los coeficientes del polinomio>>\n");
	for(int i=n; i>=0; i--)
	{
		printf("\tcoef[%d]: ", i);
		scanf("%f", &pol[i]);
	}

	system("cls");

	printf("El polinomio es:\n");
	for(int i=n; i>=0; i--)
	{
		if(i>1)
			printf(" %.0fx^%d ", pol[i], i);
		else if(i==1)
			printf(" %.0fx ", pol[i]);
		else if(i==0)
			printf(" %.0f ", pol[i]);
		if(i!=0)
			printf(" + ");
	}

	for(int i=n; i>=1; i--)
		d[i-1]=pol[i]*i;
	
	printf("\n\nEl polinomio derivado es:\n");
	for(int i=n; i>=0; i--)
	{
		if(i>1)
			printf(" %.0fx^%d", d[i-1], i-1);
		else if(i==1)
			printf(" %.0f ", d[i-1]);
		if(i!=0)
			printf(" + ");
		else if(i==0)
			printf(" 0");
	}

	printf("\n");
	system("pause");
}

void punto()
{
	int n;
	float x, p=0.0;

	printf("Define el grado del polinomio>> ");
	s("%d", &n);

	float a[n];

	printf("\nIngresa los coeficientes del polinomio:\n");
	for(int i=n; i>=0; i--)
	{
		printf("Coef[%d]: ", i);
		s("%f", &a[i]);
	}

	printf("Ingresa un valor para 'x'>> ");
	s("%f", &x);

	system("cls");

	printf("El polinomio es:\n");
	for(int i=n; i>=0; i--)
	{
		if(i>1)
			printf(" %.0fx^%d ", a[i], i);
		else if(i==1)
			printf(" %.0fx ", a[i]);
		else if(i==0)
			printf(" %.0f ", a[i]);
		if(i!=0)
			printf(" + ");
	}

	for(int i=0; i<=n; i++)
		p+=a[i]*pow(x, i);

	printf("\nEl polinomio evaluado en x=%.0f es:\n", x);
	printf("p(%.0f)=%.0f\n", x, p);
	system("pause");
}