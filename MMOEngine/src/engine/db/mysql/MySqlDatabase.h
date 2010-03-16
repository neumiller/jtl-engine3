/*
Copyright (C) 2007 <SWGEmu>. All rights reserved.
Distribution of this file for usage outside of Core3 is prohibited.
*/

#ifndef MYSQLDATABASE_H_
#define MYSQLDATABASE_H_

#include "system/lang.h"

#ifdef PLATFORM_MAC
#include "mysql5/mysql/mysql.h"
#else
#include <mysql.h>
#endif

#include "../../log/Logger.h"

#include "../Database.h"
#include "Statement.h"
#include "ResultSet.h"

namespace engine {
  namespace db {
    namespace mysql {

    class MySqlDatabase : public Database, public Mutex,  public Logger {
		MYSQL mysql;
		String host;

		uint32 queryTimeout;

	public:
		MySqlDatabase(const String& s);
		MySqlDatabase(const String& s, const String& host);

		virtual ~MySqlDatabase();

		void connect(const String& dbname, const String& user, const String& passw, int port);

		void executeStatement(const char* statement);
		void executeStatement(const String& statement);
		void executeStatement(const StringBuffer& statement);

		engine::db::ResultSet* executeQuery(const char* statement);
		engine::db::ResultSet* executeQuery(const String& statement);
		engine::db::ResultSet* executeQuery(const StringBuffer& statement);

		void commit();

		void autocommit(bool doCommit);

		void close();

	    void error();
	    void error(const char* query);

		static void finalizeLibrary();

	};

    } // namespace mysql
  } // namespace db
} // namespace engine

#endif /*MYSQLDATABASE_H_*/