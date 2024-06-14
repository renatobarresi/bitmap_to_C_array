#pragma once

#include <string>

class arrayGenerator
{
    public:

        enum class sizeOfArray
        {
            uint8,
            uint16,
            uint32,
            uint64
        };

        /**
         * @brief 
         * 
         */
        void generateArray(sizeOfArray val);
};