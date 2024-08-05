#include "ip.h"




bool IP::match(const GenericString& packet) {
	bool matching = 0;
	//assumming the packet is valid,
	// we dont need to check the split size
	
		String& newPacket= packet.as_string();
		StringArray segments = (newPacket.as_string()).split(","); // maybe we need to do it with " " if we do sed s/,/ /g
		segments[0].trim();
		segments[2].trim();
		stringArray ip = segments[(this->type)*2].split("="); //either the 1st or 3rd cell
		stringArray only_ip= ip[1].split(".")
		uint extracted = (only_ip[0].to_integer())<<24 +(only_ip[1].to_integer())<<16 +(only_ip[2].to_integer())<<8 + (only_ip[3].to_integer());// do we need to remove the dots?
		return extracted & this->mask == maskedIP;
		
}

// recieves src-ip=XXX.XXX.XXX.XXX/XX 

IP::IP(const GenericString* rule) { 

	String& newRule= rule.as_string();
	// the number in the name refers to the wanted cell
	stringArray mask1 = newRrule.split("/");
	mask1[1].trim();
	stringArray ip1 = mask1[0].split("=");
	ip1[1].trim();
	stringArray type0 = ip1[0].split("-");
	type[0].trim();
	
	if(type0[0]=="src")
		this->type = 0;
	else if(type0[0] == "dst")
		this->type = 1;
	this->mask = -1u;
	stringArray only_ip= ip1[1].split(".")
	only_ip[0].trim();
	only_ip[1].trim();
	only_ip[2].trim();
	only_ip[3].trim();
	uint extracted = (only_ip[0].to_integer())<<24 +(only_ip[1].to_integer())<<16 +(only_ip[2].to_integer())<<8 + (only_ip[3].to_integer());// do we need to remove the dots?
	this->ip = extracted;
	int maskint = mask1[1].to_integer();

	this->mask <<(32-maskint);
		
	
	
	this->maskedIP = this->mask & this->ip;

	//is this needed? 
	delete[] mask1;
	delete[] ip1;
	delete[] type0;

}

