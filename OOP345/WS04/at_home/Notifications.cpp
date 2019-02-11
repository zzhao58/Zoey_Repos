#include <iostream>
#include "Message.h"
#include "Notifications.h"

using namespace std;
namespace sict{

	Notifications::Notifications(): p_messages(nullptr),MAX(0), num_message(0){}

	Notifications::Notifications(int max) {
		if (max > 0) {
			MAX = max;
			//Message* message1 = new Message[MAX];
			//p_messages = &message1; 
			*p_messages = new Message[MAX];
			num_message = 0;
		}
		else {
			*this=Notifications();
		}
	}

	Notifications::Notifications(const Notifications& src){
		*this = src;
	}

	Notifications::Notifications(Notifications&& src) {
		*this = move(src);
	}

	Notifications& Notifications::operator=(const Notifications& src){
		if (this != &src){
			p_messages = src.p_messages;
			MAX = src.MAX;
			num_message = src.num_message;
		}
		return *this;
	}

	Notifications& Notifications::operator=(Notifications&& src) {
		if (this != &src) {
			p_messages = src.p_messages;
			MAX = src.MAX;
			num_message = src.num_message;

			src.p_messages = nullptr;
			src.MAX = 0;
			src.num_message = 0;
		}
		return *this;
	}

	Notifications& Notifications::operator+=(const Message& msg){
		if (num_message < MAX) {
			(*p_messages)[num_message] = msg;
			num_message++;
		}
		return *this;
	}

	Notifications& Notifications::operator-=(const Message& msg) {
		bool found = false;
		int i;
		for (i = 0; i < num_message && !found; i++)
			if ((*p_messages)[i] == msg) {
				found = true;
			}

		if(found) {
			for ( ; i < num_message; i++)
				(*p_messages)[i-1] = (*p_messages)[i];

			if (num_message) {
				(*p_messages)[num_message - 1] = Message();
				num_message--;
			}
		}
		return *this;
	}
	
	void Notifications::display(ostream& os) const{
		for (int i = 0; i < num_message; i++)
			(*p_messages)[i].display(os);
	}

	size_t Notifications::size() const {
		return num_message;
	}

	ostream& operator<<(ostream& os, Notifications& no) {
		no.display(os);
		return os;
	}
}
