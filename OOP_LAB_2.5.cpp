// main.cpp
#include "triangle.h"
#include <iostream>

int main() {
    Triangle triangle;

    triangle.Read();
    triangle.Display();

    triangle++;
    triangle.Display();

    triangle--;
    triangle.Display();

    return 0;
}
