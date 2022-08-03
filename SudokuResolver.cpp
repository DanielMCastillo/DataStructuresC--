#ifndef __SUDOKU_RESOVER_HPP__
#define __SUDOKU_RESOVER_HPP__

#include <vector>
#include <utility>
#include "matriz.hpp"

namespace ed {


std::vector<int> posibil(Matriz<int> &s, int pi, int pj)
{
    std::vector<int> p;
    static const int  sub_ini[] = { 1 , 4,  7};
    static const int  sub_end[] = { 3 , 6,  9};

    p.reserve(9);
    for ( int n =1; n <=9; n++) {
        int i = 1;
        //Busqueda fila
        while ( i <= s.darColumnas() && s(pi,i) != n  )
            ++i;
        if ( i > s.darColumnas() ) {
            i = 1;
           //Busqueda en columna
           while ( i <= s.darFilas() && s(i,pj) != n )
             ++i;
           if ( i > s.darFilas()) {
             //Busqueda en la submatriz
             bool encontre_n = false;
             int submi = (pi-1)/ 3;
             int submj = (pj-1)/ 3;
             for ( i = sub_ini[submi]; i <= sub_end[submi];  i++) {
                for ( int j = sub_ini[submj]; j <= sub_end[submj];  j++)
                    if ( s(i,j) == n ) {
                       encontre_n = true;
                       break;
                    }
                if ( encontre_n )
                    break;
             }
             if ( !encontre_n)
                p.push_back(n);
           }
        }
    }

    return p;

}

std::pair<int,int> sigcasilla(Matriz<int> &s)
{
     for ( int i = 1; i <= s.darFilas(); i++)
        for ( int j = 1; j <= s.darColumnas(); j++)
            if ( s(i,j) == 0)
              return std::pair<int,int>(i,j);

    return std::pair<int,int>(-1,-1);
}


bool resolver(Matriz<int> &s)
{
    std::vector<Matriz<int>* > vtableros;
    vtableros.reserve(100);
    vtableros.push_back( new Matriz<int>(s));

    bool solucion = false;

    while (vtableros.size() > 0 ) {
    Matriz<int>* ulttablero = vtableros.back();
    std::pair<int,int> cs = sigcasilla(*ulttablero);

    if ( cs.first == -1) {
        s = *ulttablero;
        solucion = true;
        break;
    }
    std::vector<int> vposib = posibil(*ulttablero,cs.first,cs.second);
    //NO TIENE SOLUCION
    if ( vposib.size() == 0 ) {
        vtableros.pop_back();
        delete  ulttablero;
    }
    if ( vposib.size() == 1 ) {
        (*ulttablero)(cs.first,cs.second) = vposib[0];
    }
    if ( vposib.size() > 1 ) {
        (*ulttablero)(cs.first,cs.second) = vposib[0];
        for ( size_t i = 1; i < vposib.size(); i++) {
            Matriz<int> *newtab = new Matriz<int>(*ulttablero);
            (*newtab)(cs.first,cs.second) = vposib[i];
            vtableros.push_back(newtab);
        }
    }
    }
    for ( size_t i = 0; i < vtableros.size(); i++) {
       delete vtableros[i];
    }

    return solucion;
}

}

#endif