#include <fstream>
#include <cctype>
#include <set>
#include <string>
#include <iostream>
using namespace std;

int min(int a, int b){
	int c;
	if(a<=b){c=a;}
	else{c=b;}
	return c;
}
string findInLine(string line, string goal, int index) {
	int startIndex = line.find(goal, index);
	cout <<"start: " << startIndex << endl;
	if (startIndex == -1) {
		return "not found";
	}
	int endIndex = startIndex+goal.size();
	//cout <<"end: " << endIndex << endl;
	int commentIndex = line.find("//");
	//cout <<"comment: " << commentIndex << endl;
	if (commentIndex<startIndex && commentIndex!=-1) {
		return "not found";
	}
	int startReturnString = endIndex+1;
	int endReturnString = startReturnString;
	while(isalpha(line[endReturnString])) {
		endReturnString++;
	}
	//cout << "startR: " << startReturnString << endl;
	//cout << "endR: " << endReturnString << endl;
	if (endReturnString == startReturnString){
		return "not found";
	}else {
		while(isalpha(line[endReturnString])||isdigit(line[endReturnString])) {
			endReturnString++;
		}
	}
	return line.substr(startReturnString, endReturnString-startReturnString);
}

int main() {
	string Line = " today i1 <a busy day//but still playing";
	string key = "today" ;
	string i = findInLine(Line, key, 0);
	cout << i << endl;
	return 0;
}