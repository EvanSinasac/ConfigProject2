//Evan Sinasac - 1081418
//INFO6025 Configuration and Deployment (Project 2)
//cLanguageReaderJSON.h description:
//					This is the header file for reading the language files.  This class is responsible for reading and
//					storing the messages located in a language file.  If the language is changed, the internal messages
//					updated with the messages located in the new language file.

#pragma once
#include <string>
#include <rapidjson/filereadstream.h>
#include <rapidjson/document.h>

class cLanguageReaderJSON
{
private:
	//These are all the strings to store the messages so we don't have to access the language file everythime we need to read something
	std::string English;
	std::string French;
	std::string EnterXToExit;
	std::string DisplayLanguage;
	std::string DisplayName;
	std::string DisplayNumber;
	std::string DisplayAnimal;
	std::string CurrentMessage;
	std::string WelcomeMessage;
	std::string ChangeMessage;
	std::string CurrentLanguage;
	std::string Enter12;
	std::string NewLanguage;
	std::string CurrentName;
	std::string SetNameMessage;
	std::string NewName;
	std::string CurrentNumber;
	std::string SetNumberAbove;
	std::string SetNumberBelow;
	std::string IncorrectInput;
	std::string NewNumber;
	std::string CurrentAnimal;
	std::string SetAnimalMessage;
	std::string Enter17;
	std::string NewAnimal;
	std::string GoodbyeMessage;
public:
	cLanguageReaderJSON();
	~cLanguageReaderJSON();
	//reading the language functions
	bool readLanguage(const std::string& filePath);
	bool loadEnglish();
	bool loadFrench();
	bool loadLanguage(const std::string& language);
	//getters
	std::string GetEnglish();
	std::string GetFrench();
	std::string GetEnterXToExit();
	std::string GetDisplayLanguage();
	std::string GetDisplayName();
	std::string GetDisplayNumber();
	std::string GetDisplayAnimal();
	std::string GetCurrentMessage();
	std::string GetWelcomeMessage();
	std::string GetChangeMessage();
	std::string GetCurrentLanguage();
	std::string GetEnter12();
	std::string GetNewLanguage();
	std::string GetCurrentName();
	std::string GetSetNameMessage();
	std::string GetNewName();
	std::string GetCurrentNumber();
	std::string GetSetNumberAbove();
	std::string GetSetNumberBelow();
	std::string GetIncorrectInput();
	std::string GetNewNumber();
	std::string GetCurrentAnimal();
	std::string GetSetAnimalMessage();
	std::string GetEnter17();
	std::string GetNewAnimal();
	std::string GetGoodbyeMessage();
};