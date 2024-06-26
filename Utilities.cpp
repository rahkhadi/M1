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

#include "Utilities.h"

namespace sdds
{
    char Utilities::m_delimiter = '|'; // All Utilities objects in the system share the same delimiter.
    Utilities::Utilities()
    {
        m_widthField = 1;
    }
    void Utilities::setFieldWidth(size_t newWidth)
    {
        m_widthField = newWidth;
    }

    size_t Utilities::getFieldWidth() const
    {
        return m_widthField;
    }
    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
    {
        std::string token;
        if (more)
        {

            if (next_pos >= str.length())
            {
                more = false;
                throw "Invalid position for token extraction";
            }

            if (str[next_pos] == m_delimiter)
            {
                more = false;
                throw "Delimiter found at starting position";
            }
            size_t delimPos = str.find(m_delimiter, next_pos);
            if (delimPos == std::string::npos)
            {
                token = str.substr(next_pos);
                more = false;
            }
            else
            {
                token = str.substr(next_pos, delimPos - next_pos);
                next_pos = delimPos + 1;
                more = true;
            }
            token = token.erase(0, token.find_first_not_of(' '));
            token = token.erase(token.find_last_not_of(' ') + 1);
            if (token.length() > m_widthField)
            {
                m_widthField = token.length();
            }
        }
        return token;
    }
    void Utilities::setDelimiter(char newDelimiter)
    {
        m_delimiter = newDelimiter;
    }
    char Utilities::getDelimiter()
    {
        return m_delimiter;
    }
}