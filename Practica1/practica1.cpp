#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>

// El mismo valor de pi dado en math.h de C
#define M_PI 3.14159265358979323846

#if defined(_WIN32) || defined(__CYGWIN__)
#include <cstdlib>
#define CLRSCR() system("cls");
#else
#define CLRSCR() std::cout << "\x1b[2J\x1b[H";
#endif

template <typename _T> void read_input(_T& variable, std::string prompt);
double funcion1(double x);
double funcion2(double x);

double hi, hs, hp, tol;
char rsp, main_loop, selec_func;
double h, V, r;
double (*foo)(double);

using namespace std;

int main(int argc, char const* argv[])
{
    CLRSCR();

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(5);

    cout << "\t\t  ANALISIS NUMERICO" << endl;
    cout << "\t\t      Grupo: 6" << endl;
    cout << "\t\t Método de bisección" << endl << endl;

    cout << "Integrantes del equipo:" << endl;
    cout << " - Bravo Moreno Gustavo Ulises" << endl;
    cout << " - Flores González Brandon Uriel" << endl;
    cout << " - Martinez Cruz Lizeth" << endl;
    cout << " - Moreno Chalico Edgar Ulises" << endl;
    cout << " - Yañez García Fernando" << endl << endl;

    cout << "Presiona enter tecla para continuar";
    cin.ignore();

    CLRSCR();

    do
    {
        rsp = 's';
        main_loop = 's';
        selec_func = '0';
        foo = NULL;

        do
        {
            cout << ">> Selecciona una función a resolver" << endl;
            cout << "[1] V = (πx^2 (3r-x))/3" << endl;
            cout << "[2] sin(x) - csc(x) + 1 = 0" << endl;

            read_input(selec_func, "> ");

            // Se selecciona la función usando un puntero
            if (selec_func == '1')
                foo = funcion1;
            if (selec_func == '2')
                foo = funcion2;
        } while (selec_func != '1' && selec_func != '2');


        if (foo == funcion1)
            read_input(r, "Ingresa el valor de r[m]: ");

        cout << ">> Tabulación de la función" << endl;
        do
        {
            read_input(hi, ">> Ingresa el valor de hi para tabular: ");

            cout << setw(15) << "h" << setw(15) << "f(h)" << endl;
            for (int counter = 0; counter <= 50; counter++)
                cout << setw(15) << hi + (0.1 * counter) << setw(15) << foo(hi + (0.1 * counter)) << endl;

            read_input(rsp, "¿Deseas tabular nuevamente? (s/n): ");

        } while (rsp == 's');

        do
        {
            read_input(hi, "Ingresa el valor del límite inferior (hi): ");
            read_input(hs, "Ingresa el valor del límite superior (hs): ");
        } while ((foo(hi) * foo(hs)) > 0 || hi > hs);

        read_input(tol, "Ingresa el valor de la tolerancia: ");
        if (tol < 0) tol = tol * -1;

        CLRSCR();

        cout << "\t\t --- Parámetros --- " << endl;
        cout << "Intervalo inicial: [ " << hi << ", " << hs << " ] " << endl;
        if (foo == funcion1)
            cout << "r[m] = " << r << endl;
        cout << "Tolerancia = " << tol << endl;

        cout << "|    i |"
            << "              hi |"
            << "              hp |"
            << "              hs |"
            << "           f(hi) |"
            << "           f(hp) |"
            << "           f(hs) |"
            << "     f(hi)*f(hs) |"
            << endl;

        double fhifhp;
        int iteraciones = 0;

        do
        {
            iteraciones++;
            hp = (hi + hs) / 2;
            fhifhp = foo(hi) * foo(hp);

            cout << "|"
                << setw(5) << iteraciones << " | "
                << setw(15) << hi << " | "
                << setw(15) << hp << " | "
                << setw(15) << hs << " | "
                << setw(15) << foo(hi) << " | "
                << setw(15) << foo(hp) << " | "
                << setw(15) << foo(hs) << " | "
                << setw(15) << fhifhp << " | "
                << endl;

            if (fhifhp < 0)
                hs = hp;
            else if (fhifhp > 0)
                hi = hp;
        } while (fabs(foo(hp)) > tol);

        cout << "La raíz es: " << hp << endl;

        read_input(main_loop, "¿Deseas calcular otra raíz? (s/n): ");
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

/**
 * @brief V=(πx^2 (3r-x))/3
 *
 * @param x
 * @return double V
 */
double funcion1(double x)
{
    return (M_PI * std::pow(x, 3) * (3 * r - x)) / 3;
}

/**
 * @brief y = sin(x) - csc(x) + 1
 *
 * @param x
 * @return double y
 */
double funcion2(double x)
{
    return std::sin(x) - (1 / std::sin(x)) + 1;
}