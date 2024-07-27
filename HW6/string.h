#ifndef STRING_H
#define STRING_H
#include <stddef.h>
#include <iostream>
#include "generic-string.h"
#include "string-array.h"


class String : GenericString{
    char *data;
    int size;
     
    
    public:
    String();
    String(const String &str);
    String(const char* str);
    //---!
    StringArray split(const char *delimiters);
     //create this in StringArray.cpp

     String& operator=(const char *str);
     String& trim();
     bool operator==(const String &other);
     bool operator==(const char *other);
     int to_integer();
     String& as_string();
     const String& as_string();
    
    ~String();

};



#endif 