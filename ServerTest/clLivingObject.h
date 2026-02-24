#ifndef LIVINGOBJECT_H
#define LIVINGOBJECT_H

#include <exception>
#include <string>
#include <iostream>

#include <QtCore/QThread>
#include <QtCore/QString>
#include <QtCore/QDateTime>
#include <QtNetwork/QHostInfo>


#include "clIceClientLogging.h"
#include "clIceClientServer.h"
#include "clLivingObjectMach.h"

//! [0]
class clLivingObject
{

public:
    clLivingObject(clIceClientServer * paIceClientServer, clIceClientLogging *paIceClientLogging);
    ~clLivingObject();



private:
	bool getLivingObjectsForThisWorkstation();

	clIceClientLogging * meIceClientLogging;
	clIceClientServer * meIceClientServer;
	clLivingObjectMach * meLivingObjectMach[200];
	QThread * meThread[200];
};
//! [0]

#endif
