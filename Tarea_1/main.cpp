#include <conio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>

char validacion = ' ';

//Ejericio #1
bool numeroprimo(int N){
    int k, raiz;
    raiz = (int)sqrt(N);
    for (k = 2; N % k && k <= raiz; k++);
    if (k == raiz + 1)
        return 1;

    return 0; 

}
    int iteracion = 1;

    void numPrimo(int num) {
        char validacion = 1;

        std::cout << "Ejemplo:" << iteracion << " Numero: " << num << " = ";
        std::cout << "{ ";

        for (int i = 1; i <= num; i++)
            if (num % i == 0 && numeroprimo(i))
                std::cout << i << ",";

        std::cout << "}";
    }

//Ejercicio#2
int a2;
int binNum = 0;
int tablam = 0;
int residuo;
int tabla[8];

void numeroBinario(int almacenador) {
    a2 = almacenador;

    while (almacenador != 0)
    {
        residuo = almacenador % 2;
        almacenador = almacenador / 2;
        tablam++;
    }

    tablam--;
    almacenador = a2;
    tabla[0] = tabla[tablam];

    while (almacenador != 0)
    {
        residuo = almacenador % 2;
        almacenador = almacenador / 2;
        tabla[binNum] = residuo;
        binNum++;
    }

    binNum--;
    std::cout << "Su numero en binario es: ";

    while (binNum >= 0)
    {
        std::cout << tabla[binNum] << " ";
        binNum--;
    }
}

//Ejercicio #3
const int MAX = 1000;
int f[MAX] = { 0 };
int n;


int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (f[n] = 1);

    if (f[n])
        return f[n];

    int k = (n & 1) ? (n + 1) / 2 : n / 2;
    f[n] = (n & 1) ? (fibonacci(k) * fibonacci(k) + fibonacci(k - 1) * fibonacci(k - 1))
        : (2 * fibonacci(k - 1) + fibonacci(k)) * fibonacci(k);

    return f[n];
}
void printfibo(int n) {
    int t1 = 0;
    int t2 = 1;
    int nextTerm = 0;
    for (int i = 1; i <= n; ++i)
    {

        if (i == 1)
        {
            std::cout << " " << t1 << " ";
            continue;
        }
        if (i == 2)
        {
            std::cout << t2 << " ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        
        std::cout << nextTerm << " ";
    }
}


int sumaFibo(int m)
{
    return fibonacci(m + 1) - 1;
}

int main() {
    int opcion;

    do{
        std::cout << "\n\n*** Bienvenido a ACTIVIDAD 1 ***\n\n"
            "1. Numeros primos\n"
            "2. Numero Binario\n"
            "3. Fibonacci\n"
            "4. Salir del Programa\n"
            "Por favor ingrese una opcion:\n\n" ;
        std::cin >> opcion;
        switch (opcion){

            case 1: 
                do {
                    {
                        int num;
                        std::cout << "\nBienvenido a seccion Numeros primos.\n"
                            "Por favor ingrese un numero para ver sus factores primos:";
                        std::cin >> num;
                        numPrimo(num);
                        std::cout << "\n\nQuiere intentarlo de nuevo?(n o y): ";
                        std::cin >> validacion;
                        if (validacion == 'y')
                            iteracion++;
                    }
                } while (validacion == 'y');
                break;
            case 2: 
                    {
                        int almacenador;
                        std::cout << "Bienvenido a Seccion Numeros Binarios.\n"
                            "Por favor ingrese el numero que quiere convertir a binario: ";
                        std::cin >> almacenador;
                        numeroBinario(almacenador);
                        break;
                    }
            case 3:
                char confirmacion = 'n';
                do {
                    {
                        std::cout <<"\nBienvenido a seccion Serie Fibocci.\n" "Ingrese numero de series Fibonacci que quiere imprimir: ";
                        std::cin >> n;
                        printfibo(n);
                        std::cout << "\nSuma de serie Fibonacci: "
                            << sumaFibo(n);

                        std::cout << "\n\nDesea intentarlo de nuevo? (n o y): \n";
                        std::cin >> confirmacion;
                        
                    }
                } while (confirmacion == 'y');
                break;
            }
        
    } while (opcion != 4);
    std::cout << "Espero le haya gustado el programa Ingeniero! Pase buen dia/noche.";
}

