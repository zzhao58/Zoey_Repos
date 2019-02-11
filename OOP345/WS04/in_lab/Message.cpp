//Zhi Zhao
//109079178

#include <iostream>
#include <string>
#include "Message.h"

using namespace std;
namespace sict {
	Message::Message() :user(""), reply(""), message("") {}
	

	Message::Message(const std::string& str) {
		if (str.length() != 0)
		{
			size_t at = str.find("@");
			size_t space = str.find(" ");			

			user = str.substr(0, space);

			if (at != string::npos)//we find @
			{
				size_t space2 = str.find(" ", at);
				reply = str.substr(at + 1, space2 - (at + 1));

				message = str.substr(space2 + 1) + '\r';

			}
			else//there is no @
			{
				if (space != string::npos)//we find space1, there user and message
				{
					message = str.substr(space + 1) + '\r';

				}
				else
				{
					*this = Message();//imcomplete, out it in the empty
				}
			}

		}
		else
		{
			Message();
		}
	}

	bool Message::empty() const {
		return user.length() == 0 ? true : false;
	}

	void Message::display(std::ostream& os) const {
		if (!empty())
		{
			os << ">User" << "  : " << user << endl;
			if (reply.size() != 0)
			{
				os << " Reply" << " : " << reply << endl;
			}

			os << " Tweet" << " : " << message << endl;
		}

	}
}