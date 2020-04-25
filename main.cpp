#include <iostream>
#include <thread>

#include "header.h"


int main() {

    std::cout << "main.cpp loaded" << std::endl;

    std::thread gl_th(oglWindow);
    std::thread cv_th(ocvWindow);

    gl_th.detach();
    cv_th.join();

    return 0;
}
