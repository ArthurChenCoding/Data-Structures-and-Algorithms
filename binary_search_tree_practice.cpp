template <typename Comparable>
class BinarySearchTree {
	public :
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree & rhs);
	BinarySearchTree(BinarySearchTree && rhs );
	~BinarySearchTree();
	
	const Comparable & findMin() const;
	const Comparable & findMax() const;
	book contains( const Comparable & x)const;
	bool isEmpty() const;
	void printTree(ostream & out = cout) const;
	
	void makeEmpty();
	void insert(const Comparable & x);
	void insert(const Comparable & x);
	void remove( const Comparable & x);
	
	BinarySearchTree & operator=(const BinarySearchTree & rhs);
	BinarySearchTree & operator=( BinarySearchTree && rhs);
	
	private:
}
	