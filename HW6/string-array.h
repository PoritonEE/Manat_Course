#ifndef STRING_ARRAY_H
#define STRING__ARRAY_H
#include <vector>
#include "generic-string.h"



//will function as an ADT
class StringArray {
    //PRAVITE FILDES
    std::vector<GenericString*> *my_string_array;    
    
    public:
    // Constructor
    StringArray();
    // Copy constructor
    //StringArray(const StringArray& other);
    // Copy assignment operator
    //StringArray& operator=(const StringArray& other);
    //destructor
    ~StringArray();

    //functions    
    /**
     * @brief push a new element.
     */
    void Push(GenericString* str);
     /**
     * @brief Overloaded operator[] to access elements
     */ 
    GenericString* operator[](size_t index) const;
     /**
     * @brief Method to get the size of the array
     */  
    size_t size() const;    
};

#endif