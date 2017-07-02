#ifndef MACROS_HPP
#define MACROS_HPP

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define WHITE   "\033[1;37m"
#define GREEN   "\033[1;32m"





#define HEX_COUT(data, length)\
                    for (unsigned long i = 0; i < length; i++){\
                        std::cout << std::hex\
                                  << std::uppercase\
                                  << std::setw(2)\
                                  << std::setfill('0')\
                                  << (int)data[i]\
                                  << " ";\
                     }\
                     std::cout << std::endl;

#define HEX_OUT(out, data, length)\
                    for (unsigned long i = 0; i < length; i++){\
                        out << std::hex\
                            << std::uppercase\
                            << std::setw(2)\
                            << std::setfill('0')\
                            << (int)data[i]\
                            << " ";\
                     }\
                     out << std::endl;

#endif // MACROS_HPP
