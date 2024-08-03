#ifndef PORT_H
#define PORT_H

#include "generic-string.h"
#include "generic-field.h"
#include "string-array.h"
#include "string.h"

enum rule_type { SRC_PORT = 0, DES_PORT  };

class Port 
{
    public:
        /**
         * @brief Check if the port is accepted by the rule
         * @param packet the whole packet
         * @return true if the packet matches the rule (port)
        */
        bool match(const GenericString& packet);

        /**
         * @brief Set the port rule
         * @param value the port rule
         * @return true if the port rule is valid, false otherwise
        */
        Port set_value(const GenericString& value);

        ~Port() {}

        //void set_port_type(String type) { this->type = type; }

    private:
        // private fields
        int port_type;        // src-port=0 | dst-port=1
        int port_left;      // left part of the ports range
        int port_right;     // right part of the ports range       
   

};
#endif //PORT_H