#include <iostream>
#include "stack.hpp"

using namespace std;
using namespace ed;

int main(){
    //stack LIFO
    Stack <char> *s =  push(push(push(empty<char>(),'A'),'B'),'C');
//Stack
//  C|  <- TOPE
//  B|
//  A|   
//

    s = push(s,'D');

//Stack
//  D|
//  C|  <- TOPE
//  B|
//  A|   
//  

    cout << "Stack:\n\n" << s << endl;
    cout << "Tope \n\n" << top(s) << endl;
    
    s = pop(s);

    cout << "Stack:\n\n" << s << endl;

    cout << "Tope \n\n" << top(s) << endl;   

    return 0;
}