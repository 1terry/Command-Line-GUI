#ifndef HEADER_H
#define HEADER_H

#include <boost/process.hpp>
#include <string>
#include <iostream>

using namespace boost::process;
using std::string; 

class Command {
    private:
        int returnCode;
        string commandText;
        string result;
    public:
        Command(string commandToExecute);
        ~Command();
        int execute(); 
        int getReturnCode();
        string returnCommandText();
        string returnResult();
        void setCommandText(string text);
};      

#endif 