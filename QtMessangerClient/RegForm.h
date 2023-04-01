#pragma once

#include <QMainWindow>
#include "ui_RegForm.h"

class AuthentWindow;

//Класс описывающий форму для регистрации
class RegForm : public QMainWindow
{
	Q_OBJECT

public:
	RegForm(QWidget *parent = nullptr);
	~RegForm();

private:
	Ui::RegFormClass ui;

signals:
	void sendRegData(QString loginStr, QString passwordStr);

private slots:
	void on_clickedRegFormOK();
};
