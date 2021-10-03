//#include <boost/array.hpp>

#include <boost/process.hpp>
#include <string>
#include <iostream>

using namespace boost::process;
using std::string; 

class Command {
    public:
        int returnCode;
        string commandText;
        string result;

        Command(string commandToExecute);
        ~Command();
        int execute() {return returnCode;}
        int getReturnCode() {return returnCode;}
        string returnCommandText() {return commandText;}
        string returnResult() {return result;}
        void setCommandText(string text);
};      