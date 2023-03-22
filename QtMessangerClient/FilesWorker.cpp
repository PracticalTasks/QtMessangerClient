#include "FilesWorker.h"

FilesWorker::FilesWorker()
{
	file = std::make_unique<std::fstream>();

	if (!loadFile(settingsPath))
	{
		QMessageBox::critical(nullptr, "Error", "Cannot load settings");
		return;
	}	

}

void FilesWorker::read()
{
}

void FilesWorker::write()
{
}

bool FilesWorker::loadFile(std::string& filePath)
{
	file->open(filePath, std::ios::in | std::ios::out);

	if (!file)
		return false;

	return true;
}
