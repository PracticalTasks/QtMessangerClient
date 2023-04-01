#pragma once
#include <QMainWindow>
#include <fstream>
#include <QDir>
#include <QMessageBox>

class FileSystem : public QMainWindow
{
public:
	FileSystem();
	void read();
	void write(QString& filePath, QString& writeStr);
	QString loadFile(QString& filePath);

private:
	//std::unique_ptr<std::fstream> file;
	std::unique_ptr<QFile> file;

	std::string settingsPath = "contacts.txt";
	

};
