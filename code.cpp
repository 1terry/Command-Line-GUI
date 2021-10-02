#include "header.h"


//INSTALL ON LINUX!!!!!

int main()
{
    
}

class Command {
    private:
        int returnCode = 0;
        string commandText = "";
        string result = "";

    Command(string commandToExecute){
        commandText = commandToExecute;
    }
    ~Command() {
        //Do something?
    }

    int execute() {
        ipstream pipe_stream;
        child c("gcc --version", (std_out & std_err) > pipe_stream);

        std::string line;

        while (pipe_stream && std::getline(pipe_stream, line) && !line.empty())
            std::cerr << line << std::endl;

        c.wait();
        return 1;
    }

    int getReturnCode(){
        return returnCode;
    }

    string returnCommandText(){
        return commandText;
    }

    string returnResult(){
        return result;
    }

    void setCommandText(string text){
        commandText = text;
    }

};