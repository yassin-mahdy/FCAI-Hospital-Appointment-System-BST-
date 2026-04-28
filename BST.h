#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;

class Appointment
{
public:
    string name;
    int priority;
    string department;

    Appointment() {}

    Appointment(string n, int p, string d)
    {
        name = n;
        priority = p;
        department = d;
    }
    void print() const
    {
        cout << "[" << name << ", "
             << priority << ", "
             << department << "]" << endl;
    }
};

class Node
{
public:
    Appointment data;
    Node *left;
    Node *right;

    Node(Appointment a)
    {
        data = a;
        left = right = nullptr;
    }
};

class BST
{
private:
    Node *root;
    Node *insert(Node *root, Appointment a)
    {
        // Empty tree case (first insertion)
        if (root == nullptr)
            return new Node(a);

        if (a.priority <= root->data.priority)
            root->left = insert(root->left, a);
        else
            root->right = insert(root->right, a);

        return root;
    }
    void inorder(Node *root) // inorder traversal
    {
        if (root != nullptr)
        {
            inorder(root->left);
            root->data.print();
            inorder(root->right);
        }
    }
    void search(Node *root, int priority)
    {
        if (root == nullptr)
        {
            return;
        }
        search(root->left, priority); // search the left subtree
        if (root->data.priority == priority)
        {
            root->data.print(); // check wether a match if found or not
        }
        search(root->right, priority); // search the right subtree
    }
    Node *remove(Node *root, int priority)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        root->left = remove(root->left, priority);
        root->right = remove(root->right, priority);
        if (root->data.priority == priority) // search for match if found then delete
        {
            if (root->left == nullptr && root->right == nullptr) // no child case
            {
                delete root;
                return nullptr;
            }
            else if (root->left == nullptr) // only one child case
            {
                Node *newnode = root->right;
                delete root;
                return newnode;
            }
            else if (root->right == nullptr) // same goes for right child
            {
                Node *newnode = root->left;
                delete root;
                return newnode;
            }
            else // 2 children case
            {
                Node *success = getSuccessor(root->right);
                root->data = success->data;
                root->right = remove(root->right, success->data.priority);
            }
        }
        return root;
    }
    Node *getSuccessor(Node *node)
    {
        while (node && node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    void moreUrgent(Node *root, int priority)
    {
        if (root == nullptr)
            return;

        // If current node too large skip right subtree
        if (root->data.priority > priority)
        {
            moreUrgent(root->left, priority);
        }
        else // Current node is valid
        {

            moreUrgent(root->left, priority);

            root->data.print();

            moreUrgent(root->right, priority);
        }
    }
    void lessUrgent(Node *root, int priority)
    {
        if (root == nullptr)
            return;

        // If too small skip left subtree
        if (root->data.priority < priority)
        {
            lessUrgent(root->right, priority);
        }
        else
        {
            lessUrgent(root->left, priority);

            root->data.print();

            lessUrgent(root->right, priority);
        }
    }

public:
    BST() { root = nullptr; }
    void insert(Appointment a)
    {
        root = insert(root, a);
    }
    void displayAll()
    {
        if (root == nullptr)
            return;
        inorder(root);
    }
    void search(int priority)
    {
        search(root, priority);
    }
    void remove(int priority)
    {
        root = remove(root, priority);
    };
    void displayMoreUrgent(int priority)
    {
        moreUrgent(root, priority);
    }
    void displayLessUrgent(int priority)
    {
        lessUrgent(root, priority);
    }
};

#endif
