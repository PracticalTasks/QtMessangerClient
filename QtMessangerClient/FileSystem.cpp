#include "FileSystem.h"
#include <QFileDialog>


FileSystem::FileSystem()
    :file(std::make_unique<QFile>())
{

}

void FileSystem::read()
{
}

void FileSystem::write(QString& filePath, QString& writeStr)
{
    if (!filePath.isEmpty())
    {
        if (filePath.endsWith(".txt"))
        {
            file->setFileName(filePath);
            if (file->open(QFile::WriteOnly | QIODevice::Append))
            {
                QTextStream stream(file.get());
                stream << writeStr;
            }
        }
    }
}

QString FileSystem::loadFile(QString& filePath)
{
    file->setFileName(filePath);
    if (file->open(QFile::ReadOnly | QFile::ExistingOnly))
        filePath = file->readAll();

	return filePath;
}
