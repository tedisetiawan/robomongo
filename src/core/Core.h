#ifndef CORE_H
#define CORE_H

#include <QSharedPointer>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include "Wrapper.h"

namespace mongo
{
    class DBClientConnection;
}

/*
** Smart pointers for Mongo* staff
*/
namespace Robomongo
{
    class AppRegistry;
    typedef boost::scoped_ptr<AppRegistry> AppRegistry_ScopedPtr;

    class SettingsManager;
    typedef boost::scoped_ptr<SettingsManager> SettingsManager_ScopedPtr;

    class MongoManager;
    typedef boost::scoped_ptr<MongoManager> MongoManagerScopedPtr;

    class MongoServer;
    typedef boost::shared_ptr<MongoServer> MongoServerPtr;

    class MongoDatabase;
    typedef boost::shared_ptr<MongoDatabase> MongoDatabasePtr;

    class MongoCollection;
    typedef boost::shared_ptr<MongoCollection> MongoCollectionPtr;

    class ConnectionRecord;
    typedef boost::ptr_vector<ConnectionRecord> ConnectionRecord_PtrVector;
    typedef QSharedPointer<ConnectionRecord> ConnectionRecordPtr;

    typedef boost::scoped_ptr<mongo::DBClientConnection> DBClientConnection_ScopedPtr;

}

#define R_EVENT(EVENT_TYPE) \
    if (__event->type() == EVENT_TYPE::EventType) \
        handle(static_cast<EVENT_TYPE *>(__event));

#define R_HANDLE(EVENT) \
    QEvent *__event = static_cast<QEvent *>((EVENT)); \
    if (false) ;

#define R_MESSAGE \
    public: \
    const static QEvent::Type EventType; \
    private:


#endif // CORE_H
