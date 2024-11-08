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

/**
 * @brief App runs here
 *
 * @param argv arguments should be the path to the file and the type of array
 */
int main(int argc, char *argv[])
{   
    // Check correct number of inputs
    if (argc < 3)
    {
        std::cout << "Usage: " << argv[0] << " <path> <typeOfArray>\n";
        return 1;
    }

    std::string path = std::string(argv[1]);

    int typeOfArray = int(*argv[2] - '0');

    // Validate the array types
    if (typeOfArray > 5 || typeOfArray <= 0)
    {
        std::cout << "Options for array type are 1, 2, 3 and 4. Where 1 represents uint8, 2 uint16 and so on\n";
        return 1;
    }

    // TODO
    // Add validation to the input parameters

    // Convert file contents to a bitstream
    parser myParser(path);      // This object is used to parse the contents of the file and convert it to a bitstream
    
    // Convert bitstream to the specified C array
    arrayGenerator myArray;     // This object is used to generate the C array based on a bitstream
    arrayGenerator::sizeOfArray val;

    switch (typeOfArray)
    {
        
        case 1:
        {
            val = arrayGenerator::sizeOfArray::uint8;
        }
        break;
        case 2:
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
        break;
        default:
        {
            std::cout << "Invalid size option\n";
            return 1;
        }
    }

    // Get the string represeting a C array
    std::string C_array = myArray.generateArray(myParser.bitStreamData, val);

    // Print the C array
    std::cout << C_array << "\n";

    return 0;
}