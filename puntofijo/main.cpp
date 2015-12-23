/*Programa para obtener raíces de polinomios
  por medio del metodo de iteración de punto fijo

		   Análisis Numérico
		   José Alfredo Gallegos Chavarría
		   mat. 1383375
		   16 de marzo de 2012
*/

//directivas de preprocesamiento adecuadas para el compilador
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;                                        //specificación del namespace

//grado maximo del polinomio, puesto como variable global para poderlo acceder en todos los scopes
int n = 0, i = 0;
double e = 0.0;

//prototipos de funciones
double eval(double[], double);
void imprimeEncabezado();
void imprimeInstrucciones();

int main()
{
    cout << fixed << setprecision(4);                           //cuatro decimales
    imprimeEncabezado();

    //obten un valor adecuado de n
    while(n <= 0  || n > 5)
    {

        cout << "\nGrado Maximo del Polinomio: ";
        cin >> n;

        if(n <= 0 || n > 5)
        {
            cout << "\nValor no adecuado...";
            getchar();
        }
    }

    //después, pide datos adicionales
    //captura tolerancia
    while (e <= 0  || e >=1)
    {
        cout << "\nEntrar error (porcentaje): ";
        cin >> e;
    }

    //crea arreglos double de n+1 posiciones para F y G (n coeficientes + cte)
    double F[n + 1];
    double G[n + 1];

    imprimeInstrucciones();

    for(i = n; i >= 0; i--)
    {
        cin >> F[i];
    }

    //Este metodo crea g(x) = x
    for(i = (n + 1); i >= 0; i--)
    {
        G[i] = F[i];
        if(i == 1)
        {
            G[i] += 1;
        }
    }

    //creamos otro arreglo para la derivada de G
    double Deriv[n + 1];

    //opera en el arreglo de la derivada de G
    for(i = 1; i < n + 1; i++)
    {
        //if(i = n){ Deriv[i] = 0; break;}
        Deriv[i - 1] = i * G[i];
    }

    //para imprimir datos en pantalla
    //imprime Fx
    cout << "\n f(x) = 0\t";
    for(i = n; i >= 0; i--)
    {
        cout << F[i] << "\t";
    }

    //imprime Gx
    printf("\n g(x) = x\t");
    for(i = n; i >= 0; i--)
    {
        cout << G[i] << "\t";
    }

    //imprime G'x
    printf("\n g'(x)\t\t");
    for(i = n; i >= 0; i--)
    {
        cout << Deriv[i] << "\t";
    }

    double validador = 2, value = 0;

    //evaluacion: es posible resolver la ecuacion por el metodo? (f'(a) < 1)?
    //recuerda: criterio de convergencia
    //en lugar de hacer que termine el programa si no es una aprox inicial adecuada, se queda
    //ciclando hasta obtener una aproximación adecuada del usuario
    while(validador > 1)
    {

        //pide valor a evaluar para la derivada
        cout << "\n\nEntrar aproximacion inicial x0 para obtener g'(x0): ";
        cin >> value;

        validador = eval(Deriv, value);
        cout << "\n g'(" << value << ") = " << validador;

        if(validador > 1)
            cout << "\n\nValor inadecuado, vuelva a entrar un valor...";
        else
            cout << "\n\nValor adecuado para resolucion por el metodo: g'(" << value << ") < 1";
    }

    double p = value;

    //muestra mensaje en pantalla adecuado
    cout << "\n\nSolucion por Metodo de Punto fijo con e = " << e;

    //genera la tabla de valores en las iteraciones de punto fijo: está programado a detenerse
    //al encontrar el punto en que g(x) = x, de otra manera continua hasta 75 iteraciones
    //encabezado de la tabla
    cout << "\n\n\t i\t p\t f(p)\t e" << endl
         << "\t------------------------------";

    double previo = 0.0;

    for(i = 0; i < 75; i++)
    {

        cout << "\n\t" << i + 1 << "\t" << p << "\t" << eval(F, p);
        //si llega a g(x) == x, o dentro del margen de error
        if( (eval(G, p) == p) || (e > abs((p - previo)/p)) )
        {
            break;  //termina de iterar, y ahí acaba el problema
        }
        else
        {
            p = eval(G, p);   //de otra manera, sigue iterando!!!
        }

        if(i == 74)
        {
            cout << "\n\nLimite de 75 iteraciones alcanzado SIN SOLUCION" << endl;
            system("PAUSE");
            return 0;
        }
    }

    //muestra un mensaje en pantalla adecuado
    cout << "\n\nRaiz de la ecuacion: " << p << endl;

    //espera a que se presione una tecla antes de terminar la ejecución
    system("PAUSE");

    //termina la ejecución del programa
    return 0;
}

//por motivos de presentación de informacion en pantalla
void imprimeEncabezado()
{
    cout << "\t\t   Resolucion de raices de ecuaciones" << endl
         << "\t\t    Metodo de Iteracion de Punto Fijo" << endl
         << "\t\t     Jose Alfredo Gallegos Chavarria" << endl
         << "\t\t           (Marzo 16, 2012)\n" << endl;
}

//funcion para mostrar información util al usuario al momento de empezar a capturar datos
void imprimeInstrucciones()
{
    cout << "\nEntre la ecuacion a resolver en forma canonica f(x) = 0, \n"
         << "por ejemplo, para la ecuacion... " << endl
         << "\n\t2x^3 - 2x^2 + x = 1\n" << endl
         << "...ud. entraria los siguientes datos con tabulacion entre coeficientes " << endl
         << "y un salto de linea al final..." << endl
         << "\t2\t-2\t1\t-1\n" << endl
         << ">> ";
}

//prototipo y definicion de la funcion para la evaluacion de la derivada
//evalua una funcion derivada, con coeficientes en der[] en donde el valor del indice en cada
//locacion del arreglo implica la potencia de la variable a que multiplica el coeficiente
//sustituyendo plug en cada caso
double eval(double der[], double plug)
{

    int j = 0;
    double total = 0;

    for(j = n; j >= 0; j--)
    {
        total = total + (der[j] * pow(plug, j));
    }

    return total;
}
