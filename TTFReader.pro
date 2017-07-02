TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ttffile.cpp \
    ttf_components/ttftableheader.cpp \
    ttf_components/ttffileheader.cpp \
    ttf_components/ttftabledescription.cpp \
    ttf_components/ttftable.cpp

HEADERS += \
    ttffile.hpp \
    macros.hpp \
    swapbits.hpp \
    ttf_components/ttftableheader.hpp \
    ttf_components/ttffileheader.hpp \
    ttf_components/ttftabledescription.hpp \
    ttf_components/ttftable.hpp
