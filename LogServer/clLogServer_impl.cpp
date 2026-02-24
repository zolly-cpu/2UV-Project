#include "clLogServer_impl.h"

void clLogServer_impl::insertItem(  const std::string& paLogNumber,
									const std::string& paComputerName,
                                    const std::string& paApplicationName,
                                    const std::string& paApplicationText,
                                    const Ice::Current &paCurrent)
{
    IceUtil::Mutex::Lock loLock (meGeneralMutex);
    try
    {
       meFileWriter.writeMessageToLogFile(QString(paLogNumber.c_str()),
										  QString(paComputerName.c_str()),
                                          QString(paApplicationName.c_str()),
                                          QString(paApplicationText.c_str()));
    }
    catch(exception& e)
    {
       printf("bool clLogServer_impl::insertItem -> error ...");
	   printf(e.what());
    }
}

bool clLogServer_impl::Ping (const Ice::Current& paCurrent)
{
    try
    {
        printf("clLogServer_impl::Ping entered");
		IceUtil::Mutex::Lock loLock (meGeneralMutex);
        cout << "clLogServer_impl::Ping";
        return true;
    }
    catch(exception& e)
    {
        printf("bool clLogServer_impl::Ping -> error ...");
		printf(e.what());
    }
}

void clLogServer_impl::Shutdown(const Ice::Current& paCurrent)
{
    try
    {
        IceUtil::Mutex::Lock loLock (meGeneralMutex);
        paCurrent.adapter->getCommunicator()->shutdown ();
    }
    catch(exception& e)
    {
        printf("void clLogServer_impl::Shutdown -> error ...");
		printf(e.what());
    }
}
