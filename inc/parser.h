/**
 * @file parser.h
 * @author Renato Barresi (renatobarresi@gmail.com)
 * @brief Header file of the parser component
 * 
 * @attention 
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * 
 */
#pragma once

// Includes 

#include <iostream>

// Class definition

/**
 * @brief This class is in charge of reading the file containing the bitmap 
 * and convert the data to a bitstream
 */
class parser
{
    public:

        std::string bitStreamData;     //! Used to store the bitstream

        /**
         * @brief Class constructor
         */
        parser(const std::string& inputFile);
        
        /**
         * @brief Method to print the bitstream
         */
        void printBitStream();

    private:

        std::string fileInputPath;  //! Path to the file
        
};