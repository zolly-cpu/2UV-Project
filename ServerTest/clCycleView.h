#ifndef CLCYCLEVIEW_H
#define CLCYCLEVIEW_H

#include <exception>
#include <string>
#include <iostream>
#include <dlfcn.h>

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
#include <QtWidgets/QMessageBox>
#include <QtGui/QStandardItemModel>
#include <QtGui/QStandardItem>
#include <QtCore/QList>
#include <QtCore/QVariant>
#include <QtCore/QSignalMapper>
#include <QtCore/QThread>
#include <QtCore/QTextStream>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QDoubleSpinBox>

#ifdef WIN32
#include <QtCore/qtalgorithms>
#elif defined(_WIN32)
#include <QtCore/qtalgorithms>
#elif defined(__WIN32)
#include <QtCore/qtalgorithms>
#elif defined(__WIN32__)
#include <QtCore/qtalgorithms>
#else
#include <QtCore/QtAlgorithms>
#endif


#include "clIceClientLogging.h"
#include "clIceClientServer.h"
#include "clDatabaseColumn.h"
#include "clDatabaseAction.h"
#include "clWorkstationCycles.h"
#include "clWorkstationCycle.h"




using namespace std;

class clCycleView : public QWidget
{

    Q_OBJECT;

public:

    clCycleView (clIceClientServer * paIceClientServer, clIceClientLogging *paIceClientLogging, clWorkstationCycles *paWorkstationCycles, QWidget* paParent = 0, const char* paName = 0); //, WFlags paFlags = 0);
    ~clCycleView ();

private slots:
	void slotUpdateValues();
	void slotButtonStartPressed();
	void slotButtonStopPressed();
	void slotButtonDebugPressed();
	void slotButtonResetPressed();
	void slotButtonSetDelayPressed();
private:
    clIceClientLogging * meIceClientLogging;
    clIceClientServer * meIceClientServer;
	clWorkstationCycles * meWorkstationCycles;
	
	void initializeUI();
	void readMappingIcons();

	vector <QString> meIcon;
	vector <QString> meClass;
	
	enum { NumGridRows = 200, NumButtons = 20 };
	
    QLabel *meLabels[NumButtons][NumGridRows];
	QDateTimeEdit *meDateTimeEdit[NumButtons][NumGridRows];
    QLineEdit *meLineEdits[NumButtons][NumGridRows];
	
	QLabel *meLabelsGeneral[NumButtons];
    QPushButton *meButtons[NumButtons];
	QDoubleSpinBox *meSpinBox[NumButtons];
	
	QGridLayout *layout;
	QScrollArea *scrollArea;
	
	QTimer * meTimer;
	
	/*
		//Add the viewport to the scroll area
	scrollArea = new QScrollArea;
	scrollArea->setWidget(viewport);
	
    meMainLayout->addWidget(scrollArea);
	*/
};

#endif
