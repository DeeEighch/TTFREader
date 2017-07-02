#ifndef SWAPBITS_HPP
#define SWAPBITS_HPP

#include <climits>
#include <endian.h>

template <typename T>
T swap_endian(T u)
{
    static_assert (CHAR_BIT == 8, "CHAR_BIT != 8");

    union
    {
        T u;
        unsigned char u8[sizeof(T)];
    } source, dest;

    source.u = u;

    for (size_t k = 0; k < sizeof(T); k++)
        dest.u8[k] = source.u8[sizeof(T) - k - 1];

    return dest.u;
}

#if LITTLE_ENDIAN
#define swap_bits(u8, some_u8) swap_endian<u8>(some_u8);
#else
#define swap_bits(u8, some_u8) some_u8;
#endif


#endif // SWAPBITS_HPP
