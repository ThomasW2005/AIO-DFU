#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char **argv)
{
    std::string mcu = "atmega32u4";
    int eraseStatus, flashStatus, startStatus;
    if (argc != 3)
    {
        std::cerr << "\033[91;1;1mInvalid Arguments\033[0;0;0m:\n\n\t1st Argument should be location of dfu-programmer.exe (including .exe)\n\t2nd Argument should be location of hex file (usually ${TARGET_OUTPUT_DIR}${PROJECT_NAME})\n\n\tFor Example: \033[96;1;1m\"C:\\dfu-programmer-win-0.7.2\\dfu-programmer.exe\" ${TARGET_OUTPUT_DIR}${PROJECT_NAME}\033[0;0;0m" << std::endl;
        return -1;
    }
    std::string helper = argv[1];
    std::string programmer = "\"" + helper + "\"";
    putchar(218);
    if (eraseStatus = system((programmer + " " + mcu + " erase --force").c_str()))
    {
        putchar(192);
        std::cout << "\033[91;1;1mError\033[0;0;0m while erasing chip :( [exited with code \"" << eraseStatus << "\"]\n";
    }
    helper = argv[2];
    putchar(218);
    if (flashStatus = system((programmer + " " + mcu + " flash " + helper + ".hex").c_str()))
    {
        putchar(192);
        std::cout << "\033[91;1;1mError\033[0;0;0m while flashing chip :( [exited with code \"" << flashStatus << "\"]\n";
    }
    putchar(218);
    if (startStatus = system((programmer + " " + mcu + " start").c_str()))
    {
        putchar(192);
        std::cout << "\033[91;1;1mError\033[0;0;0m while starting MCU :( [exited with code \"" << startStatus << "\"]\n";
    }
    return eraseStatus + flashStatus + startStatus;
}