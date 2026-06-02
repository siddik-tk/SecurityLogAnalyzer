#include "LogAnalyzer.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <regex>
using namespace std;

void LogAnalyzer::readlogfile(const string& filename){

    ifstream logfile(filename);
    if (logfile.is_open()){
        string line;
        regex pattern(R"((Failed|Success).*?(\d+.\d+.\d+.\d+))");
        while(getline(logfile,line)){
            smatch match;
            if(regex_search(line, match, pattern)){
                cout << "[INFO] " << match[1] << " login attempt from IP: " << match[2] << endl;
            }
        }
    }
    else{
        cout << "[ERROR] file failed to open" << filename << endl;
    }
}