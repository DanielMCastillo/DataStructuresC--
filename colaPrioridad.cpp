#include <iostream>
#include <queue>
#include<stdlib.h>
using namespace std;
int colaprioridad_display(priority_queue <int> colaprioridad);

int main (){
    priority_queue <int> colaprioridad;
    int num, choice;
    cout <<" 1 - Insertar elemento en la cola" <<endl;
    cout <<" 2 - Borrar primer elemento" <<endl;
    cout <<" 3 - Desplegar cola" <<endl;
    cout <<" 4 - Desplegar elemento de prioridad más alto" <<endl;
    cout <<" 5 - Salir" <<endl;
    while (1)
    {
        cout <<endl<< "Selecciona una opcion : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Ingresa un valor que se insertara : ";
            cin >> num;
            colaprioridad.push(num);
            break;
        case 2:
            cout << "El primer elemento " << colaprioridad.top() <<" ha sido eliminado de la cola" <<endl;
            colaprioridad.pop();
            break;
        case 3:
            colaprioridad_display(colaprioridad);
            break;
        case 4:
            cout <<"El elemento con prioridad más grande es  " << colaprioridad.top() <<endl;
            break;
        case 5:
            exit(0);
        default:
            cout << "Opcion incorrrecta, ingresa otra opcion";
        }
    }
    return 0;
}

int colaprioridad_display(priority_queue <int> colaprioridad){
    while (!colaprioridad.empty())
    {
        cout <<colaprioridad.top() <<'\t' ;
        colaprioridad.pop();
    }
    cout << '\n';
    return 0;
}
