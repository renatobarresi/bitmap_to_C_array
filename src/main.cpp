/**
 * @file app.cpp
 * @author Renato Barresi (renatobarresi@gmail.com)
 * @brief A non bloated way of converting bmp to a plain, C array. 
 * @version 0.1
 * @date 2024-06-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include "main.h"
#include "parser.h"
#include "arrayGenerator.h"
#include <string>

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int
 * \todo validate input
 */
int main(int argc, char *argv[])
{   
    std::cout << "BMP to C array!" << "\n";

    std::string path = std::string(argv[1]);
    int sizeOfArray = int(*argv[2] - '0');
    arrayGenerator::sizeOfArray val;

    // Convert file contents to a bitstream
    arrayGenerator myArray;     // This object is used to generate the C array based on a bitstream
    parser myParser(path);      // This object is used to parse the contents of the file and convert it to a bitstream

    myParser.printFileData();

    // Convert bitstream to the specified C array
    switch (sizeOfArray)
    {
        case 1:
        {
            val = arrayGenerator::sizeOfArray::uint8;
        }
        break;
        /*case 2:
        {
            val = arrayGenerator::sizeOfArray::uint16;
        }
        break;
        case 3:
        {
            val = arrayGenerator::sizeOfArray::uint32;
        }
        break;
        case 4:
        {
            val = arrayGenerator::sizeOfArray::uint64;
        }
        break;*/
        default:
        {
            std::cout << "Invalid option\n";
            return 0;
        }
    }

    std::string C_array = myArray.generateArray(myParser.fileBSData, val);

    std::cout << "the C array: " << C_array << "\n";

    return 0;
}