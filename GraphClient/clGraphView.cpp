#define INFO_BUFFER_SIZE 32767
#include "clGraphView.h"

clGraphView::clGraphView(clIceClientServer * paIceClientServer, clIceClientLogging * paIceClientLogging, QString paXmlFile) : QChartView()
{
    try
    {
        //this->resize(682,297);
		//horizontalScrollBar()->setRange(0, 0);
		//verticalScrollBar()->setRange(0, 0);
		
		
		
		
		//this->setParent(parent);
		meIceClientLogging = paIceClientLogging;
		meIceClientServer = paIceClientServer;
		
		
		
		cout << "XML file to read:" << paXmlFile.toStdString() << endl;
		if (!readXmlFile(paXmlFile))cout << "Problem reading xml file ..." << endl;
		else cout << "xml file readed ..." << endl;
		//meWorkstationStatus = paWorkstationStatus;
		/*
        doSetup(meThread);
        moveToThread(&meThread);
        meThread.start();
		*/
		//meGraphicsItem = new QGraphicsItem(this);
		
		meChart = new QChart();
		this->setChart(meChart);
		
		//QWidget * object = qobject_cast< QWidget * >(this);
		//meChart = new QChart(object);
		//meChart->setParent(object);
	
		
		
		
		
		
		
		//setUpWidget();
		//setTimingsInGraph();
		
		meTimer = new QTimer(this);
        meTimer->setInterval(meGraphRefresh.toInt());
        meTimer->connect(meTimer, SIGNAL(timeout()), this, SLOT(slotDoIt()));
        meTimer->start();
		
		

		
		
    }
    catch(...)
    {
		cout << "clGraphView::clGraphView -> constructor fail ..." << endl;
    }
}

clGraphView::~clGraphView()
{
	try
	{
		//this->close();
		//meChart->deleteLater();
		//meChartView->deleteLater();
	}
	catch(...)
	{
		
	}
}

