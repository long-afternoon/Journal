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
//         int i;
//         std::string jsonDay = jsonFile[i] + jsonFile[i+1] + jsonFile[i+2];

        
//     }



// }

bool trackLogs(std::string fn) {
    return false;
}

std::string getThought(std::string fn, int currentPos) {
    std::string file = getJson(fn);
    int sr = file.length();
    for(int i = currentPos; i < sr; i++) {
        if('u' == file[i] && 'g' == file[i+1] && 'h' == file[i+2] && 't' == file[i+3] && '"' == file[i+4] && ':' == file[i+5]) {
            
            std::string thought = "";
            int j = i + 7;
            
            while(file[j] != '?' && file[j+1] != '"') {
                thought += file[j + 1];
                j++;
            }
            thought[thought.length() - 1] = ' ';
            return thought;
        }
        // return "NULL1"; 

    } 
    return "NULL"; 
}

void findByDay(std::string fn, std::string target) {
    std::string file = getJson(fn);
    int sr = file.length();
    for(int i = 0; i <= sr; i++) {
        if(file[i] == 'd' && file[i+1] == 'a' && file[i+2] == 'y' && file[i+3] == '?') {
            // std::cout << "DAY:" << file[i+4] + file[i+5] + file[i+6] << std::endl;

            std::string hm1(1, file[i+4]);
            std::string hm2(1, file[i+5]);
            std::string hm3(1, file[i+6]);

            std::string theDay = hm1+hm2+hm3; //Mon, Tue, Wed...

            // int thoughtIdx = 0;
    
            // getThoughtIdx(i);

            std::string thoughtOfThtDay;
            if(theDay == target) {
                thoughtOfThtDay = getThought(fn, i);
            }
            
            std::cout << "DAY:" <<  thoughtOfThtDay << std::endl;
        }
    }
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



