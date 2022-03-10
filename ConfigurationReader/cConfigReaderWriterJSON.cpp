//Evan Sinasac - 1081418
//INFO6025 Configuration and Deployment (Project 2)
//cConfgiReaderWriterJSON.cpp description:
//					This is the cpp file for the config reader writer.  The main purpose of this is to read the config file
//					at the start of the program, then it is used to read the user's preference file and to update it.

#include "cConfigReaderWriterJSON.h"
#include <iostream>
#include <sstream>

UserPrefs userPrefs;

cConfigReaderWriterJSON::cConfigReaderWriterJSON()
{

}

cConfigReaderWriterJSON::~cConfigReaderWriterJSON()
{
	
}

//Read the config file
bool cConfigReaderWriterJSON::readConfigFile(const std::string& filePath)
{
	using namespace rapidjson;

	FILE* fp = 0;
	fopen_s(&fp, filePath.c_str(), "rb"); // non-Windows use "r"

	char readBuffer[65536];
	FileReadStream is(fp, readBuffer, sizeof(readBuffer));

	Document d;
	d.ParseStream(is);

	//Kinda just realized I never actually used the preference file here, probably should...
	//So I went through and changed all the hard coded "UserPrefs.json" to use preferenceFile instead
	if (!d["PreferenceFile"].IsString())
	{
		std::cout << "Preference file didn't exist!" << std::endl;
		return false;
	}
	else
	{
		preferenceFile = d["PreferenceFile"].GetString();
		std::cout << "Preference File: " << preferenceFile << std::endl;
	}

	if (!d["Languages"].IsObject() && !d["Languages"]["English"].IsString())
	{
		return false;
	}
	else
	{
		languages.push_back(d["Languages"]["English"].GetString());
		std::cout << "Language 1: " << languages[0] << std::endl;
	}

	if (!d["Languages"].IsObject() && !d["Languages"]["French"].IsString())
	{
		return false;
	}
	else
	{
		languages.push_back(d["Languages"]["French"].GetString());
		std::cout << "Language 2: " << languages[1] << std::endl;
	}

	if (!d["FavoriteAnimalOptions"].IsArray())
	{
		return false;
	}
	else
	{
		for (unsigned int index = 0; index < d["FavoriteAnimalOptions"].Size(); index++)
		{
			animals.push_back(d["FavoriteAnimalOptions"][index].GetString());
			std::cout << "Animal " << index + 1 << ": " << animals[index] << std::endl;
		}
	}
	
	if (!d["FavoriteNumberRange"].IsArray())
	{
		return false;
	} 
	else
	{
		minimum = d["FavoriteNumberRange"][0].GetInt();
		maximum = d["FavoriteNumberRange"][1].GetInt();
		std::cout << "Number Range: " << minimum << " to " << maximum << std::endl;
	}
	//load the default preferences
	if (!d["DefaultPrefs"].IsObject())
	{
		return false;
	}
	else
	{
		if (!d["DefaultPrefs"]["Language"].IsString())
			return false;
		else
			userPrefs.language = d["DefaultPrefs"]["Language"].GetString();

		if (!d["DefaultPrefs"]["Animal"].IsString())
			return false;
		else
			userPrefs.animal = d["DefaultPrefs"]["Animal"].GetString();

		if (!d["DefaultPrefs"]["Number"].IsInt())
			return false;
		else
			userPrefs.number = d["DefaultPrefs"]["Number"].GetInt();

		if (!d["DefaultPrefs"]["Name"].IsString())
			return false;
		else
			userPrefs.name = d["DefaultPrefs"]["Name"].GetString();
	}

	std::cout << "Default Prefs: \nLanguage: " << userPrefs.language << "\nAnimal: " << userPrefs.animal << "\nNumber: " << userPrefs.number << "\nName: " << userPrefs.name << std::endl;

	fclose(fp);

	//Check if the preference file exists, if it does, then we can just return, other wise we need to make and write the file
	FILE* file;
	int file_exists;
	const char* filename = preferenceFile.c_str();	//UserPrefs

	fopen_s(&file, filename, "r");
	if (file == NULL) 
		file_exists = 0;
	else { 
		file_exists = 1; 

		char readBufferPref[65536];
		FileReadStream isPref(file, readBufferPref, sizeof(readBufferPref));

		Document dPref;
		dPref.ParseStream(isPref);

		if (!dPref["Language"].IsString())
		{
			return false;
		}
		else
		{
			userPrefs.language = dPref["Language"].GetString();
		}

		if (!dPref["Animal"].IsString())
		{
			return false;
		}
		else
		{
			userPrefs.animal = dPref["Animal"].GetString();
		}

		if (!dPref["Number"].IsInt())
		{
			return false;
		}
		else
		{
			userPrefs.number = dPref["Number"].GetInt();
		}

		if (!dPref["Name"].IsString())
		{
			return false;
		}
		else
		{
			userPrefs.name = dPref["Name"].GetString();
		}

		fclose(file); 
	}

	if (file_exists)
	{
		return true;
	}
	else
	{
		return writeUserPrefs(userPrefs.language, userPrefs.animal, userPrefs.number, userPrefs.name, preferenceFile);
	}

}  //end of readConfig
//Write the user's preference file
bool cConfigReaderWriterJSON::writeUserPrefs(std::string language, std::string animal, int number, std::string name, const std::string& fileName)
{
	using namespace rapidjson;

	FILE* fp = 0;

	//fopen_s(&fp, "UserPrefs.json", "rb"); // non-Windows use "r"
	//char readBuffer[65536];
	//FileReadStream is(fp, readBuffer, sizeof(readBuffer));
	//Document d;
	//d.ParseStream(is);
	//fclose(fp);
	//fp = 0;

	fopen_s(&fp, fileName.c_str(), "wb");
	char writeBuffer[65536];
	FileWriteStream os(fp, writeBuffer, sizeof(writeBuffer));

	Writer<FileWriteStream> writer(os);
	//d.Accept(writer);						//This absolutely breaks everything
	
	writer.StartObject();
	writer.Key("Language");
	writer.String(language.c_str());

	writer.Key("Animal");
	writer.String(animal.c_str());

	writer.Key("Number");
	writer.Int(number);

	writer.Key("Name");
	writer.String(name.c_str());
	writer.EndObject();
	
	fclose(fp);

	return true;
}	//end of writeUserPrefs

