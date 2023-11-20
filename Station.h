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

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <string>

namespace sdds
{
    class Station
    {
        int m_id;
        std::string m_name;
        std::string m_desc;
        unsigned int m_nextSerialNum;
        unsigned int m_stockNum;
        static size_t m_widthField;
        static int id_generator;

    public:
        Station();
        Station(const std::string& record);
        const std::string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;
    };
}

#endif