#include "LogAnalyzer.h"
#include <fstream>
#include <iostream>
using namespace std;

int main(){
    LogAnalyzer analyzer;
    analyzer.readlogfile("./logs/auth.log");
    analyzer.showFailedIPs();
    analyzer.detectsuspiciousIPs();
    return 0;
}