//These getters open the user's preference file to pull the information out
//Changed it, realized I had a struct I wasn't really using so I added updates to it when we set and now
//we just grab the prefs from the struct so we don't have to keep opening the file to pull it out
std::string cConfigReaderWriterJSON::GetUserLanguage()
{
	return userPrefs.language;
	//Keeping these commented so I have it just in case I need to change things to read from the file instead of the struct again
	//using namespace rapidjson;
	//FILE* fp = 0;
	//fopen_s(&fp, preferenceFile.c_str(), "rb");	// non-Windows use "r"
	//char readBuffer[65536];
	//FileReadStream is(fp, readBuffer, sizeof(readBuffer));
	//Document d;
	//d.ParseStream(is);
	//if (d["Language"].IsString())
	//{
	//	std::string answer = d["Language"].GetString();
	//	fclose(fp);					//It would be pretty dumb to forget to close the file and just return the GetString call... haha..ha...haaaa, yeah I forgot it at first lol
	//	return answer;
	//}
	//else
	//{
	//	fclose(fp);
	//	return "";
	//}
}
std::string cConfigReaderWriterJSON::GetUserAnimal()
{
	return userPrefs.animal;
}
int cConfigReaderWriterJSON::GetUserNumber()
{
	return userPrefs.number;
}
std::string cConfigReaderWriterJSON::GetUserName()
{
	return userPrefs.name;
}

//The only way I could get the writing to actually change the file is to do the write stuff, which basically erases the file and writes the whole thing
//So, these setters change one of the user's preferences by pulling the other preferences and re-writing them, and writing the one change
//Also update the userPrefs struct
bool cConfigReaderWriterJSON::SetUserLanguage(int index)
{
	userPrefs.language = languages[index - 1];
	return writeUserPrefs(languages[index - 1], GetUserAnimal(), GetUserNumber(), GetUserName(), preferenceFile);
}
bool cConfigReaderWriterJSON::SetUserAnimal(int index)
{
	userPrefs.animal = this->animals[index - 1];
	return writeUserPrefs(GetUserLanguage(), this->animals[index-1], GetUserNumber(), GetUserName(), preferenceFile);
}
bool cConfigReaderWriterJSON::SetUserNumber(int number)
{
	userPrefs.number = number;
	return writeUserPrefs(GetUserLanguage(), GetUserAnimal(), number, GetUserName(), preferenceFile);
}
bool cConfigReaderWriterJSON::SetUserName(std::string name)
{
	userPrefs.name = name;
	return writeUserPrefs(GetUserLanguage(), GetUserAnimal(), GetUserNumber(), name, preferenceFile);
}
//This goes through the options for animals and prints them to the console
void cConfigReaderWriterJSON::PrintAnimalOptions()
{
	for (unsigned int index = 0; index < animals.size(); index++)
	{
		std::cout << index + 1 << ") " << animals[index] << std::endl;
	}
}
int cConfigReaderWriterJSON::GetNumberOfAnimals()
{
	return this->animals.size();
}
//This goes through the options for languages and prints them to the console
void cConfigReaderWriterJSON::PrintLanguageOptions()
{
	for (unsigned int index = 0; index < languages.size(); index++)
	{
		std::cout << index + 1 << ") " << languages[index] << std::endl;
	}
}
//Get the minimum or maximum number to error check what the user inputs
int cConfigReaderWriterJSON::GetMinimumNumber()
{
	return minimum;
}
int cConfigReaderWriterJSON::GetMaximumNumber()
{
	return maximum;
}

