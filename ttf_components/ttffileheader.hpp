#ifndef TTFFILEHEADER_HPP
#define TTFFILEHEADER_HPP

#include <vector>
#include <iomanip>
#include <sstream>

#include "macros.hpp"
#include "swapbits.hpp"
class TTFFileHeader
{
public:
    enum HeaderPart{
        SIZER = 0,
        TABLE_COUNT = 4,
        SEARCH_DIAP = 6,
        SELECTOR = 8,
        OFFSET = 10
    };

    TTFFileHeader();
    TTFFileHeader(std::vector<uint8_t> &data);

    uint32_t sizer(){
        uint32_t value = 0;
        if (m_data.size() >= SIZER  + sizeof(value))
            value = swap_bits(uint32_t, reinterpret_cast<uint32_t&>(m_data.data()[0]));
        return value;
    }
    uint16_t table_count(){
        uint16_t value = 0;
        if (m_data.size() >= TABLE_COUNT  + sizeof(value))
            value = swap_bits(uint16_t, reinterpret_cast<uint16_t&>(m_data.data()[4]));
        return value;
    }
    uint16_t search_diap(){
        uint16_t value = 0;
        if (m_data.size() >= SEARCH_DIAP  + sizeof(value))
            value = swap_bits(uint16_t, reinterpret_cast<uint16_t&>(m_data.data()[6]));
        return value;
    }
    uint16_t selector(){
        uint16_t value = 0;
        if (m_data.size() >= SELECTOR  + sizeof(value))
            value = swap_bits(uint16_t, reinterpret_cast<uint16_t&>(m_data.data()[8]));
        return value;
    }
    uint16_t offset(){
        uint16_t value = 0;
        if (m_data.size() >= OFFSET + sizeof(value))
            value = swap_bits(uint16_t, reinterpret_cast<uint16_t&>(m_data.data()[10]));
        return value;
    }

    std::string hex_string(){
        std::ostringstream out;
        HEX_OUT(out, m_data, m_data.size())
        return out.str();
    }

    std::string component_string(){
        std::ostringstream out;
        out << "sizer: " <<  std::dec << std::setw(sizeof(sizer()) * 2) << std::setfill('0') << sizer() << std::endl
            << "tables count: " << std::setw(sizeof(table_count()) * 2) << std::setfill('0') << table_count() << std::endl
            << "search range: " << std::setw(sizeof(search_diap()) * 2) << std::setfill('0') << search_diap() << std::endl
            << "selector: " << std::setw(sizeof(selector()) * 2) << std::setfill('0') << selector() << std::endl
            << "offset: " << std::setw(sizeof(offset()) * 2) << std::setfill('0') << offset() << std::endl;
        return out.str();
    }

    std::vector<uint8_t>& data() {
        return m_data;
    }

private:
    std::vector<uint8_t> m_data;

};

#endif // TTFFILEHEADER_HPP
