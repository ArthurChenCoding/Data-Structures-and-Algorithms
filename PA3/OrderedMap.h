#ifndef ORDERED_MAP_H
#define ORDERED_MAP_H
#include <iostream>
#include <string> 
#include <sstream>
using namespace std;       

// OrderedMap class
template <class Key, class Value>
class OrderedMap{
  public:
    /**
     * Default constructor for the map
     */
    OrderedMap():root_key{new KeyNode(-1,nullptr,nullptr)}{}
    OrderedMap(int map_size):root_key{new KeyNode(-1,nullptr,nullptr)},MAP_MAX_SIZE{map_size}{}
    /**
     * Destructor for the map
     */
    ~OrderedMap()
    {makeEmpty();}
    /**
     * Copy assignment
     */
    OrderedMap & operator=(const OrderedMap & rhs){
        OrderedMap copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
    /**
     * Move assignment
     */
    OrderedMap & operator=(OrderedMap && rhs){
        std::swap( root_key, rhs.root_key );       
        return *this;
    }
    /**
     * Insert a key value pair in the map.
     */
    void insert(const Key & key,const Value & value){ 
        int key_hash = hashFunction(key);
		//cout << "ok"<<endl;
        return insert( key_hash, key, value, root_key ); 
    }

    /**
     * Print the map content in sorted order.
     */
    void printMap( ostream & out = cout ) const{//turing private to public
        printMap( root_key, out );
    }
    /**
     * Make the tree logically empty.
     */
    void makeEmpty( )
    { makeEmpty( root_key ); }
	
  private: 
    struct ValueNode{
        Key key;
        Value value;
        ValueNode* right;

        ValueNode
            ( const Key & theKey, const Value & theValue, ValueNode *rt)
          : key{ theKey }, value{ theValue }, right{ rt } { }

        ValueNode
            ( Key && theKey, Value && theValue, ValueNode *rt)
          : key{ std::move( theKey ) }, value{ std::move( theValue ) }, right{ rt } { }
    };

    struct KeyNode{
        int hash_key;
        ValueNode* right;
        KeyNode* down;

        KeyNode
            (int hash, ValueNode *rt, KeyNode* dn)
          : hash_key{ hash }, right{ rt }, down{ dn } { }
    };

    KeyNode *root_key;
    int MAP_MAX_SIZE;

    /** Q 4.1
     *
     * Implement your own hash function that will convert the Key into an integer.
     * 
     * Note: Return value of this function should be between 0 than MAP_MAX_SIZE - 1.
     */
    int hashFunction( const Key & key ) {
		//cout << key;
        // turning anythign into string
		stringstream s;
		s << key;
		string holder = s.str();
		// then turn into index
		//cout << holder;
		int index = holder.at(0)%MAP_MAX_SIZE;
		//cout<<"index:"<<index<<endl;
        return index;
    }
    /** Q 4.2
     *
     * Implement method to insert a key, value pair in a map.
     * 
     * Note: Since this is ordered map, insert key in sorted order of hash_key.
     *       In case there is already a key node with given hash_key, insert the 
     *       value node in the end.
     */
    void insert( int hash_key, const Key & key, const Value & value, KeyNode* t ){
		while (true) {
			//non empty, found same node, insert at end
			if (hash_key == t->hash_key) {
				if (t->right != nullptr) {
					ValueNode* new_t = t->right;
					while (new_t->right != nullptr) {//move to rightest
						new_t=new_t->right;
					}
					new_t->right = new ValueNode{key,value,nullptr};
					return;
				}else {
					cout << "error" << endl;
				}
			}
			//next one is higher, right place to insert
			else if (t-> down != nullptr && hash_key < t->down->hash_key) {
				//create new keynode at down, and wire up 
				KeyNode* holder = new KeyNode{hash_key,nullptr,nullptr};
				holder->down = t->down;
				t->down = holder;
				//creare new valuenode at right
				holder->right = new ValueNode{key,value,nullptr};
				return;
			}
			else if (t-> down == nullptr) {//largest, add new at down 
				t->down = new KeyNode{hash_key,nullptr,nullptr};
				t=t->down;//move to new node
				t->right = new ValueNode{key,value,nullptr};
				return;
			}
			else {
				t=t->down;
			}
		}
		/*KeyNode* holder = t;
		for (int i = 0; i < MAP_MAX_SIZE; i++) {
			holder->down = new KeyNode{i,nullptr,nullptr};
			holder=holder->down;
		}
		KeyNode* t2 = t;
		t2=t2->down;
        for (int i = 0; i < MAP_MAX_SIZE; i++) {
			cout << "t2->hash_key: " << t2->hash_key << endl;
			cout << "hash_key: " << hash_key << endl;
			if (t2->hash_key == hash_key) {//found row
				
				if (t2->right == nullptr) {//if empty list
				
					t2->right = new ValueNode{key,value,nullptr};
				}/*else {//add to the end of the list
				cout<<"gay2";
					ValueNode* new_t = t->right;
					while (new_t->right != nullptr) {//move to rightest
					new_t=new_t->right;
					}
					//now right is null, append to the right
					//initialize new ValueNode with key and value
					new_t->right = new ValueNode{key,value,nullptr};
				}
				return;//end the function after insert
			}
			t2=t2->down;//move down
		}
		return;*/
    }

    /**
     * Internal method to make a map empty.
     */
    void makeEmpty( KeyNode * & t )
    {
        if( t != nullptr )
        {
            makeEmpty_row( t->right );
            makeEmpty( t->down );
            delete t;
        }
        t = nullptr;
    }

    void makeEmpty_row( ValueNode * & v )
    {
        if( v != nullptr )
        {
            makeEmpty_row( v->right );
            delete v;
        }
        v = nullptr;
    }

    /**
     * Internal method to print the map.
     */
    void printMap( KeyNode *t, ostream & out ) const
    {
        if( t != nullptr )
        {
            out << t->hash_key << "\t->";
            if(t->hash_key == -1) {
                out << " Root KeyNode of Map";
            } else {
                printMap_row( t->right, out );
            }
            out << endl;
            printMap( t->down, out );
        }
    }

    void printMap_row( ValueNode *v, ostream & out ) const
    {
        if( v != nullptr )
        {
            out << " ( " <<v->key << " , " << v->value << " ) ";
            printMap_row( v->right, out );
        }
    }
};

#endif
