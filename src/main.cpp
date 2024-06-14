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

int main()
{   
    int rows, columns;
    std::string path = "../test/testFile.txt";

    std::cout << "BMP to C array!" << "\n";

    arrayGenerator myArray;
    parser myParser(path);

    myParser.printFileData();

    myArray.generateArray(arrayGenerator::sizeOfArray::uint8);

    return 0;
}