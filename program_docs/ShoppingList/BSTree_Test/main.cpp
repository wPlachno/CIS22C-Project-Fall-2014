
/**
 
 Test BSTree
 
 Assumptions:
  - If you can delete it, insert worked.
  - If you can find/delete it, previous deletes worked.
  - If inorder traversal gives a sorted tree, both the traversal and insert worked
  
 Notes:
 - Breadth first traversal has to be manually checked.
 - RemoveAll can be tested like destroyAll... in a real application we would assume that all the data would still be held elsewhere (this would be a good place to use shared_ptr)
 
 
 Author: Robert Hoyer
 */


#include "BSTree.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

/** Class that is compatible with BSTree for testing.
 */
class TestData
{
    int data;
public:
    TestData(int data = 0):
    data(data)
    {}
       
    int getKey()
    {
        return data;
    }

    int compareKey(int k)
    {
        if (data > k)
            return 1;
        else if (data < k)
            return -1;
        else
            return 0;
    }
};


/** Function for traversals.
 */

void print_testdata(TestData& td)
{
    std::cout << td.getKey() << std::endl;

}


/** Test removal
 */

void test_remove(BSTree<TestData, int>& tree, int val)
{
    TestData* removed = tree.remove(val);
    std::cout << "remove: ";
    if(removed)
    {
        std::cout << removed->getKey() << std::endl;
        delete removed;
    }
    else
    {
        std::cout << val << " - FAIL" << std::endl;
    }
    
}

/** Test insert
 */

void test_insert(BSTree<TestData, int>& tree, int val)
{
    std::cout << "insert: " << val;
    if(tree.insert(new TestData(val)))
        std::cout << std::endl;
    else
        std::cout << " - FAIL" << std::endl;
}


/** Test get
 */

void test_get(BSTree<TestData, int>& tree, int val)
{
    TestData* found;
    found = tree.get(val);
    
    std::cout << "get: " << val;
    if(found )
        std::cout << " - SUCCESS" << std::endl;
    else
        std::cout << "- FAIL" << std::endl;
    
}

/** Test print methods.
 */

void test_print(BSTree<TestData, int>& tree)
{
    std::cout << "<<<Tree Contents: PREORDER>>>" << std::endl;
    tree.inorderTraversal(print_testdata);
    std::cout << "<<<Tree Contents:>>>" << std::endl;
    tree.printTree();
    std::cout << "<<<------------------------>>>" << std::endl;
}


/** Test isEmpty
 */

void test_empty(BSTree<TestData, int>& tree)
{
    if(tree.isEmpty())
        std::cout << "The tree is empty." << std::endl;
}


/** Simple test of BSTree functionality.
 */

void test_bstree()
{

    BSTree<TestData, int> testTree;
    
    int testData1[] = { 50, 100, 75, 25, 0, 65, 57, 12, 99};
    
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<BEGIN TEST>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    
    test_empty(testTree);

    
    for(int i = 0; i < sizeof(testData1)/sizeof(int); i++)
    {
        test_insert(testTree, testData1[i]);
    }


    test_print(testTree);
    
    test_remove(testTree, 50);

    //first should fail
    for(int i = 0; i < sizeof(testData1)/sizeof(int); i++)
    {
        test_get(testTree, testData1[i]);
    }
    
    
    test_print(testTree);
    
    std::cout << "<<<<Breadth-first traversal>>>>" << std::endl;
    testTree.breadthFirstTraversal(print_testdata);
    std::cout << "<<<<----------------------->>>>" << std::endl;

    //first should fail
    for(int i = 0; i < sizeof(testData1)/sizeof(int); i++)
    {
        test_remove(testTree, testData1[i]);
    }
    
    test_empty(testTree);
    
    //make sure these things work when tree is empty
    testTree.removeAll();
    testTree.destroyAll();
    
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<END TEST>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl << std::endl << std::endl;
}


/** Do some tests that may be redundant but should cover all cases of insertion and deleteion.
 */

void stress_test_bsTree()
{
    const int testSize = 150;
    const int randMax = 100;
    int testData[testSize];
    BSTree<TestData, int> testTree;
    
    
    
    srand((unsigned int)time(NULL));
    
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<BEGIN STRESS TEST>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    
    for(int i = 0; i < testSize; i++)
    {
        test_insert(testTree, rand() % randMax);
    }
    
    
    test_print(testTree);
    
    
    testTree.destroyAll();
    //testTree.removeAll();
    
    
    if(testTree.isEmpty())
        std::cout << "destroyAll - SUCCESS." << std::endl;
    else
        std::cout << "destroyAll - FAIL" << std::endl;
    
    
    
    for(int i = 0; i < testSize; i++)
    {
        int toAdd = rand() % randMax;
        test_insert(testTree, toAdd);
        testData[i] = toAdd;
    }
    
    for(int i = 0; i < testSize; i++)
    {
        test_remove(testTree, testData[i]);
    }
    
    
    
    if(testTree.isEmpty())
        std::cout << "remove - SUCCESS." << std::endl;
    else
        std::cout << "remove - FAIL" << std::endl;
    
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<END STRESS TEST>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl << std::endl << std::endl;
    
}



int main(void)
{
    test_bstree();
    stress_test_bsTree();
    return 0;
}



