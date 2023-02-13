#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
map<char, int> skip_dictionary;

void skipalphabet(string skip) {
    for(char element : skip) {
        skip_dictionary[element] = 0;
    }
}

bool isExistDictionary(char c) {
    bool isFind = false;
    if(skip_dictionary.find(c) != skip_dictionary.end()) {
        isFind = true;
    }
    return isFind;
}

bool isExceed(char c) {
    if((c >= 'a') && (c <= 'z')) return false;
    else return true;
}

string solution(string s, string skip, int index) {
    skipalphabet(skip);
    for(char& c : s) {
        int copyIndex = index;
        while(copyIndex--) {
            c += 1;
            if(isExceed(c)) {
                c = 'a'; 
            }

            if(isExistDictionary(c)) {
                copyIndex += 1;
            }
        }
    }
    return s;
}
