#pragma once

#include <QMainWindow>
#include "ui_AuthentWindow.h"
#include "RegForm.h"

class AuthentWindow : public QMainWindow
{
	Q_OBJECT

public:
	AuthentWindow(QWidget *parent = nullptr);
	~AuthentWindow();

private:
	Ui::AuthentWindowClass ui;
	std::unique_ptr<RegForm> regForm;

public slots:
	void on_clickedRegFormOK();
	void on_clickedRegFormCancel();
	void on_destroyedRegForm();

private slots:
	void on_regLinkButton();

};
