/******************************************************************************
 
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
    void _deleteAllData(BSTreeNode<T>* subTreePtr);
    void _printTree(BSTreeNode<T>* subTreePtr, int level) const;
public:
    BSTree();
    ~BSTree();
    
    bool isEmpty() const;
    bool insert( T* newItem);
    T* remove(const K& targetKey);
    bool exists(const K& targetKey) const;
    T* get(const K& targetKey) const;
    void removeAll();
    void deleteAllData();
    void breadthFirstTraversal(const std::function<void(T&)>& visit) const;
    void inorderTraversal(const std::function<void(T&)>& visit) const;
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

template <typename T, typename K>
bool BSTree<T, K>::isEmpty() const
{
    return (nullptr == root);
}


//maybe try pointer to pointer method
template <typename T, typename K>
bool BSTree<T, K>::insert(T* newItem)
{
    assert(newItem);
    if(!newItem)
        return false;
    
    BSTreeNode<T>* newNode = new BSTreeNode<T>(newItem);
    
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


// hack to make the interface work
template <typename T, typename K>
T* BSTree<T, K>::remove(const K& targetKey)
{
    T* removed = nullptr;
    root = _removeValue(root, targetKey, &removed);   
    return removed;
}



template <typename T, typename K>
BSTreeNode<T>* BSTree<T, K>::_removeValue(BSTreeNode<T>* subTreePtr, const K& targetKey, T** removed)
{
    BSTreeNode<T>* tmpPtr;
    
    if(nullptr == subTreePtr)
        return nullptr;
    
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


template <typename T, typename K>
T* BSTree<T, K>::get(const K& targetKey) const
{
    BSTreeNode<T>* current = root;
    
    while(current)
    {
        int compareResult = current->data->compareKey(targetKey);
        if(0 == compareResult)
            return current;
        else if(0 < compareResult)
            current = current->left;
        else
            current = current->right;
    }
    
    return nullptr;
}


template <typename T, typename K>
void BSTree<T, K>::removeAll()
{
    if(root != nullptr)
    {
        _removeAll(root);
        root = nullptr;
    }
}

template <typename T, typename K>
void BSTree<T, K>::deleteAllData()
{
    _deleteAllData(root);
}


template <typename T, typename K>
void BSTree<T, K>::_deleteAllData(BSTreeNode<T>* subTreePtr)
{
    if(!subTreePtr)
        return;
    
    _deleteAllData(subTreePtr->left);
    if(subTreePtr->data)
    {
        delete subTreePtr->data;
        subTreePtr->data = nullptr;
    }
    _deleteAllData(subTreePtr->right);
}


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
        current = nodeQ.pop();
        visit(*current->data);
        
        if(current->left)
            nodeQ.push(current->left);
        
        if(current->right)
            nodeQ.push(current->right);
    }
    
}



template <typename T, typename K>
void BSTree<T, K>::inorderTraversal(const std::function<void(T&)>& visit) const
{
    _inorder(root, visit);
}


template <typename T, typename K>
void BSTree<T, K>::_inorder(BSTreeNode<T>* subTreePtr, const std::function<void(T&)>& visit) const
{
    if(!subTreePtr)
        return;
    
    _inorder(subTreePtr->left, visit);
    visit(*(subTreePtr->data));
    _inorder(subTreePtr->right, visit);
}


template <typename T, typename K>
void BSTree<T, K>::printTree() const
{
    _printTree(root, 0);
}

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
