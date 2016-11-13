#include <QLayout>
#include <QPalette>
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

    pCloseBut = new QPushButton("CLOSE", this);
    connect(pCloseBut, SIGNAL(clicked()), this, SLOT(close()));
//    QHBoxLayout* mainLayout = new QHBoxLayout;
//    mainLayout->addWidget(pFTPBut);
//    mainLayout->addWidget(pHTTPBut);

//    this->setLayout(mainLayout);
    pFTPBut->setGeometry(290, 275, 75, 50);
    pHTTPBut->setGeometry(410, 275, 75, 50);
    pCloseBut->setGeometry(370, 515, 75, 50);

//    pFTPBut->setGeometry(375, 250, 50, 50);
//    pHTTPBut->setGeometry(445, 250, 50, 50);
//    pCloseBut->setGeometry(405, 400, 50, 50);

    QPalette pal;
    pal.setBrush(this->backgroundRole(),QBrush(QPixmap("top.jpg")));
    this->setPalette(pal);
    this->setAutoFillBackground(true);

    this->setFixedHeight(600);
    this->setFixedWidth(800);
}

Interface::~Interface()
{
    delete ui;
}
