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

	
	
int main()
{
    string line, filename, word;
    int pos=0;

    ifstream in;
    set<string> idents;
    set<string> reserved;
    string reserveArray[]= {"for", "if","else", "fstream", "set","string",
        "include", "main", "using", "namespace","std", "iostream", "string", 
        "ifstream","char","auto","size","open","while","return","int","endl"};
    
    for (int i = 0; i <22; i++)
        reserved.insert(reserved.end(),reserveArray[i]);

    cout<<"enter the file name: ";
    cin>>filename;

    in.open(filename.c_str());
    getline(in,line);

    while (in){
        for (int i= 0; i<22; ++i){
			while(word != "not found") {
				word = findInLine(line,reserveArray[i],pos);
				if (word!="not found"&&word!="main") {
					idents.insert(word);
				}
				pos = pos+3;//continue searching
			}
			//reset for new voca
			word = "reset";
			pos=0;
		}
		getline(in,line);//next line
    }
    for (auto x:idents)
        cout<<x<<endl;
    return 0;
}
