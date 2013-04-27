#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define max 4

using namespace std;

void algoritmo( int A[max], int n, int m);


int main()
{
    int n,m,sw, menu1;
    int A[max];
    cout << "     Bienvenido al Algoritmo de Seguridad de Estado       " << endl;
    cout << "----------------------------------------------------------" << endl << endl << endl;
    cout << "Ingrese el cantidad de procesos(maximo 10):" << endl;
    cin >> n;
    if( n>1 && n<11)    //debe ser superior a 2, para poder determinar el algoritmo de estado, y menor que 11 porque ese es el limite
    {
        cout << "Ingrese cantidad de recursos(maximo 4):" << endl;
        cin >> m;
        if( m>1 && m<5)     // la cantidad de recursos debe ser mayor a 1
        {
            cout << "Ingrese opcion a realizar" << endl << endl; //pueden haber 2 opciones. Se puede ingresar la instancia disponible o ingresar la instancia total.
            cout << "1) Si desea ingresar instancia disponible" << endl;
            cout << "2) Si desea ingresar instancia total" << endl;
            cin >> menu1;

            if(menu1==1)
            {
                cout << "Ingrese instancia disponible" << endl; //por medio de un arreglo se ingresa la instancia
            }
             else{
                    if(menu1==2)
                    {
                        cout << "Ingrese instancia total" <<endl; //por medio de un arreglo se ingresa la instancia total
                        //esta instancia hay qe transformarla a disponible
                    }
                    else
                    {
                        cout << "Esta opcion no es valida" << endl;
                    }


                }

        }
        else
        {
            cout << "Cantidad de recursos invalido" << endl;
        }
    }

    else
    {
        cout << "Cantidad de procesos invalido, intente nuevamente" << endl;
    }
    return 0;
}


void algoritmo( int A[max], int n, int m)  //se ingresa el arreglo con la instancia disponible, la cantidad de procesos y cantidad de recursos
{

}
