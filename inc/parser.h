/**
 * @file parser.h
 * @author Renato Barresi (renatobarresi@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <iostream>

/**
 * @brief 
 * 
 */
class parser
{
    public:

        std::string fileBSData;

        /**
         * @brief Construct a new parser object
         * 
         * @param inputFile 
         */
        parser(const std::string& inputFile);
        
        /**
         * @brief 
         * 
         */
        void printFileData();

    private:

        std::string fileInputPath;
        
};