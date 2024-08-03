#ifndef IP_H 
#define  IP_H
#include "generic-string.h"
#include "generic-field.h"
#include "string-array.h"

enum rule_type { SRC_IP = 0, DES_IP  };

class IP : public GenericField {
	public:
		    /**
         * @brief Check if the network is accepted by the rule
         * @param packet the whole packet
         * @return true if the packet matches the rule (port)
        */
		bool match(const GenericString &packet);
		IP(const GenericString* rule);



	private:
		int type; // 0 = src | 1 = dst
		int adress;
		int mask;
		int maskedIP;





};





#endif