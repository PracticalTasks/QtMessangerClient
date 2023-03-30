#include "RegForm.h"
#include "AuthentWindow.h"

RegForm::RegForm(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.regButton, SIGNAL(clicked()), parent, SLOT(on_clickedRegFormOK()));
	connect(ui.cancelButton, SIGNAL(clicked()), parent, SLOT(on_clickedRegFormCancel()));
	connect(this, SIGNAL(destroyed()), parent, SLOT(on_destroyedRegForm()));
	setAttribute(Qt::WA_DeleteOnClose);
}

RegForm::~RegForm()
{}
