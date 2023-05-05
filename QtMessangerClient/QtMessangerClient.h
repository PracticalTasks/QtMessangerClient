#pragma once

#include <QtWidgets/QWidget>
#include <QStandardItemModel>
#include "ui_QtMessangerClient.h"

#include "Connection.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QtMessangerClientClass; };
QT_END_NAMESPACE

class QtMessangerClient : public QWidget
{
    Q_OBJECT

public:
    QtMessangerClient(QString regData, QWidget *parent = nullptr);
    ~QtMessangerClient();

private:
    void addUsers(QStringList contacstList);
    QStringList extractUserFromData(QString data);

private:
    Ui::QtMessangerClientClass *ui;
    std::unique_ptr<Connection> connection;
    std::unique_ptr<QStandardItemModel> contactsModel;

};
