/******************************************************************************
 
 Generic binary search tree for handling pointers to objects.  Allocation and
 deallocation of data can be handled outside of the tree.


 Requires:
 int T::compareKey(K keyVal)
 T T::getKey()
 
 
 Author: Robert Hoyer
 ******************************************************************************/

#ifndef BSTREE_H
#define BSTREE_H

#include <functional>
#include <cassert>
#include <iostream>
#include <queue>
#include "BSTreeNode.h"

template <typename T, typename K>
class BSTree
{
    BSTreeNode<T>* root;
    
    
    BSTreeNode<T>* _removeValue(BSTreeNode<T>* subTreePtr, const K& targetKey, T** removed);//bool& success);
    BSTreeNode<T>* _removeNode(BSTreeNode<T>* nodePtr);
    BSTreeNode<T>* _removeLeftMostNode(BSTreeNode<T>* nodePtr, T** inorderSuccessor);

    void _removeAll(BSTreeNode<T>* subTreeptr);
    void _inorder(BSTreeNode<T>* subTreePtr, const std::function<void(T&)>& visit) const;
    void _destroyAll(BSTreeNode<T>* subTreePtr);
    void _printTree(BSTreeNode<T>* subTreePtr, int level) const;
public:
    BSTree();
    ~BSTree();
    
    bool isEmpty() const;
    bool insert( T* pNewRecord);
    T* remove(const K& targetKey);
    //bool exists(const K& targetKey) const;
    T* get(const K& targetKey) const;
    void removeAll();
    void destroyAll();
    void breadthFirstTraversal(const std::function<void(T&)>& visit) const;
    void inorderTraversal(const std::function<void(T&)>& visit) const;
    //void preorderTraversal(const std::function<void(T&)>& visist) const;
    void printTree() const; //this is a pre-order traversal
    
    
    //bool writeToFile(const std::string& filename);
};



/** Default constructor.
 */
template <typename T, typename K>
BSTree<T, K>::BSTree():
root(nullptr)
{}


/** Destructor: Deletes all nodes in tree.
 */

template <typename T, typename K>
BSTree<T, K>::~BSTree()
{
    removeAll();
}

/** Test to see if the tree is empty.
@return true if the tree is empty, false otherwise.
 */

template <typename T, typename K>
bool BSTree<T, K>::isEmpty() const
{
    return (nullptr == root);
}


/** Insert a recrod into the tree.
 @param pNewRecord A pointer to the record to be inserted.
 @return true if the insertion was performed, false otherwise. //todo: this might be better as an int
 */
template <typename T, typename K>
bool BSTree<T, K>::insert(T* pNewRecord)
{
    if(!pNewRecord)
        return false;
    
    BSTreeNode<T>* newNode = new BSTreeNode<T>(pNewRecord);
    
    if(nullptr == root)
    {
        root = newNode;
        return true;
    }
    
    BSTreeNode<T>* current = root;
    BSTreeNode<T>* parent = root;
 
    while(current)
    {
        int compareResult = current->data->compareKey(newNode->data->getKey());
        if(compareResult < 0)
        //        if(compareResult > 0)
        {
            parent = current;
            current = current->right;
        }
        //else if(compareResult < 0)
        else if(compareResult > 0)
        {
            parent = current;
            current = current->left;
        }
        else
        {
            delete newNode;
            return false; //item already exits
        }
    }
    
    if(parent->data->compareKey(newNode->data->getKey()) < 0)
        parent->right = newNode;
    else
        parent->left = newNode;
    
    
    return true;
}


/** Remove a record from the tree with a key value matching the target.
@param targetKey The key value of the record to be deleted.
@return A pointer to the data record that was removed from the tree.  nullptr if the data record was not found.
 */
template <typename T, typename K>
T* BSTree<T, K>::remove(const K& targetKey)
{
    T* removed = nullptr;
    root = _removeValue(root, targetKey, &removed);   
    return removed;
}


