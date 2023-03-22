#pragma once
#include <fstream>
#include <QMessageBox>

class FilesWorker
{
public:
	FilesWorker();
	void read();
	void write();

private:
	bool loadFile(std::string& filePath);

private:
	std::unique_ptr<std::fstream> file;

	std::string settingsPath = "contacts.txt";
	

};
