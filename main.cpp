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
        if(haveFiveG())
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
        FiveG = static_cast<bool>(rand()%2);
    }
    ~Smartfone()
     {
         if (targetManner != nullptr) delete targetManner;
     };

public:
    int screen;

    bool haveFiveG() const {return FiveG;}

    virtual void checking()
    {
        if(haveFiveG())
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
        cout<<":";
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



class chipmobile : public Smartfone
{
protected:
    int think;
public:
    chipmobile() : Smartfone(mobileColor:: Blue) {SetTargerManner(CreateTargetStrategy(TargetEnum::Gamers));}
    ~chipmobile() {}

    void printType()  {cout<<"Chip mobile";}
    void Case() {cout<<"Plastic case";}
    void screen()  {cout<<"screen";}
};

class simplemobile : public Smartfone
{
protected:
    bool medage;
public:
    simplemobile() : Smartfone(mobileColor:: White) {SetTargerManner(CreateTargetStrategy(TargetEnum:: Photographers));}

    ~simplemobile() {}

    void printType() {cout<<"Simple mobile";}
    void Case() {cout<<"Metal case";}
    void screen() {cout<<"screen";}

};

class expensiveMobile : public Smartfone
{
public:
    expensiveMobile() : Smartfone(mobileColor::Black) {SetTargerManner(CreateTargetStrategy(TargetEnum::Businessman));}
    ~expensiveMobile() {}
    void printType() {cout<< "Expensive mobile";}
    void Case() {cout<<"Premium case";}
    void screen() {cout<<"screen";}
};




enum class SmartfoneType : int
{
    expensiveMobile = 1,
    simplemobile = 2,
    chipmobile = 3,

    Undefined = 0
};

Smartfone* CreateSmartfone(SmartfoneType i)
{
    Smartfone* newSmartfone = nullptr;

    if(i==SmartfoneType::chipmobile)
    {
        newSmartfone = new chipmobile;
    }

    else if (i==SmartfoneType::simplemobile)
    {
        newSmartfone = new simplemobile;
    }
    else if (i == SmartfoneType::expensiveMobile)
    {
        newSmartfone = new expensiveMobile;
    }
    return newSmartfone;
}

void AllGetMoney(Iterator<Smartfone*>* it)
{
    for (it ->First(); !it->IsDone(); it->Next())
    {
        Smartfone* currentSmartfone = it->GetCurrent();
        currentSmartfone->checking();
    }
}

void TargetEmAll(Iterator<Smartfone*> *it)
{
    for(it->First(); !it->IsDone(); it->Next())
    {
        Smartfone *currentSmartfone = it->GetCurrent();
        currentSmartfone -> target();
    }
}

void TargetEmAllGood(Iterator<Smartfone*> *it)
{
    for(it->First(); !it->IsDone(); it->Next())
    {
        Smartfone *currentSmartfone = it->GetCurrent();
        if(!currentSmartfone->haveFiveG()) continue;

        currentSmartfone->target();
    }

}

void TargetEmAllBlue(Iterator<Smartfone*> *it)
{
    for(it->First(); !it->IsDone(); it->Next())
    {
        Smartfone *currentSmartfone = it->GetCurrent();
        if(currentSmartfone->GetColor() != mobileColor::White) continue;


        currentSmartfone->target();
    }

}


class SmartfoneColorDecorator : public IteratorDecorator<class Smartfone*>
{
private:
    mobileColor TargetColor;
public:
    SmartfoneColorDecorator(Iterator<Smartfone*>* it, mobileColor color)
        : IteratorDecorator<Smartfone*>(it), TargetColor(color) {}

    void First()
{
    this->It->First();
    while (!this->It->IsDone() && It->GetCurrent()->GetColor() != TargetColor)
    {
        this->It->Next();
    }
}

    void Next()
{
    do
    {
        this->It->Next();

    } while (!this->It->IsDone() && It->GetCurrent()->GetColor() != TargetColor);
}
};

class SmartfoneFiveGDecorator : public IteratorDecorator<class Smartfone*>
{
private:
    bool TargetGood;
public:
    SmartfoneFiveGDecorator(Iterator<Smartfone*>* it, bool FiveG) : IteratorDecorator<Smartfone*>(it), TargetGood(FiveG) {}

    void First()
{
    this->It->First();
    while (!this->It->IsDone() && this->It->GetCurrent()->haveFiveG() != TargetGood)
    {
        this->It->Next();
    }

}
    void Next()
{
    do
    {
        this->It->Next();

    } while (!this->It->IsDone() && this->It->GetCurrent()->haveFiveG() != TargetGood);
}
};


int main()
{
    srand(time(nullptr)); // Инициализация генератора
    int N = 5;

    StackClass<Smartfone*> SmartfoneStack;

    for(size_t i = 0; i < N; i++)
    {
        int Smartfone_num = rand() %3+1;
        SmartfoneType smartfone_type = static_cast<SmartfoneType>(Smartfone_num);
        Smartfone* newSmartfone = CreateSmartfone(smartfone_type);
        SmartfoneStack.Push(newSmartfone);
    }

    cout<< "size steck smartfone: "<< SmartfoneStack.Size() << endl;

    Iterator<Smartfone*>* it2 = SmartfoneStack.GetIterator();

    cout<<endl;

    Array<Smartfone*> SmartfoneArray;
    for (size_t i = 0; i < N; i++)
    {
        int Smartfone_num = rand() %3+1;
        SmartfoneType smartfone_type = static_cast<SmartfoneType>(Smartfone_num);
        Smartfone* newSmartfone = CreateSmartfone(smartfone_type);
        SmartfoneArray.Add(newSmartfone);
    }

        wcout << "size array smartfone: " << SmartfoneStack.Size() << endl;


    cout << "" << endl;
    list<Smartfone*> SmartfoneVector;
    for (size_t i = 0; i < N; i++)
    {
        int Smartfone_num = rand() % 3 + 1;
        SmartfoneType smartfone_type = static_cast<SmartfoneType>(Smartfone_num);
        Smartfone* newSmartfone = CreateSmartfone(smartfone_type);
        SmartfoneVector.push_back(newSmartfone);
    }

    cout << "Stack class";

        cout << endl << "size stack: " << SmartfoneStack.Size() << endl;
        Iterator<Smartfone*> *it7 = SmartfoneStack.GetIterator();
        TargetEmAll(it7);
    cout << endl << "Black Smartfone have 5G:" << endl;
        Iterator<Smartfone*>* FiveGSkinIt = new SmartfoneFiveGDecorator(new SmartfoneColorDecorator(SmartfoneStack.GetIterator(),mobileColor::Black), true);
        TargetEmAll(FiveGSkinIt);
        delete FiveGSkinIt;

    cout << "Array class" << endl;
    cout << endl << "Smartfone have 5G:" << endl;
    Iterator<Smartfone*>* FiveGIt = new SmartfoneFiveGDecorator(SmartfoneArray.GetIterator(), true);
    TargetEmAll(FiveGIt);
    delete FiveGIt;

    cout << endl << "black smartfones:" << endl;
    Iterator<Smartfone*>* SkinIt = new SmartfoneColorDecorator(SmartfoneArray.GetIterator(), mobileColor::Black);
    TargetEmAll(SkinIt);
    delete SkinIt;

    cout << endl << "black smartfone have 5G:" << endl;
    Iterator<Smartfone*>* haveFiveGIt =
        new SmartfoneFiveGDecorator(new SmartfoneColorDecorator(SmartfoneArray.GetIterator(), mobileColor::Black), true);
    TargetEmAll(haveFiveGIt);
    delete haveFiveGIt;

    cout << endl << "black smartfone  skin have 5G using adapted iterator (another container):" << endl;
    Iterator<Smartfone*>* adaptedIt = new ConstIteratorAdapter<std::list<Smartfone*>, Smartfone*>(&SmartfoneVector);
    Iterator<Smartfone*>* adaptedBlackIt = new SmartfoneFiveGDecorator(new SmartfoneColorDecorator(adaptedIt, mobileColor::Black), true);
    TargetEmAll(adaptedBlackIt);
    delete adaptedBlackIt;

    cout << "STL:" << endl;
    vector<Smartfone*> stlVector;
        for (int i = 0; i < 5; ++i) {
            int Smartfone_num = rand() % 3 + 1;
            SmartfoneType smartfone_type = static_cast<SmartfoneType>(Smartfone_num);
            Smartfone* newSmartfone = CreateSmartfone(smartfone_type);
            stlVector.push_back(newSmartfone);
    }

        Iterator<Smartfone*>* stlIt = new ConstIteratorAdapter<vector<Smartfone*>, Smartfone*>(&stlVector);
        TargetEmAll(stlIt);
        delete stlIt;
    return 0;
}




