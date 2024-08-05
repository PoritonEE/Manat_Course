#ifndef STRING_H
#define STRING_H
#include <stddef.h>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "generic-string.h"
#include "string-array.h"


class String : public GenericString{
    char *data;
    int size;
     
    
    public:
    //constructors 

    String();
    String(const String &str);
    String(const char* str);

    //the functions from genericstring
    
    StringArray split(const char *delimiters) const override;
    GenericString& operator=(const char *str) override;
    GenericString& trim() override;
    bool operator==(const GenericString &other) const override;
    bool operator==(const char *other) const override;
    int to_integer() const override;
    String& as_string() override;
    const String& as_string() const override;
    
   
    
    //destructor
    ~String();

};



#endif 