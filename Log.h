#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <array>
#include <string>

class Log
{
    private:
        std::array<std::string, 6> logText;
           
    public:

        void addMessage(std::string newMessage)
        {
            short sort = 5;
            for (short index = 5; index > 1; index--)
            {
            this->logText[index] = this->logText[index - 1];
            }
            this->logText[0] = newMessage;
            return;
        }

        std::string getMessage(short index)
        {
            return this->logText[index];
        }

        void eraseLog()
        {
            for (short index = 0; index < 5; index++)
            {
            this->logText[index] = "";                
            }
            return;
        }

};

#endif