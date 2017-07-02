#include "ttftabledescription.hpp"

TTFTableDescription::TTFTableDescription()
{

}

TTFTableDescription::TTFTableDescription(std::vector<uint8_t> data) :
    m_data(data), desc((TTFTDESC&)(*data.data()))
{

}
