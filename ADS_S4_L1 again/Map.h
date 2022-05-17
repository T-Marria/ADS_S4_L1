#pragma once
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct Tree {
    int key;
    string data;
    Tree* left;
    Tree* right;
    int height;
    Tree(int k, string v) : key(k), data(v), left(nullptr), right(nullptr), height(1) {}
};

class Map {
private:
    Tree* root;
    void _Print(Tree* tree) const;
    void _PrintTree(Tree* p, int level) const;
    Tree* _Insert(Tree* root, int key, string value);
    Tree* _Erase(Tree* root, int key);
    unsigned _Height(Tree* root);
    void _Fix_height(Tree* root);
    int _Balance_factor(Tree* root);
    Tree* _Balance(Tree* root);
    Tree* _Rotate_left(Tree* root);
    Tree* _Rotate_right(Tree* root);
    Tree* _Find_min(Tree* root);
    Tree* _Erase_min(Tree* root);
public:
    Map();
    void Print() const;
    void PrintTree() const;
    bool Insert(int key, string data);
    const string& Find(int key) const;
    bool Erase(int key);
};