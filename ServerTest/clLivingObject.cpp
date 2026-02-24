#define INFO_BUFFER_SIZE 32767
#include "clLivingObject.h"

clLivingObject::clLivingObject(clIceClientServer * paIceClientServer, clIceClientLogging *paIceClientLogging)
{
	try
	{
    meIceClientServer = paIceClientServer;
	meIceClientLogging = paIceClientLogging;
	
	//////// Getting the living object for this machine /////////////////////
	getLivingObjectsForThisWorkstation();
	
	}
	catch(...)
	{
		cout << "clLivingObject::clLivingObject -> failed" << endl;
		
	}
}

clLivingObject::~clLivingObject()
{

}
bool clLivingObject::getLivingObjectsForThisWorkstation()
{
	
	try
	{
		////////////////////////////////////////// Getting the operations ///////////////////////////////////////////////////////////////
		QString loTableName("living_obj_mach");
		vector <std::string> loProperties;
		vector <std::string> loValues;
		vector <std::string> loTypeValues;
		vector <std::string> loLogExp;
		vector <std::string> loReturnIds;
		QString loReturnMessage;
		
		loProperties.push_back(QString("WORKSTATION_NAME").toStdString());
		loValues.push_back(QString(QHostInfo::localHostName()).toStdString());
		loTypeValues.push_back(QString("text").toStdString());
		loLogExp.push_back(QString("=").toStdString());
		
		QString loStart = QString("0");
		QString loStop = QString("0");
		
		
		if (!meIceClientServer->getFromTableDatbaseByProperty(loTableName,loStart,loStop,loProperties,loValues,loTypeValues,loLogExp,loReturnIds,loReturnMessage))
		{
			meIceClientLogging->insertItem("10",QString(QHostInfo::localHostName()),"2UVServerTest.exe","clLivingObject::getLivingObjectsForThisWorkstation() -> " + loReturnMessage);
			return false;
		}
		else
			meIceClientLogging->insertItem("10",QString(QHostInfo::localHostName()),"2UVServerTest.exe","clLivingObject::getLivingObjectsForThisWorkstation() -> " + loReturnMessage);
				
		if (loReturnIds.size() < 1) return false;
		
		for (int i = 0; i < loReturnIds.size(); i++)
		{
			meThread[i] = new QThread();
			meLivingObjectMach[i] = new clLivingObjectMach(meIceClientServer, meIceClientLogging, QString(loReturnIds.at(i).c_str()));
			meLivingObjectMach[i]->moveToThread(meThread[i]);
			/*
worker->moveToThread(thread);
connect( worker, &Worker::error, this, &MyClass::errorString);
connect( thread, &QThread::started, worker, &Worker::process);
connect( worker, &Worker::finished, thread, &QThread::quit);
connect( worker, &Worker::finished, worker, &Worker::deleteLater);
connect( meThread[i], &QThread::finished, meThread[i], &QThread::deleteLater);
			*/
			meThread[i]->start();

			
		}
		return true;
	}
	catch(...)
	{
		return false;
	}
}


