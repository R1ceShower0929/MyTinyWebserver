#include"server/webserver.h"
#include <unistd.h>
#include<iostream>
using namespace std;

int main(){
    /**
    int port, int trigMode, int timeoutMS,
    int sqlPort, const char* sqlUser, const  char* sqlPwd, const char* dbName, 
    int connPoolNum, int threadNum,
    bool openLog, int logLevel, int logQueSize);
    */
    WebServer server(
        10000,3,60000,
        3306,"root","123456","mydb",
        12,6,
        true,1,1024
    );
    server.Start();
}