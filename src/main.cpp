/**
 * @file app.cpp
 * @author Renato Barresi (renatobarresi@gmail.com)
 * @brief A non bloated way of converting bmp to a plain, C array. 
 * @version 1.0
 * 
 * @attention 
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * 
 */
#include <iostream>
#include "main.h"
#include "parser.h"
#include "arrayGenerator.h"
#include <string>
#include <sys/stat.h>
#include <cstdlib>

/**
 * @brief App runs here
 *
 * @param argv arguments should be the path to the file and the type of array
 */
int main(int argc, char *argv[])
{   
    if (argc < 3)
    {
        std::cout << "Usage: " << argv[0] << " <path> <sizeOfArray>\n";
        return 1;
    }

    std::string path = std::string(argv[1]);

    int sizeOfArray = int(*argv[2] - '0');

    // Validate the array option
    if (sizeOfArray > 5 || sizeOfArray <= 0)
    {
        std::cout << "Options for array size is 1\n";
        return 1;
    }

    arrayGenerator::sizeOfArray val;

    // Add validation to the input parameters

    // Convert file contents to a bitstream
    arrayGenerator myArray;     // This object is used to generate the C array based on a bitstream
    parser myParser(path);      // This object is used to parse the contents of the file and convert it to a bitstream

    //myParser.printFileData();

    // Convert bitstream to the specified C array
    switch (sizeOfArray)
    {
        case 1:
        {
            val = arrayGenerator::sizeOfArray::uint8;
        }
        break;
        // TODO
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