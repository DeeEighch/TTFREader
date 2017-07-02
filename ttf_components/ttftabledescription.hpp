#ifndef TTFTABLEDESCRIPTION_HPP
#define TTFTABLEDESCRIPTION_HPP
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>

#include "macros.hpp"
#include "swapbits.hpp"

class TTFTableDescription
{
public:
    enum TablePart{
        NAME = 0,
        CRC = 4,
        OFFSET = 8,
        LENGTH = 12

    };

    typedef struct {
        char name[4];
        uint32_t crc;
        uint32_t offset;
        uint32_t length;

    } TTFTDESC;

    TTFTableDescription();
    TTFTableDescription(std::vector<uint8_t> data);

    std::string name(){
        std::string value = "";
        if (m_data.size() >= NAME  + sizeof(char[4])){
            std::vector<char> sub(&m_data[NAME],&m_data[4]);
            value = std::string(sub.begin(), sub.end());
        }
        return value;
    }

//    uint32_t name(){
//        uint32_t value = 0;
//        if (m_data.size() >= NAME  + sizeof(uint32_t)){
//            value = swap_bits(uint32_t, reinterpret_cast<uint32_t&>(m_data.data()[NAME]));
//        }
//        return value;
//    }

    uint32_t crc(){
        uint32_t value = 0;
        if (m_data.size() >= CRC  + sizeof(value))
            value = swap_bits(uint32_t, reinterpret_cast<uint32_t&>(m_data.data()[CRC]));
        return value;
    }
    uint32_t offset(){
        uint32_t value = 0;
        if (m_data.size() >= OFFSET  + sizeof(value))
            value = swap_bits(uint32_t, reinterpret_cast<uint32_t&>(m_data.data()[OFFSET]));
        return value;
    }
    uint32_t length(){
        uint32_t value = 0;
        if (m_data.size() >= LENGTH  + sizeof(value))
            value = swap_bits(uint32_t, reinterpret_cast<uint32_t&>(m_data.data()[LENGTH]));
        return value;
    }

    std::string hex_string(){
        std::ostringstream out;
        HEX_OUT(out, m_data, m_data.size())
        return out.str();
    }

    std::string component_string(){
        std::ostringstream out;
        //out << "Name: "   <<  std::hex << std::setw(sizeof(name()) * 2) << std::setfill('0') << name() << std::endl
        out << "Name: "   <<  std::hex << name() << std::endl
            << "CRC: "    << std::setw(sizeof(crc()) * 2) << std::setfill('0') << crc() << std::endl
            << "Offset: " << std::setw(sizeof(offset()) * 2) << std::setfill('0') << offset() << std::endl
            << "Length: " << std::setw(sizeof(length()) * 2) << std::setfill('0') << length() << std::endl;
        return out.str();
    }

    std::vector<uint8_t>& data() {
        return m_data;
    }

    TTFTDESC desc;
private:
    std::vector<uint8_t> m_data;
};

#endif // TTFTABLEDESCRIPTION_HPP
