#include "header.h"

//Make sure to change namespaces
//INSTALL ON LINUX!!!!!
using namespace boost::process;

Command::Command(string commandToExecute){
    commandText = commandToExecute;
    returnCode = 0;
}

Command::~Command() {
    //Do something?
}

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
    
    //Catches process errors as a result of invalid command and outputs code accordingly
    catch (process_error){
        returnCode = -1;
    }

    return 1;
}

int Command::getReturnCode(){
    return returnCode;
}

string Command::returnCommandText(){
    return commandText;
}

string Command::returnResult(){
    // std::cout << result << std::endl;
    return result;
}

void Command::setCommandText(string text){
    commandText = text;
}

// int main()
// {
//     Command user_command("ls");
//     user_command.execute();
//     std::cout << "result string: \n\n" << std::endl;
//     user_command.returnResult();
//     return 0;
// }