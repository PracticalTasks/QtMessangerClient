#pragma once

#include <QMainWindow>
#include "ui_RegForm.h"

class RegForm : public QMainWindow
{
	Q_OBJECT

public:
	RegForm(QWidget *parent = nullptr);
	~RegForm();

private:
	Ui::RegFormClass ui;
};
