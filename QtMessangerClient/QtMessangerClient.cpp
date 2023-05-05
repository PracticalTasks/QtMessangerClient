#include "QtMessangerClient.h"

QtMessangerClient::QtMessangerClient(QString regData, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QtMessangerClientClass())
{
    ui->setupUi(this);
    addUsers(extractUserFromData(regData));

    connection = std::make_unique<Connection>();
    connect(ui->pushButton_send, &QPushButton::pressed, [this]()
        {
            
        });
}

QtMessangerClient::~QtMessangerClient()
{
    delete ui;
}

void QtMessangerClient::addUsers(QStringList contactsList)
{
    contactsModel = std::make_unique<QStandardItemModel>();
    //QStringList contactsList;
    //int currentIdx = 0;
    //int nextIdx = data.indexOf(':');
    //while (nextIdx != -1)
    //{
    //    contactsList << data.sliced(currentIdx, nextIdx);
    //    currentIdx = nextIdx;
    //    nextIdx = data.indexOf(':');

    //}

    //contactsList << "Ivan" << "Petr" << "BOBAH" << "Serj";

    for (auto& i : contactsList)
    {
        contactsModel->appendRow(new QStandardItem(i));
    }

    ui->listView_conatcts->setModel(contactsModel.get());

}

QStringList QtMessangerClient::extractUserFromData(QString data)
{
    QStringList contactsList;
    int currentIdx = 0;
    int nextIdx = data.indexOf(':');
    while (nextIdx != -1)
    {
        contactsList << data.sliced(currentIdx, (nextIdx - currentIdx));
        currentIdx = data.indexOf('@', nextIdx) + 1;
        nextIdx = data.indexOf(':', currentIdx);
    }

    return contactsList;
}
