#include <iostream>
#include "avl_tree.hpp"


using namespace std;
using namespace ed;

int main(){

    ed::AVLTree<int> *avl = 
    new nodet<int>(
    new nodet<int>
    (new nodet<int>(nullptr,3,nullptr),6,
                    new nodet<int>(nullptr,7,nullptr)),
    8,
        (new nodet<int>(new nodet<int>(nullptr,10,nullptr),12,
            new nodet<int>(nullptr,15,nullptr))
    ));

    avl = rotLeft(avl);

    //como probar ?? que se hizoo bein la rotacion

    cout << "Root:" << elem(avl) << endl;
    cout << "Right:" << elem(right(avl)) << endl;
    cout << "Left:" << elem(left(avl)) << endl;
    cout << "Left Right:" << elem(left(right(avl))) << endl;
    cout << "Altura:" << altura(avl) << endl;
    
    return 0;


}