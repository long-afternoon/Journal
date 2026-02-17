#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include "journalAnalyses.h"



bool trackLogs(std::string fn) {
    return false;
}

void findByDay(std::string fn) {
    std::fstream MyFile(fn, std::ios::in | std::ios::out);
    std::stringstream buffer;
    buffer << MyFile.rdbuf();  //this grabs the whole json and copies it
    std::string allEntries = buffer.str();

    std::cout << allEntries << std::endl;

}

void findByMon(int mon) {

}

void findByYear(int year) {

}

void findByTime(int time) {

}






