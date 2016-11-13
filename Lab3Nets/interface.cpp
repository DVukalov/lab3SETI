#include <QLayout>

#include "interface.h"
#include "ui_interface.h"

Interface::Interface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Interface)
{
    ui->setupUi(this);

    pFTPBut = new QPushButton("FTP", this);
    connect(pFTPBut, SIGNAL(clicked()), this, SIGNAL(FTP()));

    pHTTPBut = new QPushButton("HTTP", this);
    connect(pHTTPBut, SIGNAL(clicked()), this, SIGNAL(HTTP()));

    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addWidget(pFTPBut);
    mainLayout->addWidget(pHTTPBut);

    this->setLayout(mainLayout);
}

Interface::~Interface()
{
    delete ui;
}
