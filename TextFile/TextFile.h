/**
* @author: Le Minh Thu
*/


#pragma once 

#include <string>
#include <vector>

// This class is used to store name and content of a text file and perform modification on the content of the text file 
// Sample usage: TextFile newFile;
//				 newFile.addCommand (commandToBeAdded);

class TextFile
{
private:

	std::string fileName;
	std::vector<std::string> fileContent;

public:
	TextFile(std::string);
	~TextFile();
	bool isEmpty() const;
	void addCommand(std::string);
	bool deleteCommand(int, std::string&);
	void clearAllCommands();
	bool displayAllCommands();
	void writeToFile(std::string);
	std::string toString();
	std::string retrieveFileName() const;
	void sortAllCommands();
	std::string searchKeyWord(std::string keyWord);
};

