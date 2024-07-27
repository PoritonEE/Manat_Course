#ifndef STRING_ARRAY_H
#define STRING__ARRAY_H
#include <stddef.h>
#include <iostream>
#include <vector>
#include "generic-string.h"


//will function as an ADT
class StringArray : GenericString{
    //PRAVITE FILDES
    char** my_string_array;
    int size;
    
    public:
    // the only constructor this class can get
    StringArray(std::vector<std::string>& vec );
    ~StringArray();
    

    //char* get(const char *str);

};
#endif