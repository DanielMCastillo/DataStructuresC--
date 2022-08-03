#include <iostream>
#include "listls_ext.hpp"

using namespace std;
using namespace ed;

int pordos(int d){

    return 2*d;
}

int main(){

    


    ListLS<int> *ls = empty<int>();
    ls = cons(9,ls);
    ls = cons(10,ls);
    ls = cons(11,ls);


    cout << "ls: " << ls << endl;
    cout << "length ls:" << length(ls) << endl; 

    ListLS<int> *lsc = copy(ls);
    cout << "\ncopy(ls) lsc:" << lsc <<endl;

    ListLS<int> *lap = append(ls,lsc);
    cout << "\nlap(lap) lap:" << lap <<endl;


     ListLS<int> *lr = reverse(lap);
     cout << "\nreverse(lap) lr:" << lr <<endl;

    
     ListLS<int> *lm = map(pordos,ls);
     cout << "\nmap(lap) lm:" << lm <<endl;

    return 0;
}