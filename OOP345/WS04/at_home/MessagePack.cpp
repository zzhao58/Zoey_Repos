//MessagePack.cpp
//Zhi zhao


#include <iostream>
#include <string>
#include "MessagePack.h"

using namespace std;

namespace sict {
	MessagePack::MessagePack(): message(nullptr), num_message(0) {}

	MessagePack::MessagePack(Message** src, int num) {
		if (src != nullptr && num > 0) {
			num_message = num;

			message = new Message[num];
			for (int i = 0; i < num; i++) {
				if (!(*src)[i].empty()) {
					message[i] = (*src)[i];		//only copy Message objects where they are not empty
				}
				else {
					message[i] = Message();	   //if src is empty, set it to safe empty state.
				}
			}
		}
		else {
			*this = MessagePack();
		}
	}

	MessagePack::MessagePack(const MessagePack& src) {  //copy constrctor
		message = nullptr;
		*this = src;
	}

	MessagePack::MessagePack(MessagePack&& src) {  //move constructor
		message = nullptr;
		*this = move(src);
	}

	MessagePack::~MessagePack() {
		delete[] message;
	};

	void MessagePack::display(ostream& os) const {
		for (size_t i = 0; i < num_message; i++) {
			message[i].display(os);
		}
	}

	size_t MessagePack::size() const {
		return num_message;
	}

	MessagePack& MessagePack::operator=(const MessagePack&  src) {
		if (this != &src ) {
			num_message = src.num_message;
			delete[] message;
			message = new Message[num_message];
			for (size_t i = 0; i < num_message; i++) {
				if (!src.message[i].empty()) {
					message[i] = src.message[i];		
				}
				else {
					message[i] = Message();	   
				}
			}
		}
		return *this;
	}

	MessagePack& MessagePack::operator=(MessagePack&& src) {
		if (this != &src) {
			num_message = src.num_message;
			delete[] message;
			message = src.message;
			src.message = nullptr;
			src.num_message = 0;
		}
		return *this;
	}

	ostream& operator<<(ostream& os, MessagePack& mpack) {
		mpack.display(os);
		return os;
	}

}