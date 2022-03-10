//Evan Sinasac - 1081418
//INFO6025 Configuration and Deployment (Project 2)
//cLanguageReaderJSON.cpp description:
//					This is the cpp file for reading the language files.  The main purpose is to read and store the messages
//					in the inputted language file, and to return those messages when appropriate.

#include "cLanguageReaderJSON.h"
#include <iostream>

cLanguageReaderJSON::cLanguageReaderJSON()
{

}
cLanguageReaderJSON::~cLanguageReaderJSON()
{

}
//Open the inputted language file and place all the information into the private variables
bool cLanguageReaderJSON::readLanguage(const std::string& filePath)
{
	using namespace rapidjson;

	FILE* fp = 0;
	fopen_s(&fp, filePath.c_str(), "rb"); // non-Windows use "r"

	char readBuffer[65536];
	FileReadStream is(fp, readBuffer, sizeof(readBuffer));

	Document d;
	d.ParseStream(is);
	
	if (!d["English"].IsString())
	{
		std::cout << "English didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->English = d["English"].GetString();
	}

	if (!d["French"].IsString())
	{
		std::cout << "French didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->French = d["French"].GetString();
	}
	//Otherwise everything is just the sentences that need to be printed to the screen depending on where or what
	//position in the reading UserPrefs stuff we're in
	if (!d["EnterXToExit"].IsString())
	{
		std::cout << "EnterXToExit didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->EnterXToExit = d["EnterXToExit"].GetString();
	}

	if (!d["DisplayLanguage"].IsString())
	{
		std::cout << "DisplayLanguage didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->DisplayLanguage = d["DisplayLanguage"].GetString();
	}

	if (!d["DisplayName"].IsString())
	{
		std::cout << "DisplayName didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->DisplayName = d["DisplayName"].GetString();
	}

	if (!d["DisplayNumber"].IsString())
	{
		std::cout << "DisplayNumber didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->DisplayNumber = d["DisplayNumber"].GetString();
	}

	if (!d["DisplayAnimal"].IsString())
	{
		std::cout << "DisplayAnimal didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->DisplayAnimal = d["DisplayAnimal"].GetString();
	}

	if (!d["CurrentMessage"].IsString())
	{
		std::cout << "CurrentMessage didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->CurrentMessage = d["CurrentMessage"].GetString();
	}

	if (!d["WelcomeMessage"].IsString())
	{
		std::cout << "WelcomeMessage didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->WelcomeMessage = d["WelcomeMessage"].GetString();
	}

	if (!d["ChangeMessage"].IsString())
	{
		std::cout << "ChangeMessage didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->ChangeMessage = d["ChangeMessage"].GetString();
	}

	if (!d["CurrentLanguage"].IsString())
	{
		std::cout << "CurrentLanguage didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->CurrentLanguage = d["CurrentLanguage"].GetString();
	}

	if (!d["Enter12"].IsString())
	{
		std::cout << "Enter12 didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->Enter12 = d["Enter12"].GetString();
	}

	if (!d["NewLanguage"].IsString())
	{
		std::cout << "NewLanguage didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->NewLanguage = d["NewLanguage"].GetString();
	}

	if (!d["CurrentName"].IsString())
	{
		std::cout << "CurrentName didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->CurrentName = d["CurrentName"].GetString();
	}

	if (!d["SetNameMessage"].IsString())
	{
		std::cout << "SetNameMessage didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->SetNameMessage = d["SetNameMessage"].GetString();
	}

	if (!d["NewName"].IsString())
	{
		std::cout << "NewName didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->NewName = d["NewName"].GetString();
	}

	if (!d["CurrentNumber"].IsString())
	{
		std::cout << "CurrentNumber didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->CurrentNumber = d["CurrentNumber"].GetString();
	}

	if (!d["SetNumberAbove"].IsString())
	{
		std::cout << "SetNumberAbove didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->SetNumberAbove = d["SetNumberAbove"].GetString();
	}

	if (!d["SetNumberBelow"].IsString())
	{
		std::cout << "SetNumberBelow didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->SetNumberBelow = d["SetNumberBelow"].GetString();
	}

	if (!d["NewNumber"].IsString())
	{
		std::cout << "NewNumber didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->NewNumber = d["NewNumber"].GetString();
	}

	if (!d["CurrentAnimal"].IsString())
	{
		std::cout << "CurrentAnimal didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->CurrentAnimal = d["CurrentAnimal"].GetString();
	}

	if (!d["SetAnimalMessage"].IsString())
	{
		std::cout << "SetAnimalMessage didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->SetAnimalMessage = d["SetAnimalMessage"].GetString();
	}

	if (!d["Enter17"].IsString())
	{
		std::cout << "Enter17 didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->Enter17 = d["Enter17"].GetString();
	}

	if (!d["NewAnimal"].IsString())
	{
		std::cout << "NewAnimal didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->NewAnimal = d["NewAnimal"].GetString();
	}

	if (!d["GoodbyeMessage"].IsString())
	{
		std::cout << "GoodbyeMessage didn't exist?" << std::endl;
		return false;
	}
	else
	{
		this->GoodbyeMessage = d["GoodbyeMessage"].GetString();
	}

	if (!d["IncorrectInput"].IsString())
	{
		std::cout << "IncorrectMessage didn't exist?" << std::endl;
		return false;
	}
	else {
		this->IncorrectInput = d["IncorrectInput"].GetString();
	}

	fclose(fp);
	return true;
} //end of readLanguage

