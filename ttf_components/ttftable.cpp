
#include <iostream>
#include <fstream>
#include "ttftable.hpp"

TTFTable::TTFTable()
{

}

TTFTable::TTFTable(TTFTableDescription description, std::ifstream *file) :
m_description(description)
{
    m_data = std::vector<uint8_t>(m_description.length(), 0);

    if (file != nullptr && file->is_open()){
        std::ifstream::pos_type save_pos = file->tellg(); //save position
        file->seekg(m_description.offset());
        file->read(reinterpret_cast<char*>(m_data.data()), m_data.size());
        file->seekg(save_pos); //restore old position
    }

}

uint32_t TTFTable::calc_crc(uint32_t *table, uint32_t numberOfBytesInTable)
{
    uint32_t sum = 0;
    uint32_t nLongs = (numberOfBytesInTable + 3) / 4;

    while (nLongs-- > 0){
    sum += swap_bits(uint32_t, *table++);
    }

    return sum;
}

std::string TTFTable::hex_string()
{
    std::ostringstream out;
    out << "HEADER ======================" << std::endl;
    HEX_OUT(out, m_description.data(), m_description.data().size())
    out << "DATA ========================" << std::endl;
    HEX_OUT(out, m_data, m_data.size())
    return out.str();
}

std::string TTFTable::component_string()
{
    std::ostringstream out;
    out << "HEADER ======================" << std::endl;
    out << m_description.component_string();
    out << "DATA ========================" << std::endl;
    out << "CRC calculated: " << crc_string() << std::endl;
    //out << "NOT_IMPLEMENTED" << std::endl;
//    out << "Name: "   <<  std::hex << name() << std::endl
//        << "CRC: "    << std::setw(sizeof(crc()) * 2) << std::setfill('0') << crc() << std::endl
//        << "Offset: " << std::setw(sizeof(offset()) * 2) << std::setfill('0') << offset() << std::endl
//        << "Length: " << std::setw(sizeof(length()) * 2) << std::setfill('0') << length() << std::endl;
    return out.str();
}



std::string TTFTable::crc_string()
{
    uint32_t crc = calc_crc(reinterpret_cast<uint32_t*>(m_data.data()), m_description.length());
    std::ostringstream out;
    out << std::hex << std::setw(sizeof(uint32_t) * 2) << std::setfill('0')
        << crc << " "
        << (crc == m_description.crc()? GREEN "MATCH" RESET : RED "NOT_MATCH" RESET);
    return out.str();
}

TTFTableDescription &TTFTable::description()
{
    return m_description;
}
