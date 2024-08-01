#include <stddef.h>
#include <iostream>
#include <string>
#include "string.h"

// Constructor implementations
String::String() : size(0) {
    data = new char[size + 1];
    data[0] = '\0';
}

String::String(const String &str) : size(str.size) {
    data = new char[size + 1];
    strcpy(data, str.data);
}

String::String(const char* str) {
    size = strlen(str);
    data = new char[size + 1];
    strcpy(data, str);
}
/*


       StringArray String::split(const char *delimiters) const {
          std::vector<std::string> result;
         // Ori's implementation: stage 1, count delimiters
          int delisize=strlen(delimiters);
         // int place=0;
         // int last_place=0;
          int delisum=0;
         // int push=0;
          char* token;
          String local= String(this->data);
          token= strtok(local,delimiters);
          while(token!=NULL){
            delisum++;
            result.push_back(token);
            token=strtok(NULL,delimiters);
          }
            //char * str_m
            StringArray Array=new StringArray(delisum);
            for(int i=0; i<delisum; i++){
                //strcpy(str_m, &result[i])
                GenericString* current =make_string(result[i]);
                
                //String* current= new String(result[i]);
                //current = dynamic_cast<GenericString*>current;
                
                Array[i]= current;
                //delete current;
            }
            return Array;

          }
*/

// Pure virtual function implementations
StringArray String::split(const char *delimiters) const {
    std::vector<std::string> result;
    int delisize = strlen(delimiters);
    int delisum = 0;
    char* token;
    String local(this->data);
    token = strtok(local.data, delimiters);
    while (token != NULL) {
        delisum++;
        result.push_back(token);
        token = strtok(NULL, delimiters);
    }

    // Placeholder for StringArray construction, assuming dynamic allocation is correct
    StringArray Array(delisum);
    for (int i = 0; i < delisum; ++i) {
        GenericString* current = make_string(result[i].c_str());
        Array[i] = current;
    }
    return Array;
}

GenericString& String::operator=(const char *str) {
    if (strcmp(data, str) == 0) {
        return *this;
    }

    delete[] data;
    size = strlen(str);
    data = new char[size + 1];
    strcpy(data, str);
    return *this;
}
/*
         GenericString& String::trim(){
            int begin=0;
            int end=size-1;
            for( begin=0;begin<size;begin++){
                if(data[begin]!=' '||data[begin]!='\t'||data[begin]!='\n')
                    break;
                
            }
            if(begin<end){
                for( end=size-1; end>begin;end--){
                    if(data[end]!=' '||data[end]!='\t'||data[end]!='\n')
                        break;
                }
            }
            char* tempdata= new char(end-begin+2);
            if(end-begin+1)
                strncpy(tempdata, this->data+begin, end-begin+1);
            tempdata[end-begin+1]='\0';
            delete[] this->data;
            this->data=tempdata; 
            
            //might not work, use next 2 lines if it doesnt:

            //strcpy(this->data, tempdata);
            //delete[] tempdata;
            this->size=(end-begin+1);
            //this->data= this->data+count;
            //this->size=this->size-count;
           // delete[count] this->data-count;


        }
*/
GenericString& String::trim() {
    int begin = 0;
    int end = size - 1;

    while (begin <= end && isspace(data[begin])) {
        begin++;
    }
    while (end >= begin && isspace(data[end])) {
        end--;
    }

    int newSize = end - begin + 1;
    char* tempData = new char[newSize + 1];
    strncpy(tempData, data + begin, newSize);
    tempData[newSize] = '\0';

    delete[] data;
    data = tempData;
    size = newSize;

    return *this;
}
/*
        bool String::operator==(const GenericString &other) const{
            String* temp= dynamic_cast<String*>(&other);
            int result= strcmp(this->data,temp->data);
        //  delete temp;
            return (!result);



        }
*/
bool String::operator==(const GenericString &other) const {
    const String* temp = dynamic_cast<const String*>(&other);
    if (temp) {
        return strcmp(data, temp->data) == 0;
    }
    return false;
}
/*
        bool String::operator==(const char *other) const{
                int result= strcmp(this->data, other);
                return (!result);
        }
*/
bool String::operator==(const char *other) const {
    return strcmp(data, other) == 0;
}

int String::to_integer() const {
    if (size == 0) {
        return 0;
    }
    try {
        return std::stoi(data);
    } catch (const std::out_of_range&) {
        return 0;
    }
}
/*
        // virtual from generic string
        // cast generic string into String
        String& String::as_string(){
            String* str=dynamic_cast<String*>(this);
            if(str){
                 return *str;
            }
            else 
                return NULL; 
           

        }

        // virtual from generic string
        // cast generic string into const String
const String& String::as_string() const{
    const String* str=dynamic_cast<const String*>(this);
    if(str){
        return str;
    } else 
        return NULL;
}
*/

String& String::as_string() {
    return *this;
}

const String& String::as_string() const {
    return *this;
}
/*
GenericString* make_string(const char *str){
    // create a string object and then downcast it
    String* my_str= new String(str);
    GenericString* current = my_str;
    return current;
}
*/
GenericString* make_string(const char *str) {
    String* my_str = new String(str);
    return my_str;
}

String::~String() {
    delete[] data;
}

