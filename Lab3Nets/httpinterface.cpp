#include <QFont>
#include <QDebug>
#include <QLayout>
#include <QSettings>
#include <QByteArray>
#include <QStringList>

#include "httpinterface.h"
#include "ui_httpinterface.h"

HTTPInterface::HTTPInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HTTPInterface)
{
    __print;
    ui->setupUi(this);

    pClient = new HTTPClient();

    pAdrLabel = new QLabel("Net address: ");
    pAdrLabel->setFont(QFont("Courier", 12));

    pTxtLabel = new QLabel("Site's content");
    pTxtLabel->setFont(QFont("Courier", 14, QFont::Bold));

    pStatusInfo = new QLabel("Status: ");
    pStatusInfo->setFont(QFont("Courier", 12, QFont::Bold));

    pStatusLabel = new QLabel();
    pStatusLabel->setFont(QFont("Courier", 12));
    pStatusLabel->setAlignment(Qt::AlignLeft);
    pStatusLabel->setFixedWidth(1000);
    connect(pClient, &HTTPClient::message, pStatusLabel, &QLabel::setText);

    pLoadBut = new QPushButton("Load", this);
    pLoadBut->setFont(QFont("Courier", 12));
    connect(pLoadBut, &QPushButton::clicked, this, &HTTPInterface::load);
    connect(pClient, &HTTPClient::enabled, pLoadBut, &QPushButton::setEnabled);

    pExitBut = new QPushButton("Exit", this);
    pExitBut->setFont(QFont("Courier", 12));
    connect(pExitBut, &QPushButton::clicked, pClient, &HTTPClient::interrupt);
    connect(pExitBut, &QPushButton::clicked, this, &HTTPInterface::close);

    pClearHistoryBut = new QPushButton("Clear History", this);
    pClearHistoryBut->setFont(QFont("Courier", 12));
    connect(pClearHistoryBut, &QPushButton::clicked, this, &HTTPInterface::clearHistory);

    pAddressLine = new QComboBox();
    pAddressLine->setEditable(true);
    pAddressLine->setInsertPolicy(QComboBox::InsertAtBottom);
    pAddressLine->setFont(QFont("Courier", 12));

    pInfoText = new QTextEdit();
    pInfoText->setGeometry(0, 20, 60, 40);
    connect(pClient, &HTTPClient::data, pInfoText, &QTextEdit::setText);

    pErrorBox = new QMessageBox(this);
    connect(pClient, &HTTPClient::error, this, &HTTPInterface::showError);

    QHBoxLayout* butLay = new QHBoxLayout;
    butLay->addWidget(pTxtLabel);
    butLay->addWidget(pLoadBut);
    butLay->addWidget(pExitBut);

    QHBoxLayout* addressLay = new QHBoxLayout;
    addressLay->addWidget(pAdrLabel);
    addressLay->addWidget(pAddressLine);
    addressLay->addWidget(pClearHistoryBut);

    QHBoxLayout* statusLay = new QHBoxLayout;
    statusLay->addWidget(pStatusInfo);
    statusLay->addWidget(pStatusLabel);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(addressLay);
    mainLayout->addLayout(butLay);
    mainLayout->addWidget(pInfoText);
    mainLayout->addLayout(statusLay);

    this->setLayout(mainLayout);

    this->setWindowFlags(Qt::CustomizeWindowHint|
                         Qt::WindowTitleHint);
    this->setWindowTitle("HTTP loader");
    this->setFixedSize(800, 600);
    this->updateHistory();
}

HTTPInterface::~HTTPInterface()
{
    delete ui;
}

void HTTPInterface::load()
{
    QString text = pAddressLine->currentText();
    if(!text.isEmpty() && text.contains("/"))
        pClient->getData(QByteArray(text.toUtf8()));
    this->saveHistory();
    this->updateHistory();
}

void HTTPInterface::saveHistory()
{
    QStringList sites;
    QSettings settings("../Lab3Nets/history.txt", QSettings::IniFormat);

    settings.beginGroup("HISTORY");
    sites = settings.value("sites").toStringList();
    settings.endGroup();

    if(!sites.contains(pAddressLine->currentText()))
    {
        sites.insert(0, pAddressLine->currentText());
        settings.beginGroup("HISTORY");
        settings.setValue("sites", sites);
        settings.endGroup();
    }
}

void HTTPInterface::updateHistory()
{
    QStringList sites;
    QSettings settings("../Lab3Nets/history.txt", QSettings::IniFormat);

    settings.beginGroup("HISTORY");
    sites = settings.value("sites").toStringList();
    settings.endGroup();

    pAddressLine->clear();
    pAddressLine->insertItems(0, sites);
}

void HTTPInterface::clearHistory()
{
    QSettings settings("../Lab3Nets/history.txt", QSettings::IniFormat);
    settings.clear();

    pAddressLine->clearEditText();
    pAddressLine->clear();
}

void HTTPInterface::showError(QString err)
{
    pErrorBox->setWindowTitle("Error");
    pErrorBox->setIcon(QMessageBox::Warning);
    pErrorBox->setText(err);
    pErrorBox->show();
    pStatusLabel->setText("");
}
