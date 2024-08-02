    #include "string-array.h"
    #include <vector>
    #include <string>
    #include "generic-string.h"

    
    StringArray::StringArray(){
        my_string_array = new std::vector<GenericString*>();
    }
        
  /*  StringArray::StringArray(const StringArray& other){
        for (const auto& item : other.my_string_array) {
        my_string_array->push_back(new GenericString(*item));
        }
    }
*/
        
    StringArray::~StringArray(){
        for (auto& item : *my_string_array) {
            delete item;
        }
    }

    void StringArray::Push(GenericString* str){
            my_string_array->push_back(str);
    }

    GenericString* StringArray::operator[](size_t index) const {
        return my_string_array->at(index);  // Use at() for bounds checking
    }
    size_t StringArray::size() const{
        return my_string_array->size();
    }
