#include <stddef.h>
#include <iostream>
#include <string>
#include "string.h"
#include "string-array.h"


        String::String():size(0){
            data=new char[size+1];
            data[0]='\0';
        }

        String::String(const String &str): size(str.size){

            data=new char[size+1];
            strcpy(data, str.data);
        }

        String::String(const char* str){
            size=strlen(str);
            data=new char[size+1];
            strcpy(data, str);
        }


        StringArray String::split(const char *delimiters) const{
          std::vector<std::string> result;
            //implement here the vector

            //construct string array that will save the data on the heap
          //return StringArray(result);


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

         /* 
          while(this->data[place]!='\0'){
            if(this->data[place]==delimiters[0])
            {
                strtok
                strcmp(this->data[place],delimiter)
            }
          }
          
            
          while(this->data[place]!='\0'){
            if(exist(this->data[place],delimiters))
            {
                
            }
          }
        */
            StringArray Array=new StringArray(delisum);
            for(int i=0; i<delisum; i++){
                String* current= new String(result[i]);
                current = dynamic_cast<GenericString*>current;
                //GenericString* current= new String(result[i]);
                //Array[i]= new String(current);
                Array[i]= current;
                //delete current;
            }
            return Array;

          }

       // StringArray 

       // }
         String& String::operator=(const char *str){
            if(!strcmp(data,str))
                return *this;
            
            delete[] this->data;
            
            this->size=strlen(str);
            this->data= new char[this->size+1];
            strcpy(this->data, str);
            return *this;
        }

         String& String::trim(){
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
        bool String::operator==(const GenericString &other){
            String* temp= dynamic_cast<String*>other;
            int result= strcmp(this->data,temp->data);
        //  delete temp;
            return (!result);



        }
        bool String::operator==(const char *other){
                int result= strcmp(this->data, other);
                return (!result);
        }
        int String::to_integer(){
        // check if the data is empty
        if(size==0 ){
            return 0;
        }
        int number=0;
        //try to covert the string into a number, if it's a number bigger
        // then 2^32 return 0
        try {
            number = std::stoi(data);
        } catch (const std::out_of_range& e) {
        return 0;
        }
        return number;
        }

        // virtual from generic string
        // cast generic string into String
        String& String::as_string(){
            String* str=dynamic_cast<String*>(this);
            if(str){
                 return str;
            }
            else 
                return NULL; 
           

        }

        // virtual from generic string
        // cast generic string into const String
        const String& String::as_string(){
            const String* str=dynamic_cast<const String*>(this);
            if(str){
                 return str;
            }
            else 
                return NULL;
        }
        String::~String() {
            delete[] size;
        }



