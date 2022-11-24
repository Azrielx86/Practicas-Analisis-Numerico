/* ANALISIS NUMÉRICO Pråctica No. 2

A) Para un programa de Newton-Raphson realizado en smathstudio o en un lenguaje
    de cómputo que se les haga mås sencillo utilizar
    1. Agregar un letrero que diga:
        ANÅLISIS NUMÉRICO
        GRUPO:
        MÉTODO DE NEWTON RAPHSON
    2. Agregar un letrero en el que aparezcan los integrantes del equipo.
    3.Hacer que el programa resuelva una función de aplicación a la ingenieria
        (de preferencia de su carrera)
    4. Hacer que el programa tabule 50 valores de la función con un incremento
        h=0.1
    5. Incluir el criterio de convergencia, es decir definir la función de la
        segunda derivada y llamarla en esta parte
    6. Hacer que el programa termine hasta que se cumpla la tolerancia o un
        número måximo de iteraciones, 10 que suceda primero.

B) EN EXCEL:
    1) Dibujar la función que se resolvió en el punto 3 del inciso A.
    2) Dibujar el número de la iteración en el eje horizontal y en el eje vertical
        el valor absoluto de la función calculado en dicha iteración.

C) DAR CONCLUSIONES Y COMENTARIOS
*/
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>

#if defined(_WIN32) || defined(__CYGWIN__)
#include <cstdlib>
#define CLRSCR() system("cls");
#else
#define CLRSCR() std::cout << "\x1b[2J\x1b[H";
#endif

#define MAX_IT 1000

template <typename _T> void leer_entrada(_T& variable, std::string prompt);
double funcion(double x);
double funcion_dx1(double x);
double funcion_dx2(double x);

using namespace std;

int main(int argc, char const* argv[])
{
    char rsp, main_loop;
    double x0, xnuevo, convergencia, error, tol;

    CLRSCR();

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(5);

    cout << "\t\t     ANALISIS NUMERICO" << endl;
    cout << "\t\t          Grupo: 6" << endl;
    cout << "\t\t METODO DE NEWTON RAPHSON" << endl << endl;

    cout << "Integrantes del equipo:" << endl;
    cout << " - Bravo Moreno Gustavo Ulises" << endl;
    cout << " - Flores González Brandon Uriel" << endl;
    cout << " - Martinez Cruz Lizeth" << endl;
    cout << " - Moreno Chalico Edgar Ulises" << endl;
    cout << " - Yañez García Fernando" << endl << endl;

    cout << "Presiona enter tecla para continuar";
    cin.ignore();

    CLRSCR();

    // Programa principal
    do
    {
        rsp = 's';
        main_loop = 's';

        // Tabulación de la función
        cout << ">> Tabulación de la función\n";
        do
        {
            leer_entrada(x0, "Ingresa el valor de x0: ");
            cout << setw(15) << "h" << setw(15) << "f(h)" << endl;
            for (int counter = 0; counter <= 50; counter++)
                cout << setw(15) << x0 + (0.1 * counter) << setw(15) << funcion(x0 + (0.1 * counter)) << endl;

            leer_entrada(rsp, "¿Deseas tabular nuevamente? (s/n): ");
        } while (rsp == 's');

        do
        {
            CLRSCR();
            leer_entrada(x0, "Ingresa un valor inicial para x0: ");
            convergencia = (funcion(x0) * funcion_dx2(x0)) / funcion_dx1(x0);
        } while (fabs(convergencia) > 1);

        leer_entrada(tol, "Ingresa el valor de la tolerancia: ");
        if (tol < 0) tol = tol * -1;

        CLRSCR();

        cout << "\t\t --- Parámetros --- " << endl;
        cout << "Valor inicial = " << x0 << endl;
        cout << "Tolerancia = " << tol << endl;

        cout << "|    i |"
            << "              xi |"
            << "         f(x[i]) |"
            << "           error |"
            << endl;

        int iteraciones = 0;
        do
        {
            iteraciones++;

            if (iteraciones >= MAX_IT)
            {
                cout << "Se alcanzó el número máximo de iteraciones\n";
                break;
            }

            xnuevo = x0 - funcion(x0) / funcion_dx1(x0);
            error = fabs((xnuevo - x0) / xnuevo) * 100;
            cout << "|"
                << setw(5) << iteraciones << " | "
                << setw(15) << xnuevo << " | "
                << setw(15) << funcion(xnuevo) << " | "
                << setw(15) << error << " | "
                << endl;
            x0 = xnuevo;
        } while (error > tol);

        cout << "La raíz es: " << setw(15) << xnuevo << endl;

        leer_entrada(main_loop, "¿Deseas calcular otra raíz? (s/n)");
    } while (main_loop == 's');


    cout << "Finalizando el programa." << endl;

    return 0;
}

/**
 * @brief Lee la entrada del usuario de una manera más segura, para evitar que
 * al ingresar un dato erróneo el programa se detenga bruscamente.
 *
 * @tparam _T
 * @param variable
 * @param prompt Texto con indicaciones para leer la variable.
 */
template <typename _T> void leer_entrada(_T& variable, std::string prompt)
{
    _T input;
    for (;;)
    {
        std::cout << prompt;
        std::cin >> input;
        if (cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            #if defined(_WIN32) || defined(__CYGWIN__)
            std::cout << "Valor incorrecto, vuelve a intentar." << endl;
            #else
            std::cout << "\x1b[1A";
            std::cout << "\x1b[2K";
            #endif
            continue;
        }

        break;
    }

    variable = input;
}

double funcion(double x)
{
    return pow(x, 3) - (12 * pow(x, 2)) + (40 * x) - 30;
}

double funcion_dx1(double x)
{
    return (3 * pow(x, 2)) - (24 * x) + 38;
}

double funcion_dx2(double x)
{
    return (6 * x) - 24;
}