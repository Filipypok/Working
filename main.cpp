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
    Blue,
    White,
    Green
};

enum class TargetEnum: int
{
    Gamers,
    Photographers,
    Businessman,

    Aesthetics,

    None
};

class TargetStrategy{
public:
    virtual ~TargetStrategy(){}
    virtual void target() =0;
};

class GamersTargetStrategy: public TargetStrategy
{
    void target() {cout<<"Let's go play PUBG";}

};
class PhotographersTargetStrategy: public TargetStrategy
{
    void target() {cout<< "I like take a beautiful photo";}
};
class BusinessmanTargetStrategy: public TargetStrategy
{
    void target() {cout<< "I very-very rich";}
};
class AestheticsTargetStrata : public TargetStrategy
{
    void target() {cout<< "I love a vibe phone";}
};


TargetStrategy *CreateTargetStrategy(TargetEnum targetManner)
{
    switch(targetManner)
    {
        case TargetEnum::Gamers: return new GamersTargetStrategy;
        case TargetEnum::Photographers: return new PhotographersTargetStrategy;
        case TargetEnum::Businessman: return new BusinessmanTargetStrategy;

        //2 вариант
        case TargetEnum::Aesthetics: return new AestheticsTargetStrata;

        default: return nullptr;
    }
}


class Smartfone {
private:
    int battery;
    mobileColor smartcolor;
    TargetStrategy *targetManner;

    void DoTargetUsingStrategy()
    {
        if(targetManner==nullptr)
        {
            cout<<"Don't buy!";
            return;
        }
        else
        {
            targetManner -> target();
        }
    }
    void DetectedhavefiveG()
    {
        if(havefiveG())
        {
            cout<<"very good!";
        }
        else
        {
            cout<<"nooo";
        }
    }

protected:
    bool FiveG;
public:
    mobileColor GetColor() const {return smartcolor;}

    int Getbattery() const {return battery;}

    virtual void printType()=0;

    virtual void Case() = 0;

    Smartfone(mobileColor color) : battery(3470), smartcolor(color), screen(9), /*children*/ targetManner(nullptr)
    {
        fiveG = static_cast<bool>(rand()%2);
    }
    ~Smartfone()
     {
         if (targetManner != nullptr) delete targetManner;
     };

public:
    int screen;

    bool havefiveG() const {return fiveG;}

    virtual void checking()
    {
        if(havefiveG())
        {
            cout<<"It's very cool and modern smartfone";
        }
        else
        {
            cout<<"It's not a very cool and modern smartfone";
        }
    }
    void target()
    {
        printType();
        cout<<":"
        DetectedhavefiveG();
        cout<< ":";

        checking();
        cout<< " : ";
        DoTargetUsingStrategy();
        cout<<"\n";
    }
    void SetTargerManner(TargetStrategy *TargManner)
    {
        targetManner = TargManner;
    };
};






int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
