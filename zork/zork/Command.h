#ifndef COMMAND_H_
#define COMMAND_H_

#include "includes.h"
#include <string>

class Command {
private:
    //char*
	string commandWord;
	string secondWord;

public:
    Command(string firstWord = "", string secondWord = "");
    virtual ~Command();
	string getCommandWord();
	string getSecondWord();
	bool isUnknown();
	bool hasSecondWord();
};

#endif /*COMMAND_H_*/
