#ifndef CLTESTAPPLICATION_H_WVD_14022006
#define CLTESTAPPLICATION_H_WVD_14022006

#include "clIceClient.h"

#include <string>
#include <iostream>

#include "wdClientLogger.h"

#include <QtWidgets/QMainWindow>

#include <QtCore/QString>

#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtCore/QByteArray>
#include <QtCore/QThread>

using namespace std;

class clClientApplication : public QWidget
{

    Q_OBJECT;

public:

    clClientApplication (clIceClient &paIceClient,QWidget* paParent = 0, const char* paName = 0); //, WFlags paFlags = 0);
    ~clClientApplication ();

    Ui::wdClientLogger meClientLogger;
    QThread meThread;

public slots:
    //Slots Camera setup
    void slotButtonPingPressed();
    void slotButtonShutdownPressed();
    void slotButtonSendMessagePressed();
private:
    clIceClient &meIceClient;

};

#endif
