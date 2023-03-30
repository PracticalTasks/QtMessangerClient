#include "AuthentWindow.h"

AuthentWindow::AuthentWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.regLinkButton, &QCommandLinkButton::clicked, this, &AuthentWindow::on_regLinkButton);
	
}

AuthentWindow::~AuthentWindow()
{}

void AuthentWindow::on_clickedRegFormOK()
{
	on_destroyedRegForm();
}

void AuthentWindow::on_clickedRegFormCancel()
{
	on_destroyedRegForm();
}

void AuthentWindow::on_destroyedRegForm()
{
	regForm->hide();
	show();
}

void AuthentWindow::on_regLinkButton()
{
	regForm.release();
	regForm = std::make_unique<RegForm>(this);
	hide();
	regForm->show();
}