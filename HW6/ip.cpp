#include "ip.h"
#include "GenericField"



bool ip::match(const GenericString& packet) {
	bool matching = 0;
	//assumming the packet is valid,
	// we dont need to check the split size
	
	
		stringArray segments = packet::split(",");
		stringArray ip = segments[this->type]::split("=");
		int extracted = ip[1]::to_integer();
		return extracted & maskedIP;
		
}

// recieves src-ip=XXXXXXXXXXXX/XX 

IP::IP(const GenericString* rule) { 

	// the number in the name refers to the wanted cell
	stringArray mask1 = rule::split("/");
	stringArray ip1 = rule::mask1[0]("=");
	stringArray type0 = rule::ip1[0]("-");
	
	if(type0[0]=="src")
		this->type = 0;
	else if(type0[0] == "dst")
		this->type = 1;
	this->mask = 0;
	this->ip = ip1[0]::to_integer();
	int maskint = mask1[1]::to_integer();

	for (int i = 0; i < maskint; i++) {
		this->mask <<=2;
		this->mask |=1;

	}

	
	this->maskedIP = this->maskedIP & mask;

	//is this needed? 
	delete[] mask1;
	delete[] ip1;
	delete[] type0;

}

