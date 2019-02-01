// Workshop 2 - Copy and Move Semantics
// Name: Qirong Fu
// Student #: 158899179
// Email: qfu11@myseneca.ca
// Course: OOP345 WINTER 2019
// File: Text.cpp

#include <iostream>
#include <string>
#include <fstream>
#include "Text.h"
using namespace sict;

namespace sict
{
	Text::Text()
	{
		m_str = nullptr;
		number_str = 0;
	}

	Text::Text(char* fileName)
	{
		number_str = 0;
		std::string n_line;
		std::ifstream file(fileName);

		if (file.is_open())
		{
			while (std::getline(file, n_line))			
			{
				number_str++;
			}


			m_str = new std::string[number_str];

			for (size_t i = 0; i < number_str; i++)
			{
				std::getline(file, m_str[i]);
			}

			file.close();
		}
	}

	Text::Text(const Text& source)
	{
		m_str = nullptr;
		*this = source;
	}

	Text& Text::operator=(const Text& source)
	{
		if (this != &source)
		{
			number_str = source.number_str;

			delete[] m_str;
			if (source.m_str != nullptr)
			{
				m_str = new std::string[number_str];
				for (size_t i = 0; i < number_str; i++)
				{
					m_str[i] = source.m_str[i];
				}
			}
			else
			{
				m_str = nullptr;
			}
		}

		return *this;
	}

	Text::~Text()
	{
		delete[] m_str;
		m_str = nullptr;
	}

	size_t Text::size() const
	{
		return number_str;
	}
}

