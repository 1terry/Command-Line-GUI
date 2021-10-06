/*
Author: Terrence Ju
Header file for backend code
Oct 5, 2021
*/


#ifndef HEADER_H
#define HEADER_H

#include <boost/process.hpp>
#include <string>
#include <iostream>

using std::string; 

class Command { //Defines class
   
    private: //Defines data members of class
        int returnCode;
        string commandText;
        string result;
    
    public: //Defines methods
        Command(string commandToExecute);
        ~Command();
        int execute(); 
        int getReturnCode();
        string returnCommandText();
        string returnResult();
        void setCommandText(string text);
};      

#endif 