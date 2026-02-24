#include "clQuery.h"

clQuery::clQuery(QString paClass, QString paProperty, QString paType)
{
    setClass(paClass);
    setProperty(paProperty);
    setType(paType);
}

clQuery::~clQuery()
{

}

//Setters
void clQuery::setClass(QString paClass){ meClass= paClass;}
void clQuery::setProperty(QString paProperty){ meProperty = paProperty;}
void clQuery::setType(QString paType){meType = paType;}

//Getters
QString clQuery::getClass(){return meClass;}
QString clQuery::getProperty(){return meProperty;}
QString clQuery::getType(){return meType;}
