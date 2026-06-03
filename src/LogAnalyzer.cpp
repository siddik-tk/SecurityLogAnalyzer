#include "LogAnalyzer.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <regex>
using namespace std;

const int THRESHOLD = 3;

void LogAnalyzer::readlogfile(const string& filename){

    ifstream logfile(filename);
    if (logfile.is_open()){
        string line;
        regex pattern(R"((Failed|Success).*?(\d+.\d+.\d+.\d+))");
        while(getline(logfile,line)){
            smatch match;
            if(regex_search(line, match, pattern)){
                if(match[1] == "Failed"){
                    LogAnalyzer::failedIps[match[2]]++;
                }
            }
        }
    }
    else{
        cout << "[ERROR] file failed to open" << filename << endl;
    }
}

void LogAnalyzer::showFailedIPs(){
    cout << "Failed IPs" << endl;
    for(auto& ippair : LogAnalyzer::failedIps){
        cout << ippair.first << "->" << ippair.second << endl;
    }
}

void LogAnalyzer::detectsuspiciousIPs(){
    cout << "\n\nSuspicious IPs" << endl;
    for(auto& ippair : failedIps){
        if(ippair.second >= THRESHOLD){
            cout << "[suspicious] "<<endl;
            cout << ippair.first << "   ->   " << ippair.second << "attempt(s)" << endl;
            
        }
    }
}