/**
* This class is used to store name and content of a text file and perform modification on the content of the text file
* @author: Le Minh Thu
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include "TextFile.h"

TextFile::TextFile(std::string fileName){
	this->fileName = fileName;
}


TextFile::~TextFile(){
}

bool TextFile::isEmpty() const{
	return fileContent.size() == 0;
}

void TextFile::addCommand(std::string command){
	fileContent.push_back(command);
}

bool TextFile::deleteCommand(int lineNumber, std::string& contentToBeDeleted){
	if (lineNumber > fileContent.size()){
		return false;
	}

	contentToBeDeleted = fileContent[lineNumber - 1];
	std::vector<std::string>::iterator indexToBeDeleted = fileContent.begin() + lineNumber - 1;
	fileContent.erase(indexToBeDeleted);
	return true;
}

void TextFile::clearAllCommands(){
	TextFile::fileContent.clear();
}

bool TextFile::displayAllCommands(){
	if (TextFile::isEmpty()){
		return false;
	}

	std::string allFileContent = TextFile::toString();
	std::cout << allFileContent;
	return true;
}

void TextFile::writeToFile(std::string fileName){
	std::ofstream write(fileName);
	std::string allFileContent = TextFile::toString();
	write << allFileContent;
	write.close();
}

std::string TextFile::toString(){
	std::ostringstream out;

	for (int index = 0; index < fileContent.size(); index++){
		int lineNum = index + 1;
		out << lineNum << ".\t" << fileContent[index] << std::endl;
	}

	return out.str();
}

std::string TextFile::retrieveFileName() const{
	return fileName;
}

void TextFile::sortAllCommands(){
	std::sort(fileContent.begin(), fileContent.end());
}

std::string TextFile::searchKeyWord(std::string keyWord){
	std::string lineWithKeyWord;
	return lineWithKeyWord;
}
