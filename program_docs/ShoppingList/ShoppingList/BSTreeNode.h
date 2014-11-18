/******************************************************************************
 
 
 Author: Robert Hoyer
 ******************************************************************************/

#ifndef BSTREENODE_H
#define BSTREENODE_H

template <typename T>
class BSTreeNode
{
public:
    T* data;
    BSTreeNode<T>* left;
    BSTreeNode<T>* right;
    
    BSTreeNode();
    BSTreeNode(T* data);
    
    bool isLeaf() const;
    int childCount() const;
};



template <typename T>
BSTreeNode<T>::BSTreeNode():
left(nullptr),
right(nullptr),
data(nullptr)
{}



template <typename T>
BSTreeNode<T>::BSTreeNode(T* data):
left(nullptr),
right(nullptr),
data(data)
{}


template <typename T>
bool BSTreeNode<T>::isLeaf() const
{
    return (nullptr == left && nullptr == right);
}


template <typename T>
int BSTreeNode<T>::childCount() const
{
    int count = 0;
    
    if(left != nullptr)
        count++;
    if(right != nullptr)
        count++;
    
    return count;
}


#endif
