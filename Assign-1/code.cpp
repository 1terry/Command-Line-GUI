/*
Author: Terrence Ju
Backend code that creates a class that takes in a string
and executes the string as a command 
Oct 5, 2021
*/

#include "code.h"

using namespace boost::process;

/*
Constructor Command() takes in string of command to be executed
*/
Command::Command(string commandToExecute){
    commandText = commandToExecute;
    returnCode = 0;
}

/*
*Deconstructor ~Command() does not do anything right now but is good practice! :D 
*/
Command::~Command() {
}

/*
Calling function execute() executes the command string as a command
*/
int Command::execute() {
    ipstream pipe_stream;
      
    try{
        child c(commandText, (std_out & std_err) > pipe_stream);
        std::string line;
        while (pipe_stream && std::getline(pipe_stream, line) && !line.empty()){
            std::cerr << line << std::endl;
            result = result + "\n" + line;
        }
        c.wait();
    }
    
    //Catches process errors snf outputs error message
    catch (process_error){
        result = "An invalid input has been entered";
        returnCode = -1;
    }

    return 1;
}

/*
Getter for return code returns the status of the code as an int
Return code will be 0 for sucess, or -1 for failure
*/
int Command::getReturnCode(){
    return returnCode;
}

/*
Getter for command text that returns the command input
*/
string Command::returnCommandText(){
    return commandText;
}

/*
Getter for output that returns the output of the command
*/
string Command::returnResult(){
    return result;
}

/*
Setter for command text which takes in string to set command
*/
void Command::setCommandText(string text){
    commandText = text;
}
