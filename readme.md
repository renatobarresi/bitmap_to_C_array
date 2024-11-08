# Description

This is a -hopefully- non bloated bitmap to C array. Takes a .txt file with a bitmap as an input and prints a C array based on the bitmap.
The way the bitmap is parsed is from left to right, starting from the upper left corner.
When developing LCD drivers for embedded systems, sometimes there's a need to have pre-defined graphics inside ROM. A way of storing these graphics, would be as an array.   

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

### Executing program

./bitmapToCArray ../figures/face.txt 1

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