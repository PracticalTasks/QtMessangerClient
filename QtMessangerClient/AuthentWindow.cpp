#include "AuthentWindow.h"

AuthentWindow::AuthentWindow(QWidget *parent)
	: QMainWindow(parent)
	, fileSystem(std::make_unique<FileSystem>())
	, connection(std::make_unique<Connection>())
{
	ui.setupUi(this);
	setServerInfo();
	connect(ui.regLinkButton, &QCommandLinkButton::clicked, this, &AuthentWindow::on_regLinkButton);
	connect(ui.signInButton, &QCommandLinkButton::clicked, this, &AuthentWindow::on_signInButton);
	
}

AuthentWindow::~AuthentWindow()
{}

void AuthentWindow::on_clickedRegFormOK(QString loginStr, QString passwordStr)
{
	loginStr += ':' + passwordStr + '@';
	connection->send(loginStr.toStdString() + static_cast<char>(0x01));
	//fileSystem->write(filePath, loginStr);
	on_clickedRegFormCancel();
}

void AuthentWindow::on_clickedRegFormCancel()
{
	regForm->hide();
	show();
}

void AuthentWindow::setServerInfo()
{
	if (connection->serverConnect)
		ui.serverInfolabel->setText("Сервер online");
	else
		ui.serverInfolabel->setText("Сервер offline");
}

void AuthentWindow::on_regLinkButton()
{
	regForm.release();
	regForm = std::make_unique<RegForm>(connection.get(), this);
	hide();
	regForm->show();
}

void AuthentWindow::on_signInButton()
{
	setServerInfo();
	QString loginStr = ui.loginLineEdit->text();
	//Если не ввели логин
	if (loginStr.isEmpty())
	{
		ui.messagelabel->setText("Введите логин");
		return;
	}
	
	//Создаём объект типа QString из регист. данных полученных от сервера при соеденении 
	QString regData(QString::fromStdString(connection->regDataStr));

	//Проверяем есть ли данные пользователя(логин оканчивается ':')
	qsizetype currentIdx = regData.indexOf(loginStr + ':');
	qsizetype nextIdx = 0;
	if (currentIdx != -1)
	{
		//Увеличеваем текущий idx на количество символов в логине + ':'
		currentIdx += loginStr.size() + 1;
		//После ':' находится пароль и заканчивается '@'
		nextIdx = regData.indexOf('@', currentIdx);
		nextIdx -= currentIdx;
		QString passwordStr = regData.sliced(currentIdx, nextIdx);

		if (passwordStr == ui.passwordLineEdit->text())
		{
			hide();
			messangerClient = std::make_unique<QtMessangerClient>(connection->regDataStr.c_str());
			messangerClient->show();
			return;
		}
	}

	ui.messagelabel->setText("Не верный логин или пароль");

}