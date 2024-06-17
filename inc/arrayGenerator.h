/**
 * @file arrayGenerator.h
 * @author Renato Barresi (renatobarresi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <string>

class arrayGenerator
{
    public:

        enum class sizeOfArray
        {
            uint8 = 10,
            uint16,
            uint32,
            uint64
        };

        /**
         * @brief 
         * 
         */
        std::string generateArray(const std::string& fileBitStream, sizeOfArray val);

};