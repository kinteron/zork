#ifndef COMMANDWORDS_H_
#define COMMANDWORDS_H_

#include "includes.h"
#include <vector>
#include <string>

class CommandWords {
private:
	//Define a static vector for our valid command words.
	//We'll populate this in the class constructor
	static vector<string> validCommands;

public:
	CommandWords();
    virtual ~CommandWords();
	bool isCommand(string aString);
	void showAll();
};


#endif /*COMMANDWORDS_H_*/
