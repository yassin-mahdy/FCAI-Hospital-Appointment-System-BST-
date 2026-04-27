#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;

// =====================
// Appointment Class
// =====================
class Appointment {
public:
    string name;
    int priority;
    string department;

    Appointment() {}

    Appointment(string n, int p, string d) {
        name = n;
        priority = p;
        department = d;
    }
};

// =====================
// Node Class
// =====================
class Node {
public:
    Appointment data;
    Node* left;
    Node* right;

    Node(Appointment a) {
        data = a;
        left = right = nullptr;
    }
};

// =====================
// BST Class
// =====================
class BST {
private:
    Node* root;

    // ===== Helper Functions (Recursive) =====
    Node* insert(Node* root, Appointment a);
    void inorder(Node* root);
    void search(Node* root, int priority);
    Node* remove(Node* root, int priority);
    Node* getSuccessor(Node* node);

    void moreUrgent(Node* root, int priority);
    void lessUrgent(Node* root, int priority);

public:
    BST() { root = nullptr; }

    // ===== Public Interface =====
    void insert(Appointment a);
    void displayAll();
    void search(int priority);
    void remove(int priority);
    void displayMoreUrgent(int priority);
    void displayLessUrgent(int priority);
};

#endif
