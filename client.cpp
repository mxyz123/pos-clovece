#include <iostream>
#include <chrono>
#include <format>
#include <string>
#include "window.h"

int main()
{
    std::cout << "POS semestralka\n";

    Window* win = new Window();

    bool rn = true;
    int maxFps = 60;
    double interval = 1000000000 / (double)maxFps;
    double delta = 0;
    long prevTime = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    long currTime = 0;
    long timer = 0;
    long fps = 0;
    long count = 0;

    while(rn){
        if(!win->ProcessMessage()){
            std::cout << "exiting\n";
            rn = false;
        }
        currTime = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        timer += currTime - prevTime;
        delta += (currTime - prevTime) / interval;
        prevTime = currTime;
        if (delta >= 1 )
        {
            // TODO
            char str[256];
            sprintf(str, "%ld", fps);
            printf("FPS:%s\n", str);
            delta--;
            count++;
        }
        if(timer >= 1000000000)
        {
            fps = count;
            count = 0;
            timer = 0;
        }
    }
    delete win;
    return 0;
}