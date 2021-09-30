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

    Command(commandText){

    }
    ~Command() {

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

    String returnCommandText(){
        return commandText;
    }

    String returnResult(){
        return resultl;
    }

    void setCommandText(String text){
        //this.commandText = text
    }

};