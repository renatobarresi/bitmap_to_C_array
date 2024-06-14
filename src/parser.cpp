/**
 * @file parser.cpp
 * @author Renato Barresi (renatobarresi@gmail.com)
 * @brief Contains the class "parser" which takes a .txt file as input and 
 makes it a bitsream
 * @version 0.1
 * @date 2024-06-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "parser.h"
#include <string>
#include <fstream>

parser::parser(std::string inputFile)
{
    std::string text;

    this->fileInputPath = inputFile;

    std::ifstream file(inputFile);

    while (getline(file, text))
    {
        this->fileData.append(text);
    }

    file.close();
}

void parser::printFileData()
{
    std::cout << this->fileData << "\n";
}

int parser::getRows()
{
    return 0;
}

int parser::getColumns()
{
    return 0;
}

