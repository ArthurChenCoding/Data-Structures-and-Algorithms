#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string line, filename;
    map <string,int> coronamap;

    ifstream in;
    cout<<"enter the file name: ";
    cin>>filename;

    in.open(filename.c_str());
    getline(in,line);

    string partOf;
	string name;
	int num;
    while (in){
		int i = 0;
		while (isalpha(line[i])) {
			i++;
		}
		name = line.substr(0,i);
		num = stoi(line.substr(i+1));
		//cout << name <<":"<< num << endl;
		coronamap.insert({name,num});
		getline(in,line);//next line 
    }
	int max = -1;
    for (auto j : coronamap ){
		if(j.second>max)
			max = j.second;
	} 
	for (auto k : coronamap ){
		if(k.second == max) {
			cout << "Most confirmed cases are in " << k.first << endl;
		}
	}
    // your implementation here to print the country with max cases
    // E.g. Most confirmed cases are in USA

    return 0;
}
