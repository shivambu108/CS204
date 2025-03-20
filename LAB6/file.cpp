#include <iostream>
#include <fstream>
#include <string>
#include "file.h"
using namespace std;

bool copyFileContent(const string &inFilename, const string &outFilename) {
    ifstream inFile(inFilename);
    if(!inFile) {
        cerr << "Error: Unable to open input file: " << inFilename << endl;
        return false;
    }

    ofstream outFile(outFilename);
    if(!outFile) {
        cerr << "Error: Unable to open output file: " << outFilename << endl;
        inFile.close();
        return false;
    }

    string line;
    while(getline(inFile, line)) {
        outFile << line << endl;
    }

    inFile.close(); outFile.close();
    return true;
}
