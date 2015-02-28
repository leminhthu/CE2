/**
* Files created and modified are txt files
* File name entered by user must follow this format: <filename>.txt
* Only 1 file is processed each time the program is executed
* During the current execution, if the file name has been used during previous executions,
the current file content will overwrite those with the same name created previously
* @author: Le Minh Thu
*/

#include <iostream>
#include <sstream>
#include <string>
#include "TextFile.h"

std::string requestFileNameFromUser(int, char *[]);
void createTextFile(std::string);
void carryOutOperations(TextFile&);
std::string extractContent(std::string);
void processCommand(TextFile&, std::string);
void processCommandAdd(TextFile&, std::string);
void processCommandDisplay(TextFile&);
void processCommandDelete(TextFile&, std::string);
void processCommandClear(TextFile&);
void processCommandExit();
void processCommandSort(TextFile&);
void processCommandSearch(TextFile&, std::string keyWord);
void printOutcomeforAdded(std::string, std::string);
void printOutcomeforCantDisplay(std::string);
void printOutcomeforCantDelete(std::string);
void printOutcomeforDeleted(std::string, std::string);
void printOutcomeforClear(std::string);
void printOutcomeforSorted(std::string);
void printOutcomeforSearch(std::string, std::string, std::string);

bool continueOperation = true;

int main(int argc, char *argv[]){
	std::string fileName = requestFileNameFromUser(argc, argv);
	createTextFile(fileName);
	return 0;
}

std::string requestFileNameFromUser(int argc, char *argv[]){
	std::string fileName;

	// This is the case when TextBuddy.exe is executed through GUI or Visual Studio Debugging mode
	// Only the file name needs to be keyed in manually by user

	if (argc == 1){
		std::getline(std::cin, fileName);
	}

	// This is the case when TextBuddy.exe is executed through commnad-prompt window
	// TextBuddy.exe and <file name> need to be keyed in manually by user

	else
	if (argc == 2){
		fileName = argv[1];
	}

	// Other cases when too many arguments are passed into the program
	else{
		std::cerr << "Invalid input! Please enter: " << argv[0] << " followed by space and <file name>" << std::endl;
		exit(1);
	}

	return fileName;
}

void createTextFile(std::string fileName){
	TextFile newFile(fileName);

	// create a blank txt file
	newFile.writeToFile(fileName);

	std::cout << "Welcome to TextBuddy. " << fileName << " is ready for use" << std::endl;

	carryOutOperations(newFile);
}

void carryOutOperations(TextFile& currentFile){
	std::string userInput;

	while (continueOperation && std::getline(std::cin, userInput)){

		processCommand(currentFile, userInput);
		std::string fileName = currentFile.retrieveFileName();

		// file is saved after each user's operation
		currentFile.writeToFile(fileName);
	}
}

void processCommand(TextFile& currentFile, std::string userInput){
	std::string command;
	std::istringstream in(userInput);
	in >> command;

	if (command == "add"){
		std::string content = extractContent(userInput);
		processCommandAdd(currentFile, content);
	}

	else
	if (command == "display"){
		processCommandDisplay(currentFile);
	}

	else
	if (command == "delete"){
		std::string lineNumber = extractContent(userInput);
		processCommandDelete(currentFile, lineNumber);
	}

	else
	if (command == "clear"){
		processCommandClear(currentFile);
	}

	else
	if (command == "sort"){
		processCommandSort(currentFile);
	}

	else
	if (command == "search"){
		std::string content = extractContent(userInput);
		processCommandSearch(currentFile, content);
	}
	else
	if (command == "exit"){
		processCommandExit();
	}
}

std::string extractContent(std::string userInput){
	size_t firstSpace = userInput.find_first_of(" ");
	size_t firstCharofContent = firstSpace + 1;
	size_t lengthOfContent = userInput.size() - firstSpace;

	std::string content = userInput.substr(firstCharofContent, lengthOfContent);
	return content;
}

void processCommandAdd(TextFile& currentFile, std::string lineContent){
	std::string fileName = currentFile.retrieveFileName();
	currentFile.addCommand(lineContent);
	printOutcomeforAdded(fileName, lineContent);
}

void processCommandDisplay(TextFile& currentFile){
	std::string fileName = currentFile.retrieveFileName();

	bool canDisplay = currentFile.displayAllCommands();
	if (!canDisplay)
		printOutcomeforCantDisplay(fileName);
}

void processCommandDelete(TextFile& currentFile, std::string lineNumber){
	int lineNum = std::stoi(lineNumber);
	
	std::string lineContent;
	std::string fileName = currentFile.retrieveFileName();
	bool isDeleted = currentFile.deleteCommand(lineNum, lineContent);

	if (!isDeleted){
		printOutcomeforCantDelete(fileName);
	}

	else
	if (isDeleted){
		printOutcomeforDeleted(fileName, lineContent);
	}
}

void processCommandClear(TextFile& currentFile){
	std::string fileName = currentFile.retrieveFileName();
	currentFile.clearAllCommands();
	printOutcomeforClear(fileName);
}

void processCommandExit(){
	continueOperation = false;
}

void processCommandSort(TextFile& currentFile){
	std::string fileName = currentFile.retrieveFileName();
	currentFile.sortAllCommands();
	printOutcomeforSorted(fileName);
}

void processCommandSearch(TextFile& currentFile, std::string keyWord){
	std::string fileName = currentFile.retrieveFileName();
	std::string searchResults = currentFile.searchKeyWord(keyWord);
	printOutcomeforSearch(fileName, keyWord, searchResults);
}

void printOutcomeforAdded(std::string fileName, std::string lineContent){
	std::cout << "added to " << fileName << ": \"" << lineContent << "\"" << std::endl;
}

void printOutcomeforCantDelete(std::string fileName){
	std::cout << "Item cannot be found in " << fileName << std::endl;
}

void printOutcomeforDeleted(std::string fileName, std::string lineContent){
	std::cout << "deleted from " << fileName << ": \"" << lineContent << "\"" << std::endl;
}

void printOutcomeforClear(std::string fileName){
	std::cout << fileName << " is empty" << std::endl;
}

void printOutcomeforCantDisplay(std::string fileName){
	std::cout << fileName << " is empty" << std::endl;
}

void printOutcomeforSorted(std::string fileName){
	std::cout << "sorted " << fileName << " in alphabetical order" << std::endl;
}

void printOutcomeforSearch(std::string fileName, std::string keyWord, std::string searchResults){
	std::cout << "In " << fileName << ", " << "search results for " << keyWord << " is:" << std::endl;
	std::cout << searchResults;
}