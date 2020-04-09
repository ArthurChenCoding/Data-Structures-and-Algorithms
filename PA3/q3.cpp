#include<iostream>
#include<vector>
#include<cmath>
#include<ctime>
using namespace std;

int insertLinear(int x, vector<int> & linear);
int insertQuad(int x, vector<int> & quad);
int insertDuble(int x, int dubHash, vector<int> & duble);

int main() {
  int linCollides=0;
  int quadCollides= 0;
  int dubCollides = 0;
  int quadInc;
  int tableSize;
  bool fail = false;
  int x, count=0;
  int doubleHash;

  srand(time(NULL));
  cout<<"enter the size of the table ";
  cin>>tableSize;
  vector<int> linear(tableSize,-1);//initalize each table to -1 for empty
  vector<int> quad(tableSize,-1);  //initalize each table to -1 for empty
  vector<int> duble(tableSize,-1);  //initalize each table to -1 for empty
  do{
   doubleHash = rand()%tableSize;//a random num smaller than size
  }while (doubleHash < tableSize/10 && doubleHash%tableSize==0);

  while(count < tableSize && !fail){
    x= rand()%tableSize;// value to insert
	quadInc=insertQuad(x,quad);
	if (quadInc < 0)
		fail = true;
	else
	{
	 quadCollides += quadInc;
	 linCollides+=insertLinear(x,linear);
	 dubCollides+=insertDuble(x,doubleHash, duble);
	}
	count++;
  }
  cout<<"Num linear collides "<<linCollides<<endl;
  cout<<"Num quadratic collides "<<quadCollides<<endl;
  cout<<"Num double hash collides "<<dubCollides<<endl;
  return 0;
}

int insertLinear(int x, vector<int> & linear) {
	int size = linear.size();
	int bucket=x%size;
	int collision = 0;
    while (collision < size) {
		// Insert item in next empty bucket 
		if (linear[bucket] == -1) {
			linear[bucket] = x;
			return collision;//return number of collision
		}

		// Increment bucket index
		bucket = (bucket + 1) % size;

		// Increment number of buckets probed
		++collision;
	}
	return -1;
}

int insertQuad(int x, vector<int> & quad){
	int i = 0;
	int collision = 0;
	int size = quad.size();
	int bucket=x%size;
	int c1 = 3;
	int c2 = 5;
	while (collision < size) {
		// Insert item in next empty bucket 
		if (quad[bucket] == -1) {
			quad[bucket] = x;
			return collision;  
		}

		// Increment i and recompute bucket index
		// c1 and c2 are programmer-defined constants for quadratic probing
		
		i++;
		bucket = (x%size + c1 * i + c2 * i * i) % size;

		// Increment number of buckets probed
		collision++;
	}
	return 0;
}

int insertDuble(int x, int dubHash, vector<int> & duble){
	int i = 0;
	int collision = 0;
	int size = duble.size();
	int bucket=x%size;
	int c1 = 1;
	int c2 = 2;
	while (collision < size) {
		// Insert item in next empty bucket 
		if (duble[bucket] == -1) {
			duble[bucket] = x;
			return collision;  
		}

		// Increment i and recompute bucket index
		// c1 and c2 are programmer-defined constants for quadratic probing
		
		i++;
		bucket = (x%c1 + (c2-x%c2)) % size;

		// Increment number of buckets probed
		collision++;
	}
	return 0;
}
