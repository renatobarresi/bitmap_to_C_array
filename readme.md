# Description

A lightweight utility that converts a bitmap represented in a .txt file into a C array. The bitmap is parsed from left to right, starting at the upper-left corner. This tool is particularly useful for embedded systems development, where predefined graphics need to be stored in ROM as arrays.

## Getting Started

Create a .txt file (like the image bellow), fill it with 1 and 0's representing your graphic and save it. Then execute the program with the path to your file and an option for the type of the array. 
The options for the type of the array are:
* 1, uint8_t
* 2, uint16_t 
* 3, uint32_t
* 4, uint64_t

![file image](filePicture.png)

### Installing

* C++ 11
* CMake

### Run the program

./bitmapToCArray <file_path> <array_type>
./bitmapToCArray ../figures/face.txt 1

#### Output

![file_image][output.png]

## Version History

* 1.0
    * Initial Release
* 1.1
    * Added uint64_t type array 

## License

This project is licensed under the MIT License - see the LICENSE file for details


## TODO

* Add option to change the array contents base type (decimal, hex and binary).
* Add parsing the bitmap vertically instead of the current one (horizontally).
* Add small graphical interface, with a text editor to quickly add bitmaps without having to parse a file.
