#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define max 4

using namespace std;

void algoritmo( int a[max],int c[][max],int d[][max], int n, int m) ;
void llenarasignacion( int A[][max], int n, int m);
void llenarmaximo( int A[][max], int n, int m);
void llenadoarreglo(int a[max], int m);
void necesidad(int a[][max], int b[][max],int c[][max], int n, int m);
int compara(int a[][max], int b[][max], int n, int m);
void mostrar(int a[][max],int n,int m);
void mostrara(int a[max],int n);
void disponible(int e[max], int g[max], int f[max], int m);
void sumamatriz(int a[][max], int c[max], int n, int m);



int main()
{
    int n, m, menu1, comp;
    int A[max]; //contiene el disponible
    int B[max][max]; //contiene las asignaciones
    int C[max][max]; //contiene los maximos
    int D[max][max];    //contiene la necesidad
    int E[max]; //contiene el total
    int F[max]; //contiene el disponible, pero calculado del total
    int G[max]; //contiene la suma de las columnas de la matriz de asignaciones

    cout << "     Bienvenido al Algoritmo de Seguridad de Estado       " << endl;
    cout << "----------------------------------------------------------" << endl << endl << endl;
    cout << "Ingrese el cantidad de procesos(maximo 10):" << endl;
    cin >> n;
    if( n>1 && n<11)    //debe ser superior a 2, para poder determinar el algoritmo de estado, y menor que 11 porque ese es el limite
    {
        cout << "Ingrese cantidad de recursos(maximo 4):" << endl;
        cin >> m;
        system("cls");
        if( m>1 && m<5)     // la cantidad de recursos debe ser mayor a 1
        {
            cout << "Ingrese opcion a realizar" << endl << endl; //pueden haber 2 opciones. Se puede ingresar la instancia disponible o ingresar la instancia total.
            cout << "1) Si desea ingresar instancia disponible" << endl << endl;
            cout << "2) Si desea ingresar instancia total" << endl;
            cin >> menu1;

            system("cls");
            if(menu1==1)
            {
                cout << "Ingrese instancia disponible" << endl; //por medio de un arreglo se ingresa la instancia
                cout << "-----------------------------" << endl;
                llenadoarreglo(A,m); //llena la instancia disponible con un arreglo
                system("cls");
                llenarasignacion(B,n,m); //llena las instancias de asignacion en una matriz
                system("cls");
                llenarmaximo(C,n,m);  //llena la instancia maxima
                system("cls");
                comp = compara(B,C,n,m);  //compara las instancias maximas con las asignadas
                if(comp ==1) //si la comparacion es valida, retona 1, por lo tanto continua el procedimiento
                {
                    necesidad(B,C,D,n,m);  //crea las instancias necesidad

                }
                else //si es distinto de 1, no es valida la comparacion, por lo tanto sale
                {
                    cout << "datos incorrectos, la instancia maxima no puede ser menor a la asignada" << endl;

                }



            }
             else{
                    if(menu1==2)
                    {
                        cout << "Ingrese instancia total" <<endl; //por medio de un arreglo se ingresa la instancia total
                        llenadoarreglo(E,m);  //llena en un arreglo las instancia total
                        llenarasignacion(B,n,m);  //llena las instancias de asignacion
                        sumamatriz(B,G,n,m);  //Suma las columnas de la matriz de asignacion
                        disponible(E,G,F,m);  //a partir de las anteriores se crea la instancia disponible con la sgte formula  disponible=total de instancias-suma columnas de matriz de asignaciom
                        mostrara(F,m); //muestra la isntancia disponible

                    }
                    else
                    {
                        cout << "Esta opcion no es valida" << endl; //no existe otra opcion, solo se puede ingregar la instancia disponible o total
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


void algoritmo( int a[max],int c[][max],int d[][max], int e[max], int n, int m)  //se ingresa el arreglo con la instancia disponible,matriz de maximo y necesidad, la cantidad de procesos y cantidad de recursos
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {

        }
    }

}


void sumamatriz(int a[][max], int c[max], int n, int m)
{
    int suma=0;
    for(int j=1; j<=m; j++)
    {
        for(int i=1; i<=n; i++)
        {
            suma= a[i][j] + suma;
        }
        c[j] = suma;
        suma=0;
    }
}


void disponible(int e[max], int g[max], int f[max], int m)
{
    for(int i=1; i<=m; i++)
    {
        if(e[i]>=g[i])
        {
            f[i] = e[i] - g[i];
        }
        else
        {
            cout << "datos incorrectos, la suma de las instancias de asignacion no debe superar la instancia total" << endl;
        }
    }
}

void llenarasignacion( int A[][max], int n, int m) // se llena la matriz con las instancias para la asignacion
{
    int i,j;
    int dato = 0;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++ )
        {
            cout << "Llenado de asignacion" << endl;
            cout << "--------------------------" << endl;
            cout << "Ingrese un valor para Proceso: " << i << ", recurso: " << j <<endl;
            cin >> dato;
            if( dato<= 10 && dato >=0)
            {
                A[i][j] = dato;
            }
            else
            {
                cout << "Instancia supera el numero maximo" << endl;
            }

        }
    }
}


void llenarmaximo( int A[][max], int n, int m) // se llena la matriz con las instancias para el maximo
{
    int i,j;
    int dato = 0;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++ )
        {
            cout << "Llenado de maximo" << endl;
            cout << "-------------------" << endl;
            cout << "Ingrese un valor para Proceso: " << i << ", recurso: " << j <<endl;
            cin >> dato;
           if( dato<= 10 && dato >=0)
            {
                A[i][j] = dato;
            }
            else
            {
                cout << "Instancia supera el numero maximo" << endl;
            }
        }
    }
}

void llenadoarreglo(int a[max], int m) // se llena el arreglo con el disponible o sirve para el llenado de las instancias totales
{
    int i,j, num;
    for(i=1; i<=m; i++)
    {

            cout << "Ingrese valor para recurso: "  << i <<endl;
            cin >> num;
            if( num<= 10 && num >=0)
            {
                    a[i] = num;
            }
            else
            {
                    cout << "Instancia supera el numero maximo" << endl;
            }

    }
}


void necesidad(int a[][max], int b[][max],int c[][max], int n, int m) //determina la matriz necesidad
{
    int i,j;
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
        {
            c[i][j] = b[i][j] - a[i][j];
        }
    }
}


int compara(int a[][max], int b[][max], int n, int m) //verifica si maximo es mayor que asignacion, para que no existan numeros negativos
{
   int i,j,o;
   o=0;
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
        {
            if(b[i][j]>= a[i][j] )
            {
                o=1;
            }
        }
    }
    return o;
}


void mostrar(int a[][max],int n,int m)
{
     int i,j;
     for(i=1;i<=n;i++)
     {

        for(j=1;j<=m;j++)
         {
         cout << "numero: "<< i << ", " << j << ": " << a[i][j] << endl;
         }
     }
}

void mostrara(int a[max],int n)
{
     int i,j;
     for(i=1;i<=n;i++)
     {

         cout << "numero: "<< i << ": " << a[i] << endl;

     }
}
