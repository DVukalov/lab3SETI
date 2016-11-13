#ifndef HTTPINTERFACE_H
#define HTTPINTERFACE_H

#include <QLabel>
#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

#include "httpclient.h"

namespace Ui {
class HTTPInterface;
}

class HTTPInterface : public QWidget
{
    Q_OBJECT

public:
    explicit HTTPInterface(QWidget *parent = 0);
    ~HTTPInterface();

private slots:
    void load();
    void showError(QString err);

private:
    Ui::HTTPInterface *ui;

    QLabel* pAdrLabel;
    QLabel* pTxtLabel;
    QLabel* pStatusInfo;
    QLabel* pStatusLabel;
    QTextEdit* pInfoText;
    QPushButton* pExitBut;
    QPushButton* pLoadBut;    
    QMessageBox* pErrorBox;
    QLineEdit* pAddressLine;

    HTTPClient* pClient;

};

#endif // HTTPINTERFACE_H
