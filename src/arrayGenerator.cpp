/**
 * @file arrayGenerator.cpp
 * @author Renato Barresi (renatobarresi@gmail.com)
 * @brief 
 * 
 * @attention 
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * 
 */
#include "arrayGenerator.h"
#include <vector>
#include <iostream>

/**
 * @brief Method to generate the required array
 * It gets a bitstream as input, converts it to a vector of ints, adds the relevant C information as a string and returns it 
 * @param bitStream[in] The file's bitstream
 * @param sizeOfArray the C array type e.g uint8, uint16 ...
 * @return a string with the C style array
 */
std::string arrayGenerator::generateArray(const std::string& bitStream, sizeOfArray typeOfArray)
{
    std::string cArrayString;           // This is the string that represents the C array that is returned
    std::vector<int> *subStrings;       // Store the strings here
    std::string tempString;             // Used as a temp variable to store the processed bitstream, this is concatenated to cArrayString
    int strLen = bitStream.size();      // lenght of the bitstream
    int numOfElements = strLen/(int)typeOfArray; 

    // Convert bitstream into a vector of ints
    subStrings = getStringVector(bitStream, (int)typeOfArray, numOfElements);

    int lastItemIndex = 0;
    
    for (auto i: *subStrings)
    {   
       // Convert the integer to string and store it in a temporal string 
       tempString += std::to_string(i);
       
       // if last item break
       if (++lastItemIndex == numOfElements)
       {
        break;
       }

       tempString += ", "; 
    }

    // Build the C array
    cArrayString = "[" + std::to_string(numOfElements) + "] = {" + tempString + "};";
    
    delete subStrings;

    return cArrayString;
}

/**
 * @brief This method cuts a string representing a bitstream into parts of equal size, and then  
 * converts the strings to integers and stores them in a vector
 * @param str[in] The bitstream to cut
 * @param sizeToCut The size to cut 
 * @param numOfElements The number of elements that will result from dividing the bitstream by size to cut
 * @return std::vector<int>* 
 */
std::vector<int> *arrayGenerator::getStringVector(const std::string& str, int sizeToCut, int numOfElements)
{   
    auto *vecIntegers = new std::vector<int>;   // Store the integers here
    int intialPos = 0;                                              // The initial position in the str                                      
    int binaryInt = 0;

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
        // Since stoi can only work with 32 bit numbers, we have to check for 64 bit number and use stoull
        if (cuttedString.length() < 32)
        {
            binaryInt = std::stoi(cuttedString, nullptr, 2);
        }
        else 
        {
            binaryInt = std::stoull(cuttedString, nullptr, 2);
        }
        
        //std::cout << cuttedString << ":" << binaryInt << ",";

        vecIntegers->push_back(binaryInt);

        // Update the position for the next substring
        intialPos += sizeToCut;
    }

    return vecIntegers;
}
