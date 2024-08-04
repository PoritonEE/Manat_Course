#ifndef PORT_H
#define PORT_H


#include "generic-field.h"
#include "string.h"

enum rule_type { SRC_PORT = 0, DES_PORT  };

class Port : public GenericField
{
    public:
        Port(const GenericString& value);
        /**
         * @brief Check if the port is accepted by the rule
         * @param packet the whole packet
         * @return true if the packet matches the rule (port)
        */
        bool match(const GenericString& packet) const override;

        /**
         * @brief Set the port rule
         * @param value the port rule
         * @return true if the port rule is valid, false otherwise
        */
        //Port* Port::set_value(const GenericString& value);

        int detect_type(const GenericString& value);
        int detect_left_port(const GenericString& value);
        int detect_right_port(const GenericString& value);
         ~Port() = default; // Default destructor

        //void set_port_type(String type) { this->type = type; }

    private:
        // private fields
        int port_type;        // src-port=0 | dst-port=1
        int port_left;      // left part of the ports range
        int port_right;     // right part of the ports range       
   

};
#endif //PORT_H