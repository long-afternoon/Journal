#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include "journalAnalyses.h"
#include <cmath>
//"day?Tuesday,month?Feburary,time?20,year?2026"

std::string getJson(std::string fn) {
    std::fstream MyFile(fn, std::ios::in | std::ios::out);
    std::stringstream buffer;
    buffer << MyFile.rdbuf();  //this grabs the whole json and copies it
    std::string allEntries = buffer.str();
 
    return allEntries;
}


int findQuestionMark() {
    return 0;
}

// int findAllOccurance(std::string fn, std::string timeStamp, std::string target) {
//     std::string jsonFile = getJson(fn);
//     if(timeStamp == "day") {

//         std::string day = target[0] + target[1]; //[0] capitilize!!

//         std::string jsonDay = jsonFile[i+0] + jsonFile[i+1] + jsonFile[i+2];

//         while(day != )
//     }



// }

bool trackLogs(std::string fn) {
    return false;
}

void findByDay(std::string fn) {


    



}

void findByMon(int mon) {

}

void findByYear(int year) {

}

void findByTime(int time) {

}


int getSrNo(std::string fn) {
    std::string file = getJson(fn);
    int sr = file.length();
    int count = 0;
    for(int i = 0; i <= sr; i++) {
        if('{' == file[i]) count++;
    }
    return count;
}



