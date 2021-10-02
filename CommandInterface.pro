QT       += core widgets
TARGET = CommandGUI
TEMPLATE = app 
SOURCES += interface.cpp interface.cpp code.cpp 
HEADERS += interfaceHeader.h header.h
LIBS += -lboost_thread -lpthread 