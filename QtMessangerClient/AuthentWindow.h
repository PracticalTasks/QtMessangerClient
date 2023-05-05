#pragma once

#include <QMainWindow>
#include "ui_AuthentWindow.h"
#include "RegForm.h"
#include "FileSystem.h"
#include "QtMessangerClient.h"
#include "Connection.h"

class AuthentWindow : public QMainWindow
{
	Q_OBJECT

public:
	AuthentWindow(QWidget *parent = nullptr);
	~AuthentWindow();

private:
	Ui::AuthentWindowClass ui;
	std::unique_ptr<RegForm> regForm;
	std::unique_ptr<FileSystem> fileSystem;
	std::unique_ptr<QtMessangerClient> messangerClient;
	std::unique_ptr<Connection> connection;

	QString filePath = "regInfo.txt";

private:
	void setServerInfo();

public slots:
	void on_clickedRegFormOK(QString loginStr, QString passwordStr);
	void on_clickedRegFormCancel();

private slots:
	void on_regLinkButton();
	void on_signInButton();
	

};
