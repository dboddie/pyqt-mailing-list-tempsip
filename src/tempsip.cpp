#include "tempsip.h"
#include <iostream>
using namespace std;
template<typename T>
tempsip<T>::tempsip(T v)
{
    var = v;
}

template<typename T> void tempsip<T>::print()
{
    cout << var << endl;
}
template class tempsip<string>;
template class tempsip<double>;
