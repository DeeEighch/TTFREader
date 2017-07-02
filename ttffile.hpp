#ifndef TTFFILE_HPP
#define TTFFILE_HPP

#include <fstream>
#include <memory>

#include "ttf_components/ttffileheader.hpp"
#include "ttf_components/ttftable.hpp"

class TTFFileData;
class TTFFile : public std::ifstream
{
public:

    TTFFile(const std::string file);
    std::string header_str() const;

    TTFFileHeader header() const;
    std::vector<TTFTable> tables();

private:
    std::shared_ptr<TTFFileData> m_data;

    void read_header();
    void read_tables();
    void read_tables_descriptions();


};

#endif // TTFFILE_HPP
