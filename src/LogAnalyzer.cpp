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
                cout << "status: "<< match[1]<<endl;
                cout << "IP: "<< match[2]<<endl;
                cout << "-----------------------------" << endl;
            }
        }
    }
    else{
        cout << "[ERROR] file failed to open" << filename << endl;
    }
}