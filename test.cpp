#include <iostream>
#include <string>

using namespace std;

string joinJsonEntry(string pastData, string newData) {
    int pastSize = pastData.length();
    int newSize = newData.length();

    

    pastData[pastSize - 1] = ' ';
    newData[0] = ' ';

    return pastData + "," + newData;


}



int main() {
    
    string entry =
    "[\n{\n"
    "  \"date\": \"" + to_string(12) + "-" + to_string(43) + "-" + to_string(87) + "\",\n"
    "  \"time\": \"" + to_string(12) + ":" + to_string(45) + ":" + to_string(86) + "\",\n"
    "  \"thought\": \"" + "thoughs" + "\"\n"
    "}\n]";


    string entry1 =
    "[\n{\n"
    "  \"date\": \"" + to_string(132) + "-" + to_string(423) + "-" + to_string(487) + "\",\n"
    "  \"time\": \"" + to_string(112) + ":" + to_string(454) + ":" + to_string(826) + "\",\n"
    "  \"thought\": \"" + "thoughts232" + "\"\n"
    "}\n]";
     
    string entry3 = joinJsonEntry(entry, entry1);


    cout << joinJsonEntry(entry1, entry3) << endl;
    return 0;
}