
#include "ip.h"
#include "port.h"
//#include "input.h"

#define SRC_IP "src-ip"
#define DST_IP "dst-ip"
#define SRC_PORT "src-port"
#define DST_PORT "dst-port"



bool is_ip_rule(const GenericString &type);
//bool rule_type(String& rule, String& type, String& value);

/**
 * @brief check if the arguments are valid packets, afterwards parse the stdin
 *        and leave only packets that match the given rule.
 * @param argc the number of arguments
 * @param argv the arguments
 * @return 0 if the arguments are valid, 1 otherwise
*/
int main(int argc, char **argv)
{
    //checking the correctness of input
    if (check_args(argc, argv))
	{
		return 1;
	}
    //check if it is ip or port rule
    GenericString* rule = make_string(argv[1]);
    if(is_ip_rule(*rule)){
        //IP ip_rule= IP(*rule);
        //you have a problem in your IP file, port works fine

    }else{
        //setting the rule
        Port my_port= Port(*rule);
        //
    }
    /*
    const char* str_rule= "des-port=22-22";
    GenericString* rule =make_string(str_rule);
    Port my_port= Port(*rule);
    */

   
    return 0;
}

bool is_ip_rule(const GenericString &type){
    const String& str =type.as_string();
    String str_c=String(str);
    GenericString* value_c = &(str_c.trim());

    StringArray my_type= (value_c->as_string()).split("=");
    value_c =my_type[0];
    value_c = &(value_c->as_string()).trim();
    return ((value_c->as_string() == SRC_IP ||
             value_c->as_string() == DST_IP));
}
