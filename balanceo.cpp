#include <iostream>
#include <string>
#include <stdlib.h>

//uso de logica de stack pero modificada para el menu

using namespace std;

struct nodo{
      char dato;
      struct nodo *sgte;
};

typedef struct nodo *Stack;

/*                      Crear Nodo
--------------------------------------------------------------------*/

Stack crearNodo(char x){
      Stack newNodo = new(struct nodo);
      newNodo->dato = x;
      return newNodo;
}

/*                      Apilar
--------------------------------------------------------------------*/
void push(Stack &top, char x){
     Stack aux = crearNodo(x);
     aux->sgte = top;
     top = aux;
}

/*                      Desapilar
---------------------------------------------------------------------*/
char pop(Stack &top){
     int c ;
     Stack aux;
     
     aux = top ;
     c = aux->dato;   // asignamos el primer vamor de la pila en pila de caracteres
     top = aux->sgte ;
     delete(aux);
     return c;
}
/*                      funcion de balanceo de simbolos de agrupacion
---------------------------------------------------------------------*/
void balanceoSimbolos( Stack &p, string cad)
{
     Stack aux;
     int i = 0;
     
     while( cad[i] != '\0')
     {
            if( cad[i]=='(' || cad[i]=='[' || cad[i]=='{' )
            {
                 push( p, cad[i] );          
            }
            else if( cad[i]==')' || cad[i]==']' || cad[i]=='}' )
            {
                 aux = p;
                 
                 if(aux!=NULL)
                 {
                      if( cad[i]==')' )
                      {
                           if( aux->dato == '(')
                              pop( p );
                      }
                      else if( cad[i]==']' )
                      {
                           if( aux->dato == '[')
                              pop( p );
                      }
                      else if( cad[i]=='}' )
                      {
                           if( aux->dato == '{')
                              pop( p );
                      }        
                 }
                 else
                     push( p, cad[i] );
            }
            i++;           
     }
     
     if(p==NULL)
         cout<<"\n\tBalanceo CORRECTO..."<<endl;
     else
         cout<<"\n\t Balanceo INCORRECTO, faltan simbolos de agrupacion..."<<endl;          
     
     
}

/*                   FUNCION PRNCIPAL
-------------------------------------------------------------------*/

int main()
{
    Stack pila = NULL;    // creando Pila
    string cad;
    
    cout<<"\n\t\tBALANCEO\n\n";
    cout<<" Ejemplo: \n\n";
    cout<<"      { [ x+y] + z + (a+b) }   Balanceo Correcto  "<<endl;
    cout<<"      { [ x+y + z + (a+b) }    Balanceo Incorrecto "<<endl<<endl;
    
    cout << " Dar cadena de parentesis: ";
    getline(cin, cad);
    
    balanceoSimbolos( pila, cad );
    
    cout<<"\n\n";
    system("pause");
    return 0;
}