/** Recurisve internal function for remove.  Traverses the tree searching for the node to be
    removed the removes it.
    @param subTreePtr A pointer to the subtree to be traversed.
    @param targetKey  Key value of the record being searched for for deletion.
    @param removed Pointer to a pointer of the data value to be removed.  The pointer pointed to by removed
                   will be set to nullptr if the record to be removed is not found.
    @return Pointer to the node to be put in the place of subTreePtr.
 */

template <typename T, typename K>
BSTreeNode<T>* BSTree<T, K>::_removeValue(BSTreeNode<T>* subTreePtr, const K& targetKey, T** removed)
{
    BSTreeNode<T>* tmpPtr;
    
    if(nullptr == subTreePtr) //nothing found
    {
        *removed = nullptr; //todo: double check this
        return nullptr;
    }
    
    int compareResult = subTreePtr->data->compareKey(targetKey);
    
    if(0 == compareResult)
    {
        *removed = subTreePtr->data; //save the value who's node will be removed
        subTreePtr = _removeNode(subTreePtr);
        
        return subTreePtr;
    }
    else if(compareResult > 0) //is this right???
    {
        tmpPtr = _removeValue(subTreePtr->left, targetKey, removed);
        subTreePtr->left = tmpPtr;
        return subTreePtr;
    }
    else
    {
        tmpPtr = _removeValue(subTreePtr->right, targetKey, removed);
        subTreePtr->right = tmpPtr;
        return subTreePtr;
    }
    
}


/** Remove a node from a binary search tree.
@param nodePtr Pointer to the node to be removed.
@return Pointer to the node to replace nodePtr.  nullptr if there is no node to replace it.
 */

template <typename T, typename K>
BSTreeNode<T>* BSTree<T, K>::_removeNode(BSTreeNode<T>* nodePtr)
{
    
    if(nodePtr->isLeaf())
    {
        delete nodePtr;
        nodePtr = nullptr;
        return nodePtr;
    }
    else if(nodePtr->childCount() == 1)
    {
        BSTreeNode<T>* nodeToConnectPtr;
        if(nullptr != nodePtr->left)
            nodeToConnectPtr = nodePtr->left;
        else
            nodeToConnectPtr = nodePtr->right;
        
        delete nodePtr;
        nodePtr = nullptr;
        return nodeToConnectPtr;
    }
    else
    {
        BSTreeNode<T>* tmpPtr;
        T* newNodeValue;

        tmpPtr = _removeLeftMostNode(nodePtr->right, &newNodeValue);
        nodePtr->right = tmpPtr;
        nodePtr->data = newNodeValue;

        return nodePtr;
    }
    
    return nodePtr;
}


/** Remove the left-most node from a subtree of a binary search tree.  Intended to be called
    recursively.  Part of delete.
@param nodePtr The node to be traversed and tested to see if it is a leaf.
@param inorderSuccessor Pointer to a pointer that will contain the pointer to the data of the left-most node.
@return Pointer to the new node at the current position in the tree.
 */

template <typename T, typename K>
BSTreeNode<T>* BSTree<T, K>::_removeLeftMostNode(BSTreeNode<T>* nodePtr, T** inorderSuccessor)
{
    assert(nodePtr);
    if(nullptr == nodePtr->left)
    {
        *inorderSuccessor = nodePtr->data;
        return _removeNode(nodePtr);
    }
    else
    {
        nodePtr->left = _removeLeftMostNode(nodePtr->left, inorderSuccessor);
        return nodePtr;
    }
    
    return nullptr;
}

/** Get a a record from the tree with a key value matching the target.
 */

template <typename T, typename K>
T* BSTree<T, K>::get(const K& targetKey) const
{
    BSTreeNode<T>* current = root;
    
    while(current)
    {
        int compareResult = current->data->compareKey(targetKey);
        if(0 == compareResult)
            return current->data;
        else if(0 < compareResult)
            current = current->left;
        else
            current = current->right;
    }
    
    return nullptr;
}


