#include <iostream>
#include "window.h"

int main()
{
    std::cout << "POS semestralka\n";

    Window* win = new Window();
    bool rn = true;
    while(rn){
        if(!win->ProcessMessage()){
            std::cout << "exiting\n";
            rn = false;
        }
        Sleep(10);
    }
    delete win;
    return 0;
}