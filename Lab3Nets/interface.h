#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class Interface;
}

class Interface : public QWidget
{
    Q_OBJECT

public:
    explicit Interface(QWidget *parent = 0);
    ~Interface();

signals:
    void FTP();
    void HTTP();

private:
    Ui::Interface *ui;

    QPushButton* pFTPBut;
    QPushButton* pHTTPBut;
};

#endif // INTERFACE_H