/** Delete all the nodes in the tree and all data pointed to by each node.
 */

template <typename T, typename K>
void BSTree<T, K>::destroyAll()
{
    _destroyAll(root);
    root = nullptr;
}


/** Recursive internal method for destroyAll.
 */

template <typename T, typename K>
void BSTree<T, K>::_destroyAll(BSTreeNode<T>* subTreePtr)
{
    if(!subTreePtr)
        return;
    
    _destroyAll(subTreePtr->left);
    if(subTreePtr->data)
    {
        delete subTreePtr->data;
        delete subTreePtr;
    }
    _destroyAll(subTreePtr->right);
}


/** Deletes all nodes from the tree without deleting the data pointed to by each node.
 */

template <typename T, typename K>
void BSTree<T, K>::removeAll()
{
    if(root != nullptr)
    {
        _removeAll(root);
        root = nullptr;
    }
}


/** Recursive internal method for destroyAll.
 */

template <typename T, typename K>
void BSTree<T, K>::_removeAll(BSTreeNode<T>* subTreePtr)
{
    if(subTreePtr->left != nullptr)
        _removeAll(subTreePtr->left);
    if(subTreePtr->right != nullptr)
        _removeAll(subTreePtr->right);
    if(subTreePtr)
        delete subTreePtr;
}


//todo - why do we need this again???
/** Perform a breadth-first traversal on the tree calling a non-destructive
    function on each of the data records pointed to by each node.
@param visit Function object to be called on each data record.
 */


template <typename T, typename K>
void BSTree<T, K>::breadthFirstTraversal(const std::function<void(T&)>& visit) const
{
    if(isEmpty())
        return;
    
    
    std::queue<BSTreeNode<T>*> nodeQ;
    
    nodeQ.push(root);
    
    BSTreeNode<T>* current;
    while(!nodeQ.empty())
    {
        current = nodeQ.front();
        nodeQ.pop();
        
        visit(*current->data);
        
        if(current->left)
            nodeQ.push(current->left);
        
        if(current->right)
            nodeQ.push(current->right);
    }
    
}


/** Performs a non-destructive action on each data item in the tree through an inorder traversal.
@param visit Function object to be called on the data of each node in the traversal
*/


template <typename T, typename K>
void BSTree<T, K>::inorderTraversal(const std::function<void(T&)>& visit) const
{
    _inorder(root, visit);
}


/** Recursive internal method for inorderTraversal
 @param subTreePtr Pointer to the sub-tree to be traversed.
 @param visit Function object to be called on the data of each node in the traversal
 */

template <typename T, typename K>
void BSTree<T, K>::_inorder(BSTreeNode<T>* subTreePtr, const std::function<void(T&)>& visit) const
{
    if(!subTreePtr)
        return;
    
    _inorder(subTreePtr->left, visit);
    visit(*(subTreePtr->data));
    _inorder(subTreePtr->right, visit);
}

/** Print the structure of tree to standard output.
 */
template <typename T, typename K>
void BSTree<T, K>::printTree() const
{
    _printTree(root, 0);
}


/** Recursive internal method for printTree().
 @param subTreePtr Pointer to the subtree to print.
 @param level The current level of the subtree.
 */
template <typename T, typename K>
void BSTree<T, K>::_printTree(BSTreeNode<T>* subTreePtr, int level) const
{
    if(!subTreePtr)
        return;
    
    for(int i = level+1; i > 0; i--)
    {
         std::cout << "|";
        if(i == 1)
        {
            std::cout << "--";
        }
        else
            std::cout << "  ";
    }
    
    std::cout << " " << subTreePtr->data->getKey() << std::endl;
    
    _printTree(subTreePtr->left, level+1);
    _printTree(subTreePtr->right, level+1);
    
}


#endif /* defined(BSTREE_H) */
