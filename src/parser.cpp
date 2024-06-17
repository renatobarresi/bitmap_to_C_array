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

/**
 * @brief Construct a new parser::parser object
 * 
 * @param inputFile 
 * 
 * \todo Add error handling 
 */
parser::parser(const std::string& inputFile)
{
    std::string text;

    this->fileInputPath = inputFile;

    std::ifstream file(inputFile);

    // TODO: implement error handling
    while (getline(file, text))
    {
        this->fileBSData.append(text);
    }

    file.close();
}

void parser::printFileData()
{
    std::cout << "File's data: " << this->fileBSData << "\n";
}