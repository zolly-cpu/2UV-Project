#ifndef CLGRAPHVIEW_H_WVD
#define CLGRAPHVIEW_H_WVD

#include <string>
#include <iostream>
#include <vector>

#include <Ice/Ice.h>
#include <IceUtil/Mutex.h>
#include <IceUtil/CtrlCHandler.h>
#include <IceUtil/IceUtil.h>

#include <QtCore/QString>
#include <QtCore/QDateTime>

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QAction>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QListWidgetItem>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QGraphicsObject>
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QAbstractItemView>
#include <QtNetwork/QHostInfo>
#include <QtCore/QStorageInfo>

#include <QtCore/QByteArray>
#include <QtCore/QString>
#include <QtCore/QFile>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNode>	
#include <QtXml/QDomElement>
#include <QtCore/QObject>
#include <QtCore/QThread>
#include <QtCore/QTimer>

#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChartView>
#include <QtCharts/QCategoryAxis>

#include <QtGui/QBrush>
#include <QtGui/QFont>


#include "clIceClientLogging.h"
#include "clIceClientServer.h"
#include "clGraphLine.h"
#include "clQuery.h"

using namespace std;
using namespace QtCharts;

class clGraphView : public QChartView
{
	Q_OBJECT
public:
    clGraphView(clIceClientServer * paIceClientServer, clIceClientLogging * paIceClientLogging, QString paXmlFile);
    ~clGraphView();

public:
	bool readXmlFile(QString paXmlFile);
	
public slots:
	void slotDoIt();
	
private:
	bool addGraphLine(vector<QString> paValuesX, QString paTypeX, vector<QString> paValuesY, QString paTypeY, QString paName, QString paColor);

	QTimer * meTimer;

    //Communication class logging client
    clIceClientLogging * meIceClientLogging;
    clIceClientServer * meIceClientServer;


	QGraphicsItem * meGraphicsItem;
	QChart * meChart;
	QLineSeries * meSeries[200];
	
	QString meGraphClass;
	QString meGraphProperty;
	QString meGraphType;
	QString meGraphValue;
	QString meGraphRefresh;
	QString meGraphExpression;
	vector<clGraphLine> meGraphLines;
	
	
};
#endif

