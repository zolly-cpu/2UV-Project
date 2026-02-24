#ifndef CLFILEWRITER_H_WVD_05062012
#define CLFILEWRITER_H_WVD_05062012

#include <vector>
#include <iostream>

#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QFile>
#include <QtCore/QFileInfo>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNode>
#include <QtXml/QDomElement>
#include <QtCore/QByteArray>
#include <QtCore/QObject>
#include <QtCore/QThread>
#include <QtCore/QDateTime>
#include <QtCore/QTextStream>

using namespace std;


class clFileWriter
{
public:
    clFileWriter (QString paFilePath,QString paFileSize,QString paDiskUsage);
    ~clFileWriter ();
public:
    QString mePath;
    QString meSize;
    QString meDiskUsage;
    QString meCurrentFile;

    bool writeMessageToLogFile(QString paLogNumber,QString paComputerName, QString paApplicationName,QString paApplicationText);

private:
    bool checkFileSize(bool &paFreeSize);
    bool createNewFile(QString &paFileName);
    bool checkDiskSpace(bool &paFreeSpace);
    bool writeMessage(QString paMessage);

    void setPath(QString paPath);
    QString getPath();
    void setSize(QString paSize);
    QString getSize();
    void setDiskUsage(QString paDiskUsage);
    QString getDiskUsage();
    void setCurrentFileName(QString paCurrentFile);
    QString getCurrentFileName();
};

#endif
