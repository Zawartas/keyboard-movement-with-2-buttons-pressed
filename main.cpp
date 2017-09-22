#include <iostream>
#include <thread>
#include <conio.h>

using namespace std;

void button1(bool & pressedUP, bool & pressedRIGHT)
{
    unsigned char button;

    button = getch();
    if (button = 224)
        button = getch();

    if (button == 72)
    {
        pressedUP = true;
        cout << "First thread: UP\n";
    }
    else if (button == 77)
     {
        pressedRIGHT = true;
        cout << "First thread: RIGHT\n";
    }
    else
        cout <<"First thread: Other button\n";
}

void button2(bool & pressedUP, bool & pressedRIGHT)
{
    unsigned char button;

    button = getch();
    if (button == 72)
    {
        pressedUP = true;
        cout << "Second thread: UP\n";
    }
    else if (button == 77)
     {
        pressedRIGHT = true;
        cout << "Second thread: RIGHT\n";
    }
    else
        cout <<"Second thread: Other button\n";
}

void buttonLEFT(bool & pressedLEFT)
{

}

void buttonDOWN(bool & pressedDOWN)
{

}

int main()
{
    do
    {
    bool pressedUP = false;
    bool pressedRIGHT = false;

    thread first (button1, ref(pressedUP), ref(pressedRIGHT));
    thread second (button2, ref(pressedUP), ref(pressedRIGHT));

        first.join();
        second.join();
        // moze 3 watek z timerem i jesli nacisniecie nie pojawi sie w ciagu sekundy to bedzie konczyc cykl ?
        if (pressedUP && pressedRIGHT)
            cout << "\nUP_RIGHT\n";
    }
    while (1);

    return 0;
}
