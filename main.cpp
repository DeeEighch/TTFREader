#include <iostream>

#include "macros.hpp"
#include "ttffile.hpp"
#include <iomanip>
using namespace std;

int main(int argc, char *argv[])
{
    TTFFile file("../TTFReader/fonts/ProximaNova-Regular.ttf");

    TTFFileHeader head = file.header();
    std::vector<TTFTable> t_desc = file.tables();
    HEX_COUT(head.data(), head.data().size())

    cout << head.component_string();

    for (TTFTable& table: file.tables()){
        cout //<< "============================" << endl
             << table.component_string();
             //<< "============================" << endl;
             //<< table.hex_string() << endl;
    }

    return 0;
}
