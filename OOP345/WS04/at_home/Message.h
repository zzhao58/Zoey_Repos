//Zhi Zhao
//109079178
#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H

#include<iostream>
#include<string>
using namespace std;
namespace sict {
	class Message {
		string user;
		string reply;
		string tweet;
	public:
		Message();
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os) const;
		Message& operator=(const Message&);

		friend bool operator==(const Message&, const Message&);
	};

}
#endif 
