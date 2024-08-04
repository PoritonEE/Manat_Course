
//#include "ip.h"
#include "port.h"
//#include "input.h"

#define SRC_IP "src-ip"
#define DST_IP "dst-ip"
#define SRC_PORT "src-port"
#define DST_PORT "dst-port"



bool is_arg_ip(const GenericString &type);
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
    const char* str_rule= "des-port=22-22";
    GenericString* rule =make_string(str_rule);
    Port my_port= Port(*rule);

    /*
    if (check_args(argc, argv) != 0)
    {
        return 1;
    }
    
    String arg = String(argv[1]);
    String type;
    String value;
    if (!rule_split_type(arg, type, value)){
        return 1;
    }
    if (is_arg_ip(type))
    {
        IP ip;
        ip.set_ip_type(type);
        ip.set_value(value);
        parse_input(ip);
    }
    else
    {
        Port port;
        port.set_port_type(type);
        port.set_value(value);
        parse_input(port);
    }
    */
    return 0;
}

bool is_arg_ip(const GenericString &type){
    const String& str =type.as_string();
    String str_c=String(str);
    GenericString* value_c = &(str_c.trim());

    StringArray my_type=
    return true;
}
