#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../Header Files/MySet.h"

using namespace std;

string getPhoneNumber(const string& line) {
    stringstream ss(line);
   string field;

    int col = 0;
    while (getline(ss, field, ',')) {
        if (col == 1) {
            return field;
        }
        col++;

    }
    return "";

}

int main() {
    ifstream inputFile("data/rep1.csv");
    ofstream outputFile("data/unique_leads.csv");

    MySet<string> phoneSet;
    string line;
    while (getline(inputFile, line)) {
        string phoneNumber = getPhoneNumber(line);
        if (phoneSet.search(phoneNumber)<0){
            phoneSet.push(phoneNumber);
            outputFile << line << "\n";;

        }
    }
    inputFile.close();
    outputFile.close();
    return 0;
}