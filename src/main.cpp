#include <iostream>

#include "headers.h"


#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>


void getListenKey() {
    while (true) {
        BinanceAPIService *binanceApiService = new BinanceAPIService();
        string listenKey = binanceApiService->getListenKey();
        RedisService *redisService = new RedisService();
        redisService->set("LISTEN_KEY", listenKey);
        delete redisService;
        delete binanceApiService;
        this_thread::sleep_for(chrono::minutes(30));
    }
}

void start() {
    BinanceStreamService *streamService = new BinanceStreamService(DataUtils::USER_DATA_STREAM_URL, "443",
                                                                   "/ws/!markPrice@arr@1s", 1);
    streamService->start();
}

void mysqlExam() {
    cout << endl;
    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;
        /* Create a connection */
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
        /* Connect to the MySQL test database */
        con->setSchema("test");
        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT 'Hello World!' AS _message");
        while (res->next()) {
            cout << "\t... MySQL replies: ";
            /* Access column data by alias or column name */
            cout << res->getString("_message") << endl;
            cout << "\t... MySQL says it again: ";
            /* Access column data by numeric offset, 1 is the first column */
            cout << res->getString(1) << endl;
        }
        delete res;
        delete stmt;
        delete con;
    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line "
        << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
    cout << endl;
}

int main(int argc, char **argv) {
    thread priceServiceThread(start);
    thread getListenKeyThread(getListenKey);
    thread mysqlThread(mysqlExam);
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}