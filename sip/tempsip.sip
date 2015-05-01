template <T>
class tempsip
{
%TypeHeaderCode
#include "tempsip.h"
%End

public:
    tempsip(T v);
    void print();
};
