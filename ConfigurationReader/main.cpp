//Evan Sinasac - 1081418
//INFO6025 Configuration and Deployment (Project 2)
//main.cpp description:
//					The purpose of project 2 is to familiarze ourselves with the concepts and methods of state saving/loadig
//					and of internationalization.  This application loads a config.json file that tells it what the general
//					options are that can be changed, as well as the name of the file to be used to save the user's preferences
//					Then it enters a loop where the user can change certain options which are then reflected in the file
//					For the sake of time, I decided to forgo the harder marks and focused on rapidJSON, so there is no rapidXML
//					usage.  I kept the rapidxml include folder in case I eventually add it (it's also pretty small, so eh)

// std
#include <iostream>
#include <string>
//Didn't use xml and neither are used in main
// xml
//#include <rapidxml/rapidxml.hpp>
//#include <rapidxml/rapidxml_utils.hpp>

// json
//#include <rapidjson/filereadstream.h>
//#include <rapidjson/filewritestream.h>
//#include <rapidjson/writer.h>
//#include <rapidjson/document.h>

//Project 2 classes
#include "cConfigReaderWriterJSON.h"
#include "cLanguageReaderJSON.h"


int main()
{
	cConfigReaderWriterJSON config;
	cLanguageReaderJSON languageReader;

	if (config.readConfigFile("Config.json"))
	{
		std::cout << "Read config ended great!" << std::endl;
	}
	else
	{
		std::cout << "Read config didn't go so well..." << std::endl;
		return -1;
	}

	if (languageReader.loadLanguage(config.GetUserLanguage()))
	{
		std::cout << "loaded language :)" << std::endl;
	}
	else
	{
		std::cout << "language didn't load :(" << std::endl;
		return -1;
	}

	bool looping = true;
	std::string userInput;

	//Main loop that allows a user to interact with the program and make changes to their preferences
	while (looping)
	{
		std::cout << languageReader.GetWelcomeMessage() << std::endl;
		std::cout << languageReader.GetEnterXToExit() << std::endl;
		std::cout << languageReader.GetCurrentMessage() << std::endl;
		std::cout << languageReader.GetDisplayLanguage() << config.GetUserLanguage() << std::endl;
		std::cout << languageReader.GetDisplayName() << config.GetUserName() << std::endl;
		std::cout << languageReader.GetDisplayNumber() << config.GetUserNumber() << std::endl;
		std::cout << languageReader.GetDisplayAnimal() << config.GetUserAnimal() << std::endl;
		std::cout << languageReader.GetChangeMessage();
		std::cin >> userInput;

		std::cout << std::endl;

		if (userInput == "1")
		{
			//User wants to change the language
			userInput = "";

			std::cout << languageReader.GetCurrentLanguage() << std::endl;
			config.PrintLanguageOptions();
			std::cout << languageReader.GetEnter12();
			std::cin >> userInput;

			config.SetUserLanguage(std::stoi(userInput));
			std::cout << languageReader.GetNewLanguage() << config.GetUserLanguage() << std::endl;
			
			languageReader.loadLanguage(config.GetUserLanguage());
		}
		else if (userInput == "2")
		{
			//User wants to change their name
			userInput = "";
			
			std::cout << languageReader.GetCurrentName() << config.GetUserName() << std::endl;
			std::cout << languageReader.GetSetNameMessage();
			std::cin >> userInput;

			config.SetUserName(userInput);
			std::cout << languageReader.GetNewName() << config.GetUserName() << std::endl;

		}
		else if (userInput == "3")
		{
			//User wants to change their number
			userInput = "";

			std::cout << languageReader.GetCurrentNumber() << config.GetUserNumber() << std::endl;
			std::cout << languageReader.GetSetNumberAbove() << config.GetMinimumNumber() << languageReader.GetSetNumberBelow() << config.GetMaximumNumber() << ": ";
			std::cin >> userInput;

			if (std::stoi(userInput) < config.GetMinimumNumber() || std::stoi(userInput) > config.GetMaximumNumber())
			{
				//Check the inputted number is within acceptable range
				std::cout << languageReader.GetIncorrectInput();
			}
			else
			{
				config.SetUserNumber(std::stoi(userInput));
				std::cout << languageReader.GetNewNumber() << config.GetUserNumber() << std::endl;
			}
		}
		else if (userInput == "4")
		{
			//User wants to change their animal preference
			userInput = "";

			std::cout << languageReader.GetCurrentAnimal() << config.GetUserAnimal() << std::endl;
			std::cout << languageReader.GetSetAnimalMessage() << std::endl;
			config.PrintAnimalOptions();
			std::cout << languageReader.GetEnter17();
			std::cin >> userInput;

			//Check that the user enters a valid number (between 1 and 7 for the current config file)
			if (std::stoi(userInput) < 0 || std::stoi(userInput) > config.GetNumberOfAnimals())
			{
				std::cout << languageReader.GetIncorrectInput() << std::endl;
			}
			else
			{
				config.SetUserAnimal(std::stoi(userInput));
				std::cout << languageReader.GetNewAnimal() << config.GetUserAnimal() << std::endl;
			}

		}
		else if (userInput == "x")
		{
			// :)
		}
		else
		{
			std::cout << languageReader.GetIncorrectInput() << std::endl;
		}
		
		if (userInput == "x")
		{
			std::cout << languageReader.GetGoodbyeMessage() << std::endl;
			looping = false;
		}
		
		userInput = "";
		std::cout << std::endl;
	} //end of while loop

	return 0;
} //end of main