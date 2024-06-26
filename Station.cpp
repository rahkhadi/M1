
/**********************************************************************************************************************************
				<assessment name: Milestone 1>
Full Name  : Rahimullah Khadim Hussain
Student ID#: 119515229
Email      : rkhadim-hussain@myseneca.ca
Section    : NEE
Date of Completion: 17-11-23

Authenticity Declaration:
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************************************************************************/

#include <iomanip>
#include "Station.h"
#include "Utilities.h"

namespace sdds
{
    size_t Station::m_widthField = 0;
    int Station::id_generator = 0;

    Station::Station()
    {
        m_id = {};
        m_name = {};
        m_desc = {};
        m_nextSerialNum = {};
        m_stockNum = {};
    }

    Station::Station(const std::string& record) : Station()
    {
        Utilities utilsObj;
        bool more = true;
        size_t next_pos = 0;
        Station::id_generator++;
        m_id = id_generator;
        m_name = utilsObj.extractToken(record, next_pos, more);
        if (more)
        {
            m_nextSerialNum = stoi(utilsObj.extractToken(record, next_pos, more));
        }
        if (more)
        {
            m_stockNum = stoi(utilsObj.extractToken(record, next_pos, more));
        }

        if (Station::m_widthField < utilsObj.getFieldWidth())
        {
            Station::m_widthField = utilsObj.getFieldWidth();
        }

        if (more)
        {
            m_desc = utilsObj.extractToken(record, next_pos, more);
        }
    }

    const std::string& Station::getItemName() const
    {
        return m_name;
    }

    size_t Station::getNextSerialNumber()
    {
        return m_nextSerialNum++;
    }
    size_t Station::getQuantity() const
    {
        return m_stockNum;
    }
    void Station::updateQuantity()
    {
        if (m_stockNum > 0)
            m_stockNum--;
    }

    void Station::display(std::ostream& os, bool full) const
    {
        os << std::setfill('0') << std::right << std::setw(3) << m_id << " | ";
        os << std::setfill(' ');

        os << std::left << std::setw(m_widthField) << m_name << " | ";
        os << std::setfill('0') << std::right << std::setw(6) << m_nextSerialNum << " | ";
        os << std::setfill(' ');

        if (full)
        {
            os << std::setw(4) << m_stockNum << " | ";
            os << std::left << m_desc << std::endl;
        }
        else
            os << std::endl;
    }
}