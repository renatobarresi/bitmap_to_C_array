/**
 * @file parser.cpp
 * @author Renato Barresi (renatobarresi@gmail.com)
 * @brief Contains the class "parser" which takes a .txt file as input and 
 makes it a bitsream
 * 
 * @attention 
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * 
 */

// Includes

#include "parser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

/**
 * @brief Construct a new parser::parser object
 * 
 * @param inputFile file path plus name e.g ./folder/file.txt
 * 
 */
parser::parser(const std::string& inputFile) {
    std::string text;

    this->fileInputPath = inputFile;

    std::ifstream file(inputFile);

    // Check if the file opened successfully
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + inputFile);
    }

    // Read the file line by line
    while (getline(file, text)) {
        this->fileBSData.append(text);
    }

    // Check for any errors during reading
    if (file.bad()) {
        throw std::runtime_error("Error while reading file: " + inputFile);
    }

    file.close();
}

/**
 * @brief Print via cout the bitstream
 */
void parser::printBitStream()
{
    std::cout << "File's bitstream: " << this->fileBSData << "\n";
}