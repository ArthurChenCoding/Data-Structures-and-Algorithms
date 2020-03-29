#include<iostream>
#include<random>
#include"BinarySearchTree.h"
//Q2.1 printTree is inorder traversal
/*Q2.3 when preorder with no parameter is called in q2.cpp, it refers to BinarySearchTree.h.
  In that header file, the function of preoder with no parameter first checks if the tree is
  empty. If not, call the preorder function with two parameters, which visits and prints out 
  every node in perorder order.
*/
/*Q2.5 For any AVL tree, the maximum difference between max and min depth is one. 
       The difference between max and min depth significantly increases after we 
	   randomly insert 100000 nodes
*/
/*Q3 
  space complexity: Since my function is using recursive method, which adds 
					a new stack frame whenever leaving current invocation, the
					number of stack frame is equal to the number of levels the
					tree has. Therefore, the space complexity is S(log N)
  time complexity:  Since the height function is O(N) and it is called in every
                    iteration of diameter function, which is O(N) without height
				    function, the time complexity as a whole will be the product
				    of two, which is O(n^2)
*/
/*Q5 
  space complexity: Since my function is using queue method, and every node is 
					"deququed" right after check of common node, it does not require
					additional stack frame to preform the next iteration of the while
					loop. Therefore, the space required is a constant and does not 
					increases as the size of the tree increases, so S(1).
  time complexity:  Since every node is visited and added to the queue one by one, 
					the time complexity is O(N).
*/
int main(){
    BinarySearchTree<int> Tree;

    Tree.insert (5);
    Tree.insert (3);
    Tree.insert (1);
    Tree.insert (4);

    Tree.remove(3);
    Tree.remove_left(3);

    Tree.insert (6);
    Tree.insert (7);
    Tree.insert (9);
    Tree.insert (8);
    
    std::cout << "In-order:" << std::endl; 
    Tree.printTree();

    std::cout << "Pre-order:" << std::endl; 
    Tree.preorder();

    std::cout << "Level-order:" << std::endl; 
    Tree.levelorder();
	cout<<endl;
    std::cout << "max depth:" << Tree.max_depth() << std::endl; 
    std::cout << "min depth:" << Tree.min_depth() << std::endl; 
    std::cout << "diameter:" << Tree.diameter() << std::endl;
	std::cout << "LCA of 5 and 4 is ";
    Tree.LCA(5, 4);
	std::cout<<std::endl;
    BinarySearchTree<int> Tree1;

    int range = 1e5;
    std::random_device random_device;
    std::mt19937 random_engine(random_device());
    std::uniform_int_distribution<int> distribution(1, range);

    for(int i=0 ; i < range; i++)
    {
        auto const r = distribution(random_engine);
        Tree1.insert (r);
    }

    for(int i=0 ; i < range; i+=5 )
    {
        auto const r = distribution(random_engine);
        Tree1.remove(r);
        Tree1.remove(r);
    }
    std::cout << "Tree1 max= " << Tree1.max_depth() ;
    std::cout << " min= " << Tree1.min_depth();
    std::cout << " diff= " << Tree1.max_depth() - Tree1.min_depth() 
        << std::endl;


    BinarySearchTree<int> Tree2;
    for(int i=0 ; i < range; i++)
    {
        auto const r = distribution(random_engine);
        Tree2.insert (r);
    }
    for(int i=0 ; i < range; i+=5 )
    {
        auto const r = distribution(random_engine);
        Tree1.remove(r);
        Tree1.remove_left(r);
    }



    std::cout << "Tree2 max= " << Tree2.max_depth() ;
    std::cout << " min= " << Tree2.min_depth();
    std::cout << " diff= " << Tree2.max_depth() - Tree2.min_depth() 
        << std::endl;

}
