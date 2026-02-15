#include <filesystem>
#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include <chrono>
#include <fstream>

using namespace std;

struct times {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int hour12 = ltm->tm_hour % 12;
    int hour2 = ltm->tm_hour;

    int min = ltm->tm_min;
    int sec = ltm->tm_sec;
    
    int year = ltm->tm_year + 1900;
    int month = ltm->tm_mon + 1;
    int day = ltm->tm_mday;
    int day7 = ltm->tm_wday;
};


string getHint() {

    string hints[6] = {
    "Write whatever's on your mind...",
    "Tell me how you're feeling right now",
    "Write a letter to the stars tonight",
    "Tell the stars what today felt like",
    "Leave a message for the night",
    "Before sleep, write a little"
    };


    int size = sizeof(hints) / sizeof(hints[0]);
    int randHint = rand() % size;

    return hints[randHint];
}
bool exists(const string& path) {
    return std::filesystem::exists(path);

    return false;
}

string joinJsonEntry(string pastData, string newData) {
    int pastSize = pastData.length();
    int newSize = newData.length();

    

    pastData[pastSize - 1] = ' ';
    newData[0] = ' ';
    string newD = pastData + ',' + newData;
    return newD;


}

void feelingBox(string fname, string thoughts) {

    times tm;
    string entry =
    "[{\n"
    "  \"date\": \"" + to_string(tm.year) + "-" + to_string(tm.month) + "-" + to_string(tm.day) + "\",\n"
    "  \"time\": \"" + to_string(tm.hour12) + ":" + to_string(tm.min) + ":" + to_string(tm.sec) + "\",\n"
    "  \"thought\": \"" + thoughts + "\"\n"
    "}]";

    if(!exists(fname)) {
        fstream MyFile(fname, ios::in | ios::out | ios::trunc); //with trunc creates new file , and clears it
        MyFile << entry;
    } else {
        fstream MyFile(fname, ios::in | ios::out );

        stringstream buffer;
        buffer << MyFile.rdbuf();  //this grabs the whole json and copies it
        string oldEntries = buffer.str();

        fstream newFile(fname, ios::in | ios::out | ios::trunc);



        newFile << joinJsonEntry(oldEntries, entry);
        
        // string newData;
        // getline(MyFile, newData);


    }
}

void showTime() {
    times tm;
    string day, mon;
    switch(tm.day7) {
        case 0:
            day = "Sunday"; break;
        case 1:
            day = "Monday"; break;
        case 2:
            day = "Tuesday"; break;
        case 3:
            day = "Wednesday"; break;
        case 4:
            day = "Thursday"; break;
        case 5:
            day = "Friday"; break;
        case 6:
            day = "Saturday"; break;
    }
    switch(tm.month) {
        case 1:
            mon = "January"; break;
        case 2:
            mon = "Feburary"; break;
        case 3:
            mon = "March"; break;
        case 4:
            mon = "April"; break;
        case 5:
            mon = "May"; break;
        case 6:
            mon = "June"; break;
        case 7:
            mon = "July"; break;
        case 8:
            mon = "Auguest"; break;
        case 9:
            mon = "September"; break;
        case 10:
            mon = "October"; break;
        case 11:
            mon = "November"; break;
        case 12:
            mon = "December"; break;
    }

    cout << tm.hour12 << ":" << tm.min << " " << day << ", " << mon << " " << tm.day << endl;
}

int main() {

    srand(time(0));
    system("cls");
    showTime();

    string ftype = ".json";
    string fname;
    string userThought;

    cout << "filename:";
    cin >> fname;
    cin.get();  //getline has some weird issues T_T 


    while(true) {

        cout << getHint() << endl << ":";
        getline(cin, userThought);
        
        string file_name = "files\\" + fname + ftype;
        feelingBox( file_name, userThought);
    }
    return 0;
}