bool cLanguageReaderJSON::loadEnglish()
{
	return readLanguage("English.json");
}
bool cLanguageReaderJSON::loadFrench()
{
	return readLanguage("French.json");
}
//If any new languages are added we can add the calls here
bool cLanguageReaderJSON::loadLanguage(const std::string& language)
{
	if (language == "English")
	{
		return loadEnglish();
	}
	if (language == "Francais")
	{
		return loadFrench();
	}
	return false;
}
//And these are all the getters to get all the messages stored in the private variables
std::string cLanguageReaderJSON::GetEnglish()
{
	return this->English;
}
std::string cLanguageReaderJSON::GetFrench()
{
	return this->French;
}
std::string cLanguageReaderJSON::GetEnterXToExit()
{
	return this->EnterXToExit;
}
std::string cLanguageReaderJSON::GetDisplayLanguage()
{
	return this->DisplayLanguage;
}
std::string cLanguageReaderJSON::GetDisplayName()
{
	return this->DisplayName;
}
std::string cLanguageReaderJSON::GetDisplayNumber()
{
	return this->DisplayNumber;
}
std::string cLanguageReaderJSON::GetDisplayAnimal()
{
	return this->DisplayAnimal;
}
std::string cLanguageReaderJSON::GetCurrentMessage()
{
	return this->CurrentMessage;
}
std::string cLanguageReaderJSON::GetWelcomeMessage()
{
	return this->WelcomeMessage;
}
std::string cLanguageReaderJSON::GetChangeMessage()
{
	return this->ChangeMessage;
}
std::string cLanguageReaderJSON::GetCurrentLanguage()
{
	return this->CurrentLanguage;
}
std::string cLanguageReaderJSON::GetEnter12()
{
	return this->Enter12;
}
std::string cLanguageReaderJSON::GetNewLanguage()
{
	return this->NewLanguage;
}
std::string cLanguageReaderJSON::GetCurrentName()
{
	return this->CurrentName;
}
std::string cLanguageReaderJSON::GetSetNameMessage()
{
	return this->SetNameMessage;
}
std::string cLanguageReaderJSON::GetNewName()
{
	return this->NewName;
}
std::string cLanguageReaderJSON::GetCurrentNumber()
{
	return this->CurrentNumber;
}
std::string cLanguageReaderJSON::GetSetNumberAbove()
{
	return this->SetNumberAbove;
}
std::string cLanguageReaderJSON::GetSetNumberBelow()
{
	return this->SetNumberBelow;
}

std::string cLanguageReaderJSON::GetIncorrectInput()
{
	return this->IncorrectInput;
}
std::string cLanguageReaderJSON::GetNewNumber()
{
	return this->NewNumber;
}
std::string cLanguageReaderJSON::GetCurrentAnimal()
{
	return this->CurrentAnimal;
}
std::string cLanguageReaderJSON::GetSetAnimalMessage()
{
	return this->SetAnimalMessage;
}
std::string cLanguageReaderJSON::GetEnter17()
{
	return this->Enter17;
}
std::string cLanguageReaderJSON::GetNewAnimal()
{
	return this->NewAnimal;
}

std::string cLanguageReaderJSON::GetGoodbyeMessage()
{
	return this->GoodbyeMessage;
}