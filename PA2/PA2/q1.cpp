#include<iostream>
#include<vector>

/**
 * Q 1
 * Add the code in below function that will print the 
 * child of a given parent p.
 */
void child(int p, const std::vector<int> Parent)
{
    // Remove below line after your implementation
    return;
}

void testChild(const std::vector<int> Parent){

    std::cout << "Here is the tree" << std::endl;
    for (auto p: Parent)
        std::cout << p << ' ';
    std::cout << std::endl;

    
    for(int p=0; p < Parent.size(); p++){
        std::cout << "children of node " << p << " are" << std::endl;
        child(p, Parent);
        std::cout << std::endl;
    }
 
}

int main(){

    std::vector<int> Parent = {1, 3, 1, -1, 3};
    std::cout << "first test:" << std::endl;
    testChild (Parent);
    
    std::cout << "second test:" << std::endl;
    testChild ({4, 4, 4, 4, -1});
   
}

