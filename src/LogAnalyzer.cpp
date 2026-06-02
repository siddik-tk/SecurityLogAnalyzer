#include "LogAnalyzer.h"
#include <fstream>
#include <iostream>
using namespace std;

void LogAnalyzer::readlogfile(const string& filename){

    ifstream logfile(filename);
    if (logfile.is_open()){
        string line;
        while(getline(logfile,line)){
            cout << line << endl;
        }
    }
    else{
        cout << "[ERROR] file failed to open" << filename << endl;
    }
}