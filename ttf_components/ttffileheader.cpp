#include "ttffileheader.hpp"

TTFFileHeader::TTFFileHeader()
{

}

TTFFileHeader::TTFFileHeader(std::vector<uint8_t> &data) :
    m_data(data)
{

}
