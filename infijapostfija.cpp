#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


bool isDouble(const string &s){
    std::istringstream iss(s);
    double d;
    return iss >> d >> std::ws && iss.eof();
}

/*
    Impplementar la funcion que transforma la expresion 
    infija como cadena a postija utlizando el stack implementado 
    en clase. 

    string infijaAPostfija(string &exp);
*/

string infijaAPostfija(string &exp){
    
}




int main(){
    string exp = "24.7e-2+(35+*7.33)*9.5";
    /* 2 token 
    +
    3
    7
    */
   regex r("[\\d.]+(?:e-?\\d+)?|[\\D]");
   vector<string> tokens;
   sregex_token_iterator inicio(exp.begin(), exp.end(), r), fin;

    std::copy(inicio, fin, back_inserter(tokens));
    
    for(auto &i: tokens){
        cout << "Elem: " << i << " is operando: " << std::boolalpha << isDouble(i) << endl;
    }

/*
    Operador Operando
    Unitario

    Resta o es unario? es ambiguo

    Utilizar ~ este si,bolo como operador unario

        Está bien escrito? ~~~5
*/

    return 0;
}