/*****************************
* UI functions
*****************************/
void clGraphView::slotDoIt()
{
	
    try
    {
		////////////////////////////////////////// Getting the operations ///////////////////////////////////////////////////////////////
		vector <std::string> loProperties;
		vector <std::string> loValues;
		vector <std::string> loTypeValues;
		vector <std::string> loLogExp;
		vector <std::string> loReturnIds;
		QString loReturnMessage;
		
		loProperties.push_back(meGraphProperty.toStdString());
		loValues.push_back(meGraphValue.toStdString());
		loTypeValues.push_back(meGraphType.toStdString());
		loLogExp.push_back(meGraphExpression.toStdString());
		
		QString loStart = QString("0");
		QString loStop = QString("0");
		if (!meIceClientServer->getFromTableDatbaseByProperty(meGraphClass,loStart,loStop,loProperties,loValues,loTypeValues,loLogExp,loReturnIds,loReturnMessage))
		{
			meIceClientLogging->insertItem("10",QString(QHostInfo::localHostName()),"2UVGraphClient.exe","clGraphView::slotDoIt() -> " + loReturnMessage);
			return;
		}
		else
			meIceClientLogging->insertItem("10",QString(QHostInfo::localHostName()),"2UVGraphClient.exe","clGraphView::slotDoIt() -> " + loReturnMessage);
		
		if (loReturnIds.size() < 1)
		{
			meIceClientLogging->insertItem("10",QString(QHostInfo::localHostName()),"2UVGraphClient.exe","clGraphView::slotDoIt() -> no result returned");
			return;
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		
		for (int r = 0; r < 200; r++)
		{
			meSeries[r] = NULL;
		}
		for (int r = 0; r < meGraphLines.size(); r++)
		{
			meSeries[r] = new QLineSeries;
		}
		
		
		
		//Clear the graph lines//
		meChart->removeAllSeries();
		
		//Remove the axes
		QList<QAbstractAxis *>	axes = meChart->axes(Qt::Horizontal|Qt::Vertical);
		for (int r = 0; r < axes.size(); r++)
		{
			meChart->removeAxis(axes.at(r));
		}
		
		
	
		
		QString loID("");
		QString loClass("");
		QString loProperty("");
		QString loTypeX("");
		QString loTypeY("");
		QString loValue("");
			
		for (int i = 0; i < loReturnIds.size(); i++)
		{
				vector <QString> loResultX;
				vector <QString> loResultY;
				
				loResultX.clear();
				loResultY.clear();

				for (int t = 0; t < meGraphLines.size(); t++)
				{
			
					clGraphLine loGraphLine = meGraphLines.at(t);
					vector <clQuery> meQuery_X = loGraphLine.getQuery_X();
					vector <clQuery> meQuery_Y = loGraphLine.getQuery_Y();


					loID = QString(loReturnIds.at(i).c_str());

					for (int k = 0; k < meQuery_X.size(); k++)
					{
						loClass = meQuery_X.at(k).getClass();
						loProperty = meQuery_X.at(k).getProperty();
						loTypeX = meQuery_X.at(k).getType();
						/*
							virtual bool getFromTableDatabaseById(  QString& paTableName,
												QString& paId,
												vector<std::string>& paProperties,
												vector<std::string>& paReturnValue,
												QString& paReturnMessage);
						*/
						
						vector <std::string> loPropertiesSub;
						loPropertiesSub.clear();
						loPropertiesSub.push_back(loProperty.toStdString());
						vector <std::string> loValuesSub;
						loValuesSub.clear();
						QString loReturnMessageSub;
						
						
						if (!meIceClientServer->getFromTableDatabaseById(loClass, loID,loPropertiesSub,loValuesSub,loReturnMessageSub))
						{
							meIceClientLogging->insertItem("10",QString(QHostInfo::localHostName()),"2UVGraphClient.exe","clGraphView::slotDoIt() -> " + loReturnMessageSub);
							return;
						}
						else
							meIceClientLogging->insertItem("10",QString(QHostInfo::localHostName()),"2UVGraphClient.exe","clGraphView::slotDoIt() -> " + loReturnMessageSub);
						
						if(loValuesSub.size() < 1)
						{
							meIceClientLogging->insertItem("10",QString(QHostInfo::localHostName()),"2UVGraphClient.exe","clGraphView::slotDoIt() -> no result");
							return;
						}
						
						//Setting the new id or get the value
						if (loTypeX.toUpper().compare(QString("UUID")) == 0)
							loID = QString(loValuesSub.at(0).c_str());
						else
						{
							loResultX.push_back(QString(loValuesSub.at(0).c_str()));
							break;
						}
					}
					
					loID = QString(loReturnIds.at(i).c_str());
					
					for (int l = 0; l < meQuery_Y.size(); l++)
					{
						loClass = meQuery_Y.at(l).getClass();
						loProperty = meQuery_Y.at(l).getProperty();
						loTypeY = meQuery_Y.at(l).getType();
						/*
							virtual bool getFromTableDatabaseById(  QString& paTableName,
												QString& paId,
												vector<std::string>& paProperties,
												vector<std::string>& paReturnValue,
												QString& paReturnMessage);
						*/
						
						vector <std::string> loPropertiesSub;
						loPropertiesSub.clear();
						loPropertiesSub.push_back(loProperty.toStdString());
						vector <std::string> loValuesSub;
						loValuesSub.clear();
						QString loReturnMessageSub;					
						
						if (!meIceClientServer->getFromTableDatabaseById(loClass, loID,loPropertiesSub,loValuesSub,loReturnMessageSub))
						{
							meIceClientLogging->insertItem("10",QString(QHostInfo::localHostName()),"2UVGraphClient.exe","clGraphView::slotDoIt() -> " + loReturnMessageSub);
							return;
						}
						else
							meIceClientLogging->insertItem("10",QString(QHostInfo::localHostName()),"2UVGraphClient.exe","clGraphView::slotDoIt() -> " + loReturnMessageSub);
						
						if(loValuesSub.size() < 1)
						{
							meIceClientLogging->insertItem("10",QString(QHostInfo::localHostName()),"2UVGraphClient.exe","clGraphView::slotDoIt() -> no result");
							return;
						}
						
						//Setting the new id or get the value
						if (loTypeY.toUpper().compare(QString("UUID")) == 0)
							loID = QString(loValuesSub.at(0).c_str());
						else
						{
							loResultY.push_back(QString(loValuesSub.at(0).c_str()));
							break;
						}
					}
				}
				
				if (!addGraphLine(loResultX, loTypeX, loResultY, loTypeY, "test","blue"))
				{
					meIceClientLogging->insertItem("10",QString(QHostInfo::localHostName()),"2UVGraphClient.exe","clGraphView::slotDoIt() -> could not add values to graph ...");
					break;
				}
				else
					meIceClientLogging->insertItem("10",QString(QHostInfo::localHostName()),"2UVGraphClient.exe","clGraphView::slotDoIt() -> addGraphLine called with success ...");
		}
			
		//Add series to the chart	
		for (int u = 0; u < 200; u++)
		{
			if (meSeries[u] != NULL)
			{
				meChart->addSeries(meSeries[u]);
			}
		}
		
		
		//Set the axes values
		QDateTimeAxis *axisY;		
		QDateTimeAxis *axisX;
		QValueAxis *axisXval;
		QValueAxis *axisYval;
				
		if (loTypeX.compare(QString("timestamp")) == 0 && loTypeY.compare(QString("timestamp")) == 0)
		{
			
			axisX = new QDateTimeAxis;
			axisX->setFormat("dd-MM-yyyy h:mm:ss");
			
			axisY = new QDateTimeAxis;
			axisY->setFormat("dd-MM-yyyy h:mm:ss");
			
			meChart->addAxis(axisX, Qt::AlignBottom);
			meChart->addAxis(axisY, Qt::AlignLeft);

			for (int w = 0; w < 200; w++)
			{
				if (meSeries[w] != NULL)
				{
					meSeries[w]->attachAxis(axisX);
					meSeries[w]->attachAxis(axisY);					
				}
			}

		}
		else if (loTypeX.compare(QString("timestamp")) != 0 && loTypeY.compare(QString("timestamp")) == 0)
		{					
			axisY = new QDateTimeAxis;
			axisY->setFormat("dd-MM-yyyy h:mm:ss");
			
			axisXval = new QValueAxis;
			axisXval->setMin(0);				
			
			meChart->addAxis(axisXval, Qt::AlignBottom);
			meChart->addAxis(axisY, Qt::AlignLeft);							
			for (int w = 0; w < 200; w++)
			{
				if (meSeries[w] != NULL)
				{
					meSeries[w]->attachAxis(axisXval);
					meSeries[w]->attachAxis(axisY);					
				}
			}
		}
		else if (loTypeX.compare(QString("timestamp")) == 0 && loTypeY.compare(QString("timestamp")) != 0)
		{
			
			
			axisX = new QDateTimeAxis;
			axisX->setFormat("dd-MM-yyyy h:mm:ss");
			
			axisYval = new QValueAxis;
			axisYval->setMin(0);				
			
			meChart->addAxis(axisX, Qt::AlignBottom);
			meChart->addAxis(axisYval, Qt::AlignLeft);							
			//meSeries[0]->attachAxis(axisX);
			//meSeries[0]->attachAxis(axisYval);
			for (int w = 0; w < 200; w++)
			{
				if (meSeries[w] != NULL)
				{
					meSeries[w]->attachAxis(axisX);
					meSeries[w]->attachAxis(axisYval);					
				}
			}
		}
		else if (loTypeX.compare(QString("timestamp")) != 0 && loTypeY.compare(QString("timestamp")) != 0)
		{
			

			axisXval = new QValueAxis;
			axisXval->setMin(0);				
			
			axisYval = new QValueAxis;
			axisYval->setMin(0);				
			
			meChart->addAxis(axisXval, Qt::AlignBottom);
			meChart->addAxis(axisYval, Qt::AlignLeft);							
			for (int w = 0; w < 200; w++)
			{
				if (meSeries[w] != NULL)
				{
					meSeries[w]->attachAxis(axisXval);
					meSeries[w]->attachAxis(axisYval);					
				}
			}
		}
    }
    catch(exception &e)
    {
		meIceClientLogging->insertItem("10",QString(QHostInfo::localHostName()),"2UVServerTest.exe","clGraphView::slotDoIt() -> " + QString(e.what()));
    }
}
bool clGraphView::readXmlFile(QString paXmlFile)
{
	try
	{
        QString loFileName = paXmlFile;

        QFile loFile(loFileName);
        if ( !loFile.open( QIODevice::ReadOnly ) ) {
			cout << "Could not open file: " << loFileName.toStdString() << endl;
            return false;
        }

        //QDomDocument
        QDomDocument loDomDocument;
        if ( !loDomDocument.setContent( &loFile ) ) {
            loFile.close();
			cout << "Could not parse file: " << loFileName.toStdString() << endl;
            return false;
        }
		
		
        // create the tree view out of the DOM
		QDomElement loDocElem = loDomDocument.documentElement();

		QDomNode loDomNode = loDocElem.firstChild();
		while( !loDomNode.isNull() ) 
		{
			cout << "loDomNode" << endl;
          if(loDomNode.nodeName() == "operationQuery")
          {
              QDomElement loDocElemChild = loDomNode.toElement(); // try to convert the node to an element.
              if( !loDocElemChild.isNull() )// the node was really an element.
              {
                  if (loDocElemChild.hasAttribute(QString("class")))
                  {
                        meGraphClass = loDocElemChild.attribute("class");
                  }
                  if (loDocElemChild.hasAttribute(QString("property")))
                  {
                        meGraphProperty = loDocElemChild.attribute("property");
                  }
                  if (loDocElemChild.hasAttribute(QString("type")))
                  {
                        meGraphType = loDocElemChild.attribute("type");
                  }
                  if (loDocElemChild.hasAttribute(QString("value")))
                  {
                        meGraphValue = loDocElemChild.attribute("value");
                  }
                  if (loDocElemChild.hasAttribute(QString("refreshMS")))
                  {
                        meGraphRefresh = loDocElemChild.attribute("refreshMS");
                  }				  
                  if (loDocElemChild.hasAttribute(QString("expression")))
                  {
                        meGraphExpression = loDocElemChild.attribute("expression");
                  }						  
              }
          }
          if(loDomNode.nodeName() == "GraphLines")
          {
              QDomElement loDocElemChild = loDomNode.toElement();
              if(!loDocElemChild.isNull())
              {
				//Get the Graphline nodes
				QDomNode loNodeGraphLine = loDocElemChild.firstChild();
				
				vector<clGraphLine> loGraphLine;
				
				while(!loNodeGraphLine.isNull())
				{
					cout << "loNodeGraphLine" << endl;
					cout << loNodeGraphLine.nodeName().toStdString() << endl;
					QDomElement loNodeGraphLineElem = loNodeGraphLine.toElement();
					QDomNode loNodeGraphLineXY = loNodeGraphLineElem.firstChild();
					
					
					
					vector<clQuery> loGraphLineQuerys_X;
					vector<clQuery> loGraphLineQuerys_Y;
					QString loName;
					QString loColor;
					
					while(!loNodeGraphLineXY.isNull())
					{						
						cout << "loNodeGraphLineXY" << endl;
						QDomElement loNodeGraphLineXYElem = loNodeGraphLineXY.toElement();
						
						loName = loNodeGraphLineXYElem.attribute("name");
						loColor = loNodeGraphLineXYElem.attribute("color");
													
						QDomNode loNodeQuery = loNodeGraphLineXYElem.firstChild();
						while(!loNodeQuery.isNull())
						{
							cout << "loNodeQuery" << endl;
							QDomElement loNodeQueryElem = loNodeQuery.toElement();
							clQuery loQuery(loNodeQueryElem.attribute("class"),loNodeQueryElem.attribute("property"),loNodeQueryElem.attribute("type"));
							if(loNodeGraphLineXY.nodeName() == "valueQuery_Y")loGraphLineQuerys_Y.push_back(loQuery);
							if(loNodeGraphLineXY.nodeName() == "valueQuery_X")loGraphLineQuerys_X.push_back(loQuery);
							loNodeQuery = loNodeQuery.nextSibling();
						}
						loNodeGraphLineXY = loNodeGraphLineXY.nextSibling();
					}
					clGraphLine loGraphLine(loColor,loName,loGraphLineQuerys_X,loGraphLineQuerys_Y);
					meGraphLines.push_back(loGraphLine);
					
					loGraphLineQuerys_X.clear();
					loGraphLineQuerys_Y.clear();
					
					loNodeGraphLine = loNodeGraphLine.nextSibling();
				}
				
              }
          }		  
          loDomNode = loDomNode.nextSibling();
		}
		return true;
	}
    catch(exception &e)
    {
		meIceClientLogging->insertItem("10",QString(QHostInfo::localHostName()),"2UVServerTest.exe","clGraphView::readXmlFile() -> " + QString(e.what()));
		return false;
    }
	
}
/************************************************
* Do thread startup
************************************************/
bool clGraphView::addGraphLine(vector<QString> paValuesX, QString paTypeX, vector<QString> paValuesY, QString paTypeY, QString paName, QString paColor)
{
	try
	{
		//meChart->removeAllSeries();
		/*
		meSeries = new QLineSeries;
		meSeries->clear();
		
		
	    // Customize chart title
		QFont font;
		font.setPixelSize(18);
		meChart->setTitleFont(font);
		meChart->setTitleBrush(QBrush(Qt::blue));
		*/

		QDateTimeAxis *axisY;		
		QDateTimeAxis *axisX;
		QValueAxis *axisXval;
		QValueAxis *axisYval;
			
		if (paTypeX.compare(QString("timestamp")) == 0 && paTypeY.compare(QString("timestamp")) == 0)
		{
			cout << "Chart 1" << endl;
			for (int i=0; i < (int) paValuesX.size(); i++)
			{
				meSeries[i]->append((QDateTime::fromString(paValuesX.at(i),"yyyy-MM-dd HH:mm:ss.zzz")).toMSecsSinceEpoch(),(QDateTime::fromString(paValuesY.at(i),"yyyy-MM-dd HH:mm:ss.zzz")).toMSecsSinceEpoch());
			}
			/*
			meChart->addSeries(meSeries);
			
			axisX = new QDateTimeAxis;
			axisX->setFormat("dd-MM-yyyy h:mm:ss");

			axisY = new QDateTimeAxis;
			axisY->setFormat("dd-MM-yyyy h:mm:ss");					
			
			meChart->setAxisX(axisX, meSeries);
			meChart->setAxisY(axisY, meSeries);
			*/
		}
		else if (paTypeX.compare(QString("timestamp")) != 0 && paTypeY.compare(QString("timestamp")) == 0)
		{
			cout << "Chart 2" << endl;
			for (int i=0; i < (int) paValuesX.size(); i++)
			{
				meSeries[i]->append((qreal)(paValuesX.at(i).toDouble()),(QDateTime::fromString(paValuesY.at(i),"yyyy-MM-dd HH:mm:ss.zzz")).toMSecsSinceEpoch());	
			}
			/*
			meChart->addSeries(meSeries);			
			
			axisY = new QDateTimeAxis;
			axisXval = new QValueAxis;
			axisXval->setMin(0);
			axisY->setFormat("dd-MM-yyyy h:mm:ss");			
			
			meChart->setAxisX(axisXval, meSeries);
			meChart->setAxisY(axisY, meSeries);
			*/
		}
		else if (paTypeX.compare(QString("timestamp")) == 0 && paTypeY.compare(QString("timestamp")) != 0)
		{
			cout << "Chart 3" << endl;
			for (int i=0; i < paValuesX.size(); i++)
			{
				cout << paValuesX.at(i).toStdString() << " " << paValuesY.at(i).toStdString() << endl;
				cout << QString::number((QDateTime::fromString(paValuesX.at(i),"yyyy-MM-dd HH:mm:ss")).toMSecsSinceEpoch()).toStdString() << endl;
				meSeries[i]->append((QDateTime::fromString(paValuesX.at(i),"yyyy-MM-dd HH:mm:ss")).toMSecsSinceEpoch(),(qreal)(paValuesY.at(i).toDouble()));	
			}
			/*
			meChart->addSeries(meSeries);
			
			axisX = new QDateTimeAxis;
			axisX->setFormat("dd-MM-yyyy h:mm:ss");
			
			axisYval = new QValueAxis;
			axisYval->setMin(0);				
			
			meChart->addAxis(axisX, Qt::AlignBottom);
			meChart->addAxis(axisYval, Qt::AlignLeft);							
			meSeries->attachAxis(axisX);
			meSeries->attachAxis(axisYval);			
			*/
			
		}
		else if (paTypeX.compare(QString("timestamp")) != 0 && paTypeY.compare(QString("timestamp")) != 0)
		{
			cout << "Chart 4" << endl;
			for (int i=0; i < paValuesX.size(); i++)
			{
				meSeries[i]->append((qreal)(paValuesX.at(i).toDouble()),(qreal)(paValuesY.at(i).toDouble()));	
			}			
			/*
			meChart->addSeries(meSeries);
			
			axisXval = new QValueAxis;
			axisXval->setMin(0);
			
			axisYval = new QValueAxis;
			axisYval->setMin(0);
			
			meChart->setAxisX(axisXval, meSeries);
			meChart->setAxisY(axisYval, meSeries);							
			*/
		}
		
		//We moeten de vector copieren naar een vaste variabele
		/*
		vector <clWorkstationStatus> &loWorkstationStatus  = *meWorkstationStatus;



		meChart->setTitle((QString)((clWorkstationStatus)loWorkstationStatus[0]).getWorkstationName());
		
		for (int i=0; i < loWorkstationStatus.size(); i++)
		{
			meIceClientLogging->insertItem("1","2UVLogServer.exe","clWorkstationGraphWidget::setTimingsInGraph ->" + QString("loWorkstationStatus[i]).getTimeStamp() [") + QString::number(((QDateTime)((clWorkstationStatus)loWorkstationStatus[i]).getTimeStamp()).toMSecsSinceEpoch()) + QString("] with value [" + QString::number(((qreal)((clWorkstationStatus)loWorkstationStatus[i]).getPercentageCpuUsage().toLong())) + QString("]")));
			meSeries->append(((QDateTime)((clWorkstationStatus)loWorkstationStatus[i]).getTimeStamp()).toMSecsSinceEpoch(),((qreal)((clWorkstationStatus)loWorkstationStatus[i]).getPercentageCpuUsage().toDouble()));	
		}
		meChart->removeAllSeries();
		meChart->addSeries(meSeries);
		
		QDateTimeAxis *axisX = new QDateTimeAxis;
		axisX->setFormat("dd-MM-yyyy h:mm:ss");
		
		QValueAxis *axisY = new QValueAxis;
		axisY->setMin(0);
		
		
		meChart->setAxisX(axisX, meSeries);
		meChart->setAxisY(axisY, meSeries);
	
		
		*/

		/*
		this->setRenderHint(QPainter::Antialiasing);
		*/
		return true;
	}
    catch(exception &e)
    {
		meIceClientLogging->insertItem("10",QString(QHostInfo::localHostName()),"2UVServerTest.exe","clGraphView::addGraphLine() -> " + QString(e.what()));
		return false;
    }
}
