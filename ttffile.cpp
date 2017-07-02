#include "ttffile.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "macros.hpp"




class TTFFileData{
public:
    TTFFileData() :
    size(0),
    name(""){}
    unsigned long size;
    std::string name;
    TTFFileHeader header;
    std::vector<TTFTable> tables;
};

TTFFile::TTFFile(const std::string file) : std::ifstream(file, std::ios::binary),
    m_data(new TTFFileData)
{
    m_data->name = file;
    seekg(0, std::ios::end);
    m_data->size = tellg();
    seekg(0, std::ios::beg);

    read_header();
    read_tables_descriptions();

}

std::string TTFFile::header_str() const
{
    std::ostringstream out;
    HEX_OUT(out, m_data->header.data(), m_data->header.data().size())
    return out.str();
}

TTFFileHeader TTFFile::header() const
{
    return m_data->header;
}

std::vector<TTFTable> TTFFile::tables()
{
    return m_data->tables;
}

void TTFFile::read_header()
{
    std::vector<uint8_t> head(12, 0);
    read(reinterpret_cast<char*>(head.data()), head.size());
    m_data->header = TTFFileHeader(head);
}

void TTFFile::read_tables()
{

}

void TTFFile::read_tables_descriptions()
{
    seekg(m_data->header.data().size());
    for (unsigned int i = 0; i < m_data->header.table_count(); i++){
        std::vector<uint8_t> table_head(16, 0);
        read(reinterpret_cast<char*>(table_head.data()), table_head.size());
        TTFTableDescription t_description(table_head);
        m_data->tables.push_back(TTFTable(t_description, this));
    }
}
