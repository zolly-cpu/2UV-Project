#define INFO_BUFFER_SIZE 32767
#include "clWorkstationCycles.h"

clWorkstationCycles::clWorkstationCycles(clIceClientServer * paIceClientServer, clIceClientLogging *paIceClientLogging)
{
	try
	{
		meIceClientServer = paIceClientServer;
		meIceClientLogging = paIceClientLogging;
		
		//////// Getting the cycles for this machine /////////////////////
		getWorkstationCycles();
	}
	catch(...)
	{
		cout << "clWorkstationCycles::clWorkstationCycles -> failed" << endl;
	}
}

clWorkstationCycles::~clWorkstationCycles()
{
	for (int i=0; i < 20; i++)
	{
	
	}
}
bool clWorkstationCycles::getWorkstationCycles()
{
	
	try
	{
		////////////////////////////////////////// Getting the cycles ///////////////////////////////////////////////////////////////
		QString loTableName("cycles");
		vector <std::string> loProperties;
		vector <std::string> loValues;
		vector <std::string> loTypeValues;
		vector <std::string> loLogExp;
		vector <std::string> loReturnIds;
		QString loReturnMessage;
		
		loProperties.push_back(QString("WORKSTATION_NAME").toStdString());
		loValues.push_back(string(QString(QHostInfo::localHostName()).toUtf8()));
		loTypeValues.push_back(QString("varchar(255)").toStdString());
		loLogExp.push_back(QString("=").toStdString());
		
		
		
		QString loStart = QString("0");
		QString loStop = QString("0");
		
		
		
		if (!meIceClientServer->getFromTableDatbaseByProperty(loTableName,loStart,loStop,loProperties,loValues,loTypeValues,loLogExp,loReturnIds,loReturnMessage))
		{
			meIceClientLogging->insertItem("10",QString(QHostInfo::localHostName()),"2UVServerTest.exe","clWorkstationCycles::getWorkstationCycles() -> " + loReturnMessage);
			return false;
		}
		else
			meIceClientLogging->insertItem("10",QString(QHostInfo::localHostName()),"2UVServerTest.exe","clWorkstationCycles::getWorkstationCycles() -> " + loReturnMessage);
				
		if (loReturnIds.size() < 1) return false;
		
		//Initialise the threads
		for(int i=0; i < 20; i++)
		{
			meWorkstationCycle[i] = NULL;
		}
		
		//Set the threads
		for (int i = 0; i < (int) loReturnIds.size(); i++)
		{
			//Starting the threads//
			meWorkstationCycle[i] = new clWorkstationCycle(meIceClientServer, meIceClientLogging, QString(loReturnIds.at(i).c_str()), &meLock, this);
			connect(meWorkstationCycle[i], &clWorkstationCycle::resultReady, this, &clWorkstationCycles::handleResults);
			//connect(meWorkstationCycle[i], &clWorkstationCycle::finished, meWorkstationCycle[i], &QObject::deleteLater);
			meWorkstationCycle[i]->start();
		}
		return true;
	}
	catch(...)
	{
		return false;
	}
}
void clWorkstationCycles::handleResults(const QString &)
{
	try
	{
		
	}
	catch(...)
	{
		
	}	
}


