#ifndef LOG_ANALYZER_H
#define LOG_ANALYZER_H

#include <string>
#include <unordered_map>
using namespace std;

class LogAnalyzer{
public:
    void readlogfile(const string& filename);
    void showFailedIPs();
    void detectsuspiciousIPs();
private:
    unordered_map<string, int> failedIps;
};


#endif 