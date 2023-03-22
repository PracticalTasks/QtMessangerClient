#include "QtMessangerClient.h"

QtMessangerClient::QtMessangerClient(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QtMessangerClientClass())
{
    ui->setupUi(this);
    contactsModel = std::make_unique<QStandardItemModel>();
    QStringList contactsList;
    contactsList << "Ivan" << "Petr" << "BOBAH" << "Serj";

    for (auto& i : contactsList)
    {
        contactsModel->appendRow(new QStandardItem(i));
    }

    ui->listView_conatcts->setModel(contactsModel.get());


    connection = std::make_unique<Connection>();
    connect(ui->pushButton_send, &QPushButton::pressed, [this]()
        {
            
        });
}

QtMessangerClient::~QtMessangerClient()
{
    delete ui;
}
