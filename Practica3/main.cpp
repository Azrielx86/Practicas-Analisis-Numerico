/* ANÅLISIS NUMÉRICO Pråctica No. 3
A) Con ayuda un programa programas para resolver sistemas de ecuaciones lineales del
tipo ECGAJ.C o bien un programa disenado por IOS alumnos en el lenguaje de
programaciön que se les facilite mås.
I. Agregar un letrero que diga
ANÅLISIS NUMÉRICO
GRUPO:
MÉTODO DE ELIMINACIÖN COMPLETA DE GAUSS-JORDAN
2. Agregar un letrero en el que aparezcan los integrantes del equipo
3. Ahada Ias instrucciones que sean necesarias para que seleccione como pivote el
elemento de mayor valor absoluto
4.- Afiadir las instrucciones necesarias para que el programa imprima ademås de los
resultados, los valores de los pivotes utilizados
5. Calcular el producto de los pivotes y que 10 imprima para compara con el
determinante de la matriz
7. Utilizar el programa modificado para estimar la soluciön de un sistema de ecuaciones
lineales con al menos 10 ecuaciones y 10 incögnitas
2. En Excel:
1. Desarrollar el método de Gauss Seidel para un sistema de al menos 8 ecuaciones con
S incågnitas
2. Resolver un ejemplo de aplicaciön
3. Reportar conclusiones y comentarios
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

template <typename _T> void read_input(_T& variable, std::string prompt);
double funcion(double x);
double funciondx1(double x);
double funciondx2(double x);

char rsp, main_loop, selec_func;

using namespace std;

int main(int argc, char const* argv[])
{
    CLRSCR();

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(5);

    #ifndef DEBUG

    cout << "\t\t\t  ANALISIS NUMERICO" << endl;
    cout << "\t\t\t      Grupo: 6" << endl;
    cout << "\t\t METODO DE ELIMINACION COMPLETA DE GAUSS-JORDAN" << endl << endl;

    cout << "Integrantes del equipo:" << endl;
    cout << " - Bravo Moreno Gustavo Ulises" << endl;
    cout << " - Flores González Brandon Uriel" << endl;
    cout << " - Martinez Cruz Lizeth" << endl;
    cout << " - Moreno Chalico Edgar Ulises" << endl;
    cout << " - Yañez García Fernando" << endl << endl;

    cout << "Presiona enter tecla para continuar";
    cin.ignore();

    CLRSCR();

    #endif



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
template <typename _T> void read_input(_T& variable, std::string prompt)
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
    return 1.0;
}

double funciondx1(double x)
{
    return 1.0;
}

double funciondx2(double x)
{
    return 1.0;
}