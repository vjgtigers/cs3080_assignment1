#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
    std::cout << "Hello, World!" << std::endl;
    if (argc < 5) {
        cout << "To small" << endl;
    }
    string filename = argv[1];
    const char* amount = argv[2];
    const char* range = argv[3];
    const char* seed = argv[4];
    int numItems = atoi(amount);
    int numRange = atoi(range);
    int numSeed = atoi(seed);

    ofstream dataFile(filename);

    if(dataFile.is_open() != true) {
        cout << "file open failure" << endl;
        return 0;
    }

    srand(numSeed);

    for(int i = 0; i < numItems; ++i) {
        dataFile << rand()%numRange << endl;
    }
    dataFile.close();

    string output;
    int itemRowCounter = 1;
    ifstream numberFile(filename);
    while (getline (numberFile, output)) {

        cout << output << "\t";
        if(itemRowCounter < 5) {
            itemRowCounter += 1;
        }
        else {
            itemRowCounter = 1;
            cout << endl;
        }

    }

    numberFile.close();
    
    return 0;
}
