#include "LogAnalyzer.h"
#include <fstream>
#include <iostream>
using namespace std;

int main(){
    LogAnalyzer analyzer;
    analyzer.readlogfile("./logs/auth.log");
    return 0;
}