//MessagePack.h
//Zhi Zhao

#ifndef SICT_MESSAGEPACK_H
#define SICT_MESSAGEPACK_H

#include<iostream>
#include<string>
#include"Message.h"

  
namespace sict {
	
	class MessagePack {
		Message* message;
		size_t   num_message;
		
	public:
		MessagePack();
		MessagePack(Message**, int);
		MessagePack(const MessagePack&);		//copy constructor
		MessagePack(MessagePack&&);				//move constructor
		~MessagePack();
		void display(std::ostream&) const;
		size_t size() const;
		MessagePack& operator=(const MessagePack&  src);     //copy assignment operator
		MessagePack& operator=(MessagePack&& src);     //move assignment operator
	};

	std::ostream& operator<<(std::ostream&, MessagePack&);
}

#endif
