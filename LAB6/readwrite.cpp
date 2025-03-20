#include <iostream>
#include "file.h"

using namespace std;

int main() {
    if(copyFileContent("input.txt", "output.txt")) {
        cout<< "File content successfully copied." <<endl;
    } else {
        cout<< "File copy failed." <<endl;
        return 1;
    }
    return 0;
}
