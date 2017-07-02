#ifndef TTFTABLE_HPP
#define TTFTABLE_HPP

#include "ttftabledescription.hpp"
class TTFTable
{
public:
    TTFTable();
    TTFTable(TTFTableDescription description, std::ifstream *file = nullptr);

    uint32_t calc_crc(uint32_t *table, uint32_t numberOfBytesInTable);

    std::string hex_string();
    std::string component_string();
    std::string crc_string();

    TTFTableDescription& description();
private:
    TTFTableDescription m_description;
    std::vector<uint8_t> m_data;
};

#endif // TTFTABLE_HPP
