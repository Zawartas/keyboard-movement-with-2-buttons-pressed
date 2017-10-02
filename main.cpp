#include <iostream>
#include <thread>
#include <conio.h>

using namespace std;

void button1(bool & pressedUP, bool & pressedRIGHT)
{
        pressedUP = false;
    pressedRIGHT = false;
    unsigned char button;

    button = getch();
    if (button == 224)
    {
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
    }
    //else
        //cout <<"First thread: Other button\n";
}

void button2(bool & pressedUP, bool & pressedRIGHT)
{
        pressedUP = false;
    pressedRIGHT = false;
    unsigned char button;

    button = getch();

    if (button == 224)
    {
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
    }
   // else
        //cout <<"Second thread: Other button\n";
}

void sensor (bool & gameIsRunning, bool & pressedUP, bool & pressedRIGHT){

    while (gameIsRunning)
    {
        if (pressedRIGHT == true && pressedUP == true)
            cout << "COMBO!!!" << endl;
    }

}

int main()
{
    bool pressedUP;
    bool pressedRIGHT;
    bool gameIsRunning = true;

    thread (sensor, ref(gameIsRunning), ref(pressedUP), ref(pressedRIGHT)).detach();

    do
    {


    thread first (button1, ref(pressedUP), ref(pressedRIGHT));
    thread second (button2, ref(pressedUP), ref(pressedRIGHT));

        first.join();
        second.join();

    }
    while (1);

    return 0;
}
