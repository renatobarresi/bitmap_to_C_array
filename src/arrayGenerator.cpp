/**
 * @file arrayGenerator.cpp
 * @author Renato Barresi (renatobarresi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "arrayGenerator.h"
#include <vector>
#include <iostream>

static std::vector<int> *getStringVector(const std::string& str, int sizeToCut, int numOfElements);

/**
 * @brief 
 * 
 * @param fileBitStream 
 * @param val
 * 
 * \todo Specify which type of base should the array be generated  
 */
std::string arrayGenerator::generateArray(const std::string& fileBitStream, sizeOfArray val)
{
    std::vector<int> *subStrings;    // Store the strings here
    std::string cArrayString;
    std::string tempString;
    int strSize = fileBitStream.size();
    int numOfElements;

    switch (val)
    {
        case sizeOfArray::uint8:
        {   
            numOfElements = strSize/8; 
            subStrings = getStringVector(fileBitStream, 8, numOfElements);
        }
        break;
        case sizeOfArray::uint16:
        {
            numOfElements = strSize/16;
            subStrings = getStringVector(fileBitStream, 16, numOfElements);
        }
        break;
        case sizeOfArray::uint32:
        {
            numOfElements = strSize/32;
            subStrings = getStringVector(fileBitStream, 32, numOfElements);
        }
        break;
        case sizeOfArray::uint64:
        {
            numOfElements = strSize/64;
            subStrings = getStringVector(fileBitStream, 64, numOfElements);
        }
        break;
    }

    cArrayString = "[" + std::to_string(numOfElements) + "] = {";
    
    int lastItemIndex = 0;
    
    for (auto i: *subStrings)
    {
       tempString += std::to_string(i);
       
       // if last item break
       if (++lastItemIndex == numOfElements)
       {
        break;
       }
       tempString += ", "; 
    }

    cArrayString = cArrayString + tempString + "};";
    
    delete subStrings;

    return cArrayString;
}

static std::vector<int> *getStringVector(const std::string& str, int sizeToCut, int numOfElements)
{
    auto *vecIntegers = new std::vector<int>;    // Store the integers here
    int intialPos = 0;

    //std::cout << "\n";
    for (int i = 0; i < numOfElements; i++)
    {
        // Don't go over the string boundary
        if (intialPos + sizeToCut > str.size())
        {
            break;
        }

        // Get the substring
        std::string cuttedString = str.substr(intialPos, sizeToCut);

        // Convert the binary substring to an integer
        int binaryInt = std::stoi(cuttedString, nullptr, 2);
        
        //std::cout << cuttedString << ":" << binaryInt << ",";

        vecIntegers->push_back(binaryInt);

        // Update the position for the next substring
        intialPos += sizeToCut;
    }

    return vecIntegers;
}
