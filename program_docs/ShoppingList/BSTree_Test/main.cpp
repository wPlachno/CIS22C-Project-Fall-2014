

#include "BSTree.h"
#include <iostream>

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





void print_testdata(TestData& td)
{
    std::cout << td.getKey() << std::endl;

}



void test_bstree()
{

    BSTree<TestData, int> testTree;

    testTree.insert(new TestData(50));
    testTree.insert(new TestData(100));
    testTree.insert(new TestData(75));
    testTree.insert(new TestData(25));
    testTree.insert(new TestData(0));

    //    testTree.insert(new TestData(45));
    //    testTree.insert(new TestData(96));
    //    testTree.insert(new TestData(34));


    //TestData* removed = testTree.remove(50);
    //delete removed;
    //removed = testTree.remove(100);
    //delete removed;

    //if(removed)
    //    std::cout << "removed:" << removed->getKey() << std::endl;

    testTree.inorderTraversal(print_testdata);
    std::cout << "---------" << std::endl;
    testTree.printTree();
}





int main(void)
{

    return 0;
}



