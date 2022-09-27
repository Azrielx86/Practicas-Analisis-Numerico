/*   METODO DE NEWTON RAPHSON   */
#include <stdio.h>
// #include <conio.h>
#include <math.h>
#include <ctype.h>
double fun(double);  /* Declaraci�n de funciones */
double prider(double);
double segder(double);

void clrscr() {}

int main(void)
{
	double x0, xnuevo, h = 0.2, convergencia, error, tol;  /*Declaraci�n de variables*/
	int i, cifras;
	char corre = 's';

	while (corre == 's')
	{
		while (corre == 's')
		{
			clrscr();
			printf("\n\t T A B U L A C I O N "); /* Para seleccionar x0 */
			printf("\n\t Dame un valor ");
			scanf("%lf", &x0);
			for (i = 0; i < 10; i++)
			{
				printf("\n\t % lf \t\t % lf ", x0 + i * h, fun(x0 + i * h));
			}
			printf("\n\t Deseas tabular otra vez (s/n) ");
			corre = tolower(getche());
		}
		do
		{
			clrscr();
			printf("\n\t Dame el valor inicial x0 = ");   /*Datos de entrada*/
			scanf("%lf", &x0);
			convergencia = (fun(x0) * segder(x0)) / prider(x0);
		} while (fabs(convergencia) > 1);
		printf("\n\tCon cu�ntas cifras significativas exactas ");
		printf("quieres el resultado ");
		scanf("%d", &cifras);
		tol = 0.5 * pow(10, 2 - cifras);  /* Error relativo deseado* /

		clrscr();
		printf("\n\n\t\t P A R A M E T R O S");      /* Salida */
		printf("\n\t Valor inicial x0  =  % lf", x0);
		printf("\n\t Tolerancia        =  % lf", tol);
		printf("\n\n  i       x[i]       f(x[i])       error");
		i = 0;
		do
		{
			i++;
			xnuevo = x0 - fun(x0) / prider(x0);
			error = fabs((xnuevo - x0) / xnuevo) * 100;
			printf("\n %2d    % 11.7lf    ", i, xnuevo);
			printf("% 11.7lf    % 11.7lf", fun(xnuevo), error);
			x0 = xnuevo;
		} while (error > tol);

		printf("\n\n\t La raiz es %11.7lf ", xnuevo);

		printf("\n\t Deseas calcular otra ra�z (s/n) ");
		corre = tolower(getche());
	}
	getch();
}
/* Funciones */
double fun(double x)
{
	float y;
	y = pow(x, 3) + 0.35 * pow(x, 2) - 0.5 * x - 0.175;
	return (y);
}
double prider(double x)
{
	double y;
	y = 3 * pow(x, 2) + 0.7 * x - 0.5;
	return (y);
}
double segder(double x)
{
	double y;
	y = 6 * x + 0.7;
	return (y);
}