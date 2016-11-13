/********************************************************************************
** Form generated from reading UI file 'httpinterface.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HTTPINTERFACE_H
#define UI_HTTPINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HTTPInterface
{
public:

    void setupUi(QWidget *HTTPInterface)
    {
        if (HTTPInterface->objectName().isEmpty())
            HTTPInterface->setObjectName(QStringLiteral("HTTPInterface"));
        HTTPInterface->resize(320, 240);

        retranslateUi(HTTPInterface);

        QMetaObject::connectSlotsByName(HTTPInterface);
    } // setupUi

    void retranslateUi(QWidget *HTTPInterface)
    {
        HTTPInterface->setWindowTitle(QApplication::translate("HTTPInterface", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class HTTPInterface: public Ui_HTTPInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HTTPINTERFACE_H
