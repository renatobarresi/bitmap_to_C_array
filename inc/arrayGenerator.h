/**
 * @file arrayGenerator.h
 * @author Renato Barresi (renatobarresi@gmail.com)
 * @brief Header file of the arrayGenerator component
 * 
 * @attention 
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * 
 */
#pragma once

// Includes

#include <string>
#include <vector>

// Class definition

/**
 * @brief This is the class used to generate the possible arrays
 */
class arrayGenerator
{
    public:

        /**
         * @brief This enum represents the possible array types
         */
        enum class sizeOfArray
        {
            uint8 = 8,
            uint16 = 16,
            uint32 = 32,
            uint64 = 64
        };

        /**
         * @brief Method to get the string representing the C array
         */
        std::string generateArray(const std::string& fileBitStream, sizeOfArray val);
    
    private:

        /**
         * @brief Method to get the vector of ints based on the bitstream
         */
        std::vector<int> *getStringVector(const std::string& str, int sizeToCut, int numOfElements);
};