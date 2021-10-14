/*
Thomas Weichhart 3AHELS
06.10.2021 v2.1
ALl-in-one Wrapper for DFU-Programmer
*/

#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char **argv) //command-line arguments
{
    if (argc != 3) //check if correct amount of arguments get passed
    {
        std::cerr << "AIO-DFU v2.2\nInvalid Arguments:\n\n\t1st Argument should be location of dfu-programmer.exe (including .exe)\n\t2nd Argument should be location of hex file (usually ${TARGET_OUTPUT_DIR}${PROJECT_NAME})\n\n\tFor Example: \"C:\\dfu-programmer-win-0.7.2\\dfu-programmer.exe\" ${TARGET_OUTPUT_DIR}${PROJECT_NAME}" << std::endl;
        return -1;
    }

    int eraseStatus, flashStatus, startStatus;
    std::string mcu = "atmega32u4";   //mcu-type, constant for now
    std::string programmer = argv[1]; //convert the strings from the command-line (C-Style char arrays) to std::string's, just easier to work with
    std::string hexPath = argv[2];
    std::string command;
    programmer = "\"" + programmer + "\" ";

    command = programmer + mcu + " erase --force"; //execute the three flashing commands
    std::cerr << "Executing : \"" << command << "\" ->" << std::endl;
    eraseStatus = system(command.c_str());

    command = programmer + mcu + " flash " + hexPath + ".hex";
    std::cerr << "Executing : \"" << command << "\" ->" << std::endl;
    flashStatus = system(command.c_str());

    command = programmer + mcu + " start";
    std::cerr << "Executing : \"" << command << "\" ->" << std::endl;
    startStatus = system(command.c_str());

    return eraseStatus + flashStatus + startStatus; //return sum of return values, should be 0
}