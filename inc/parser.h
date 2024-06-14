#pragma once

#include <iostream>

/**
 * @brief 
 * 
 */
class parser
{
    public:

        std::string fileData;

        /**
         * @brief Construct a new parser object
         * 
         * @param inputFile 
         */
        parser(const std::string inputFile);
        
        /**
         * @brief 
         * 
         */
        void printFileData();

        /**
         * @brief Get the number of rows in the file
         * 
         * @return int 
         */
        int getRows();

        /**
         * @brief Get the number of columns in the file
         * 
         * @return int 
         */
        int getColumns();


    private:

        std::string fileInputPath;
        
};