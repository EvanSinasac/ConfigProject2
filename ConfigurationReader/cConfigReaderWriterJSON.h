//Evan Sinasac - 1081418
//INFO6025 Configuration and Deployment (Project 2)
//cConfgiReaderWriterJSON.h description:
//					This is the header for the config file reader.  This class is also responsible for writing, reading
//					and updating the preference file for the user.

#pragma once
#include <string>
#include <rapidjson/filereadstream.h>
#include <rapidjson/filewritestream.h>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <vector>

struct UserPrefs
{
	std::string language;
	std::string animal;
	int number;
	std::string name;
};

class cConfigReaderWriterJSON
{
private:
	std::string preferenceFile;
	std::vector<std::string> languages;
	std::vector<std::string> animals;
	int minimum;
	int maximum;
	
public:
	cConfigReaderWriterJSON();
	~cConfigReaderWriterJSON();

	bool readConfigFile(const std::string& filePath);
	bool writeUserPrefs(std::string language, std::string animal, int number, std::string name, const std::string& fileName);


	std::string GetUserLanguage();
	std::string GetUserAnimal();
	int GetUserNumber();
	std::string GetUserName();

	bool SetUserLanguage(int index);
	bool SetUserAnimal(int index);
	bool SetUserNumber(int number);
	bool SetUserName(std::string name);

	void PrintAnimalOptions();
	int GetNumberOfAnimals();
	void PrintLanguageOptions();
	int GetMinimumNumber();
	int GetMaximumNumber();

};