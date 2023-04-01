#include "AuthentWindow.h"

AuthentWindow::AuthentWindow(QWidget *parent)
	: QMainWindow(parent)
	, fileSystem(std::make_unique<FileSystem>())
{
	ui.setupUi(this);
	connect(ui.regLinkButton, &QCommandLinkButton::clicked, this, &AuthentWindow::on_regLinkButton);
	connect(ui.signInButton, &QCommandLinkButton::clicked, this, &AuthentWindow::on_signInButton);
	
}

AuthentWindow::~AuthentWindow()
{}

void AuthentWindow::on_clickedRegFormOK(QString loginStr, QString passwordStr)
{
	loginStr += ':' + passwordStr + '@';
	fileSystem->write(filePath, loginStr);
	on_clickedRegFormCancel();
}

void AuthentWindow::on_clickedRegFormCancel()
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

void AuthentWindow::on_signInButton()
{
	QString dataStr = ui.loginLineEdit->text();
	//Если не ввели логин
	if (dataStr.isEmpty())
	{
		ui.messagelabel->setText("Введите логин");
		return;
	}
		
	//Загружаем файл с данными для авторизации пользователей
	QString regData = fileSystem->loadFile(filePath);
	//Проверяем есть ли данные пользователя(логин оканчивается ':')
	qsizetype currentIdx = regData.indexOf(dataStr + ':');
	qsizetype nextIdx = 0;
	if (currentIdx != -1)
	{
		//Увеличеваем текущий idx на количество символов в логине + ':'
		currentIdx += dataStr.size() + 1;
		//После ':' находится пароль и заканчивается '@'
		nextIdx = regData.indexOf('@', currentIdx);
		nextIdx -= currentIdx;
		dataStr = regData.sliced(currentIdx, nextIdx);

		if (dataStr == ui.passwordLineEdit->text())
		{
			hide();
			messangerClient = std::make_unique<QtMessangerClient>();
			messangerClient->show();
		}
	}

	ui.messagelabel->setText("Не верный логин или пароль");



}