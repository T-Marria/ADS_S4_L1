#pragma once
#include "Map.h"

Map::Map()
{
	root = NULL;
}

void Map::Print(Tree* tree) const
{
	if (tree)
	{
		Print(tree->left);
		cout << tree->data << " ";
		Print(tree->right);
	}
}

Tree* Map::Insert(Tree** tree, int key, string data)
{
	if (*tree == NULL)
	{
		*tree = new Tree(key, data);
		 return _Balance(root);;
	}
	else if ((*tree)->key > key)
		return Insert(&(*tree)->left, key, data);
	else if ((*tree)->key < key)
		return Insert(&(*tree)->right, key, data);
	return false;
}

void Map::Print() const
{
	Print(root);
	cout << endl;
}

bool Map::Insert(int key, string data)
{
	return Insert(&root, key, data);
}

const string& Map::Find(int key) const
{
	Tree* tree = root;
	while (true)
	{
		if (tree == NULL)
			throw "error: not found\n";
		if (tree->key == key)
			return tree->data;
		if (tree->key > key)
		{
			tree = tree->left;
			continue;
		}
		if (tree->key < key)
		{
			tree = tree->right;
			continue;
		}
	}
}

bool Map::Erase(int key)
{
	Tree* tree = root;
	Tree* prev = NULL;
	while (tree && tree->key != key)
	{
		prev = tree;
		if (tree->key > key)
		{
			tree = tree->left;
		}
		else
		{
			tree = tree->right;
		}
	}
	if (tree == NULL)
		return false;
	if (tree->left == NULL)
	{
		if (prev && prev->left == tree)
			prev->left = tree->right;
		if (prev && prev->right == tree)
			prev->right = tree->right;
		delete tree;
		return true;
	}
	if (tree->right == NULL)
	{
		if (prev && prev->left == tree)
			prev->left = tree->left;
		if (prev && prev->right == tree)
			prev->right = tree->left;
		delete tree;
		return true;
	}
	Tree* subst = tree->right;
	while (subst->left)
		subst = subst->left;
	Erase(subst->key);
	tree->key = subst->key;
}

unsigned Map::_Height(Tree* root)
{
	if (root)
	{
		return root->height;
	}
	else
	{
		return 0;
	}
}

void Map::_Fix_height(Tree* root)
{
	unsigned hl = _Height(root->left);
	unsigned hr = _Height(root->right);
	if (hl > hr)
	{
		root->height = hl + 1;
	}
	else
	{
		root->height = hr + 1;
	}
}

int Map::_Balance_factor(Tree* root)
{
	return _Height(root->right) - _Height(root->left);
}

Tree* Map::_Balance(Tree* root)
{
	_Fix_height(root);
	if (_Balance_factor(root) == -2)
	{
		if (_Balance_factor(root->left) > 0)
			root->left = _Rotate_left(root->left);
		return _Rotate_right(root);
	}
	if (_Balance_factor(root) == 2)
	{
		if (_Balance_factor(root->right) < 0)
			root->right = _Rotate_right(root->right);
		return _Rotate_left(root);
	}
	return root;
}

Tree* Map::_Rotate_left(Tree* root)
{
	Tree* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	_Fix_height(root);
	_Fix_height(temp);
	return temp;
}

Tree* Map::_Rotate_right(Tree* root)
{
	Tree* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	_Fix_height(root);
	_Fix_height(temp);
	return temp;
}

Tree* Map::_Find_min(Tree* root)
{
	if (root->left)
	{
		return _Find_min(root->left);
	}
	else
	{
		return root;
	}
}

Tree* Map::_Erase_min(Tree* root)
{
	if (root->left == nullptr)
		return root->right;
	root->left = _Erase_min(root->left);
	return _Balance(root);
}