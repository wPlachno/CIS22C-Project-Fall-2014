/******************************************************************************
 
 Generic node class for BSTree.
 
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


/** Constructor
 */

template <typename T>
BSTreeNode<T>::BSTreeNode():
left(nullptr),
right(nullptr),
data(nullptr)
{}

/** Constructor
@param data Pointer to the data value for the node.
 */

template <typename T>
BSTreeNode<T>::BSTreeNode(T* data):
left(nullptr),
right(nullptr),
data(data)
{}


/** Test to see if the node is a leaf.
@return true if the node is a leaf, false otherwise.
 */

template <typename T>
bool BSTreeNode<T>::isLeaf() const
{
    return (nullptr == left && nullptr == right);
}


/** Get the number of children the node has.
@return The number of children.
 */

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
