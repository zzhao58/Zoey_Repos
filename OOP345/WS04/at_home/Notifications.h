#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H

#include <iostream>
#include <string>
#include "Message.h"

namespace sict
{
	class Notifications
	{
		const Message** p_messages;
		int MAX;
		int num_message;
	public:
		Notifications();
		Notifications(int);
		~Notifications() {};
		Notifications(const Notifications&);
		Notifications(Notifications&&);
		Notifications& operator=(const Notifications&);		
		Notifications& operator=(Notifications&&);

		Notifications& operator+=(const Message&);
		Notifications& operator-=(const Message&);
		void display(std::ostream&) const;
		size_t size() const;
	};
	std::ostream& operator<<(std::ostream&, Notifications&);
}

#endif 
