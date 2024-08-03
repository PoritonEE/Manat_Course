#include "port.h"
#include <stddef.h>
#include <iostream>


int detect_type(const GenericString& value){
    int is_des;
    //get a copy of the given value
    
    const String& str =value.as_string();
    String str_c=String(str);

    //use oprator == to detect des or src  

    is_des=(str_c=="des")? DES_PORT:SRC_PORT;
    return is_des;
}

int detect_left_port(const GenericString& value){
    int left_port;
    //get a copy of the given value
    
    const String& str =value.as_string();
    String str_c=String(str);
    GenericString* value_c = &str_c;
    //split by the sign "="
    StringArray my_array= (value_c->as_string()).split("=");
    //trim the data
    String str_left_port=String(my_array[1]->as_string());
    GenericString* value_left_port = &(str_left_port.trim());   
    
    //convert to integer
    left_port= (value_left_port->as_string()).to_integer();
    return left_port;
}

int detect_right_port(const GenericString& value){
    int right_port;
    //get a copy of the given value
    
    const String& str =value.as_string();
    String str_c=String(str);
    GenericString* value_c = &str_c;
    //trim the data
    str_c.trim();
    //convert to integer
    right_port= str_c.to_integer();
    return right_port;
}
Port::Port(const GenericString& value){
    
     
    //get a copy of the given value
    
    const String& str =value.as_string();
    String str_c=String(str);
    GenericString* value_c = &str_c; 
    
    //trim the unnecessary data
    value_c->trim();
   
   //split the data with delim "-"
   StringArray my_array= (value_c->as_string()).split("-");
   
   //find the type    
    this->port_type= detect_type(*my_array[0]);
  
    // update the left port
   
    this->port_left= detect_left_port(*my_array[1]);
    //update the rigt port
    this->port_right=detect_right_port(*my_array[2]);

    
    
}


bool Port::match(const GenericString& packet){
    int port;
    //get a copy of the given value
    
    const String& str =packet.as_string();
    String str_c=String(str);
    GenericString* value_c = &str_c;

    //we work with ports and thus we will look only on StringArray[2 and 3]
    StringArray my_array= (value_c->as_string()).split(",");
    
    //decied what to take depedns on the rule
     
    if( this->port_type==DES_PORT){
        GenericString* value_des = my_array[3];
        StringArray des_array = (value_des->as_string()).split("=");
        port= (des_array[1]->as_string()).to_integer();
        if(this->port_left<= port && this->port_right>= port){
            return true;
        } else{
            return false;
        }
    } else {
        GenericString* value_des = my_array[2];
        StringArray src_array = (value_des->as_string()).split("=");
        port= (src_array[1]->as_string()).to_integer();
        if(this->port_left<= port &&this->port_right>= port){
            return true;
        } else{
            return false;
        }

    }


}