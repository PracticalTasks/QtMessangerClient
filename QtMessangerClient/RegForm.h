#pragma once

#include <QMainWindow>
#include "ui_RegForm.h"
#include "Connection.h"

//class AuthentWindow;

//Класс описывающий форму для регистрации
class RegForm : public QMainWindow
{
	Q_OBJECT

public:
	RegForm(Connection* _connection, QWidget *parent = nullptr);
	~RegForm();

private:
	Ui::RegFormClass ui;
	Connection* connection = nullptr;

signals:
	void sendRegData(QString loginStr, QString passwordStr);

private slots:
	void on_clickedRegFormOK();
};
