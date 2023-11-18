
/**********************************************************************************************************************************
				<assessment name: Milestone 1>
Full Name  : Rahimullah Khadim Hussain
Student ID#: 119515229
Email      : rkhadim-hussain@myseneca.ca
Section    : NEE
Date of Completion: 11-11-23

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************************************************************************/

#include <iomanip>
#include <string>
#include <algorithm>
#include"Station.h"
#include "Utilities.h"

namespace sdds {
	size_t Station::m_widthField = 0;
	size_t Station::id_generator = 0;

	Station::Station(const std::string& line)
	{
		m_id = ++Station::id_generator;
		Utilities utils;
		bool more = true;
		size_t pos = 0;
		auto whiteSpace = [](const std::string str) {
			size_t start = str.find_first_not_of(" \t");
			size_t end = str.find_last_not_of(" \t");
			return str.substr(start, end - start + 1);
		};

		try {
			m_name = utils.extractToken(line, pos, more);
			m_name = whiteSpace(m_name);
			m_serial_num = std::stoi(utils.extractToken(line, pos, more));
			m_curr_items = std::stoi(utils.extractToken(line, pos, more));
			Station::m_widthField = std::max(utils.getFieldWidth(), Station::m_widthField);
			m_desc = utils.extractToken(line, pos, more);
			m_desc = whiteSpace(m_desc);
		}
		catch (std::string err) {
			std::cout << err;
		}
	}

	const std::string& Station::getItemName() const
	{
		return m_name;
	}

	size_t Station::getNextSerialNumber()
	{
		++m_serial_num;
		return m_serial_num - 1;
	}

	size_t Station::getQuantity() const
	{
		return m_curr_items;
	}

	void Station::updateQuantity()
	{
		if (m_curr_items > 0) {
			--m_curr_items;
		}
		else {
			m_curr_items = 0;
		}
	}

	void Station::display(std::ostream& os, bool full) const
	{
		os << std::right << std::setw(3) << std::setfill('0') << m_id << " | ";
		os << std::left << std::setw(Station::m_widthField) << std::setfill(' ') << m_name;
		os << "| " << std::right << std::setw(6) << std::setfill('0') << m_serial_num << " | ";

		if (full) {
			os << std::right << std::setw(4) << std::setfill(' ') << m_curr_items <<" | ";
			os << std::left << m_desc << std::endl;
		}
		else{

			os << std::endl;
		}
	}

}