#include "RegForm.h"
#include "AuthentWindow.h"

RegForm::RegForm(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.regButton, &QPushButton::clicked, this, &RegForm::on_clickedRegFormOK);
	connect(this, SIGNAL(sendRegData(QString, QString)), parent, SLOT(on_clickedRegFormOK(QString, QString)));
	connect(ui.cancelButton, SIGNAL(clicked()), parent, SLOT(on_clickedRegFormCancel()));
	connect(this, SIGNAL(destroyed()), parent, SLOT(on_clickedRegFormCancel()));

	//Атрибут для уничтожения окна после нажатия на X
	setAttribute(Qt::WA_DeleteOnClose);
}

RegForm::~RegForm()
{}

void RegForm::on_clickedRegFormOK()
{
	//Проверка на ввод логина
	if (ui.loginLineEdit->text().isEmpty())
	{
		ui.messageLabel->setText("Введите логин.");
		return;
	}
	// Проверка правельность введёного пароля. Если пароли совпадают
	// посылается сигнал с данными регистрации
	if (ui.passwordLineEdit->text() == ui.passwordLineEdit_2->text())
		emit sendRegData(ui.loginLineEdit->text(), ui.passwordLineEdit->text());
	else
		ui.messageLabel->setText("Пароли не совпадают, повторите попытку.");
}