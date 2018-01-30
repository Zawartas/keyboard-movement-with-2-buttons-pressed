#include <iostream>
#include <thread>
#include <conio.h>
#include <ctime>

using namespace std;
void wait (int);
void signal(int&);

int main(){
//    bool gameIsRunning = true;
    static int j = 0;
//    static queue<int> kolejka;

thread first (signal, ref(j));
thread second (signal, ref(j));

first.join();
second.join();
        
    return 0;
}


void wait (int i){
    int start = clock();
    while (clock() < start + i){}}

void signal(int & j){
    unsigned char key;

    while (key != 'q'){
        key = getch();
        if (key == 224){
            key = getch();
            switch(key){
                case 72:
                    j += 4;
                    break;
                case 77:
                    j += 5;
                    break;
                case 80:
                    j += 7;
                    break;
                case 75:
                    j += 10;
                    break;
            }
        }
    wait(25);

    if (j == 4) {cout << "Up\n"; j = 0;}
    else if (j == 5) {cout << "Right\n"; j = 0;}
    else if (j == 7) {cout << "Down\n"; j = 0;}
    else if (j == 10) {cout << "Left\n"; j = 0;}
    else if (j == 9) {cout << "Up_Right\n"; j = 0;}
    else if (j == 11) {cout << "Up_Down\n"; j = 0;}
    else if (j == 14) {cout << "Up_Left\n"; j = 0;}
    else if (j == 12) {cout << "Down_Right\n"; j = 0;}
    else if (j == 15) {cout << "Right_Left\n"; j = 0;}
    else if (j == 17) {cout << "Down_Left\n"; j = 0;}

}}
