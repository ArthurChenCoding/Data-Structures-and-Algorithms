#include <fstream>
#include <cctype>
#include <set>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b){
	int c;
	if(a<=b){c=a;}
	else{c=b;}
	return c;
}

int main() {
	vector<int> v1{ 10, 20, 30, 40, 50 };
    vector<int> v2{ 100, 200, 300, 400 };

    //appending elements of vector v2 to vector v1
    v1.insert(v1.end(), v2.begin(), v2.end());
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << endl;
	}

}