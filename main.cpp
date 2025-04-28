#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include "patternh.h"
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;


enum class mobileColor: int
{
    Black,
    Yellow,
    White,
    Green
};

enum class TargetEnum: int
{
    gamers,
    photographers,
    businessman,

    aesthetics

    None
};

class TargetStrategy{
public:
    virtual ~TargetStrategy(){}
    virtual void target() =0;
};









int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
