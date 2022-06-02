#pragma once
#include "Map.h"

Map::Map()
{
	root = NULL;
}

void Map::_Print(Tree* tree) const
{
	if (tree)
	{
		_Print(tree->left);
		cout << tree->data << " ";
		_Print(tree->right);
	}
}

void Map::_PrintTree(Tree* tree, int level) const
{
	if (tree)
	{
		_PrintTree(tree->right, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << tree->key << endl;
		_PrintTree(tree->left, level + 1);
	}
}

Tree* Map::_Insert(Tree* root, int key, string value)
{
	if (!root)
	{
		root = new Tree(key, value);
	}
	else
	{
		if (key < root->key)
		{
			root->left = _Insert(root->left, key, value);
		}
		else if (key > root->key)
		{
			root->right = _Insert(root->right, key, value);
		}
		else throw "Element already exists\n";
	}
	return _Balance(root);
}

Tree* Map::_Erase(Tree* root, int key)
{
	if (!root)
		return nullptr;
	if (key < root->key)
	{
		root->left = _Erase(root->left, key);
	}
	else if (key > root->key)
	{
		root->right = _Erase(root->right, key);
	}
	else
	{
		Tree* temp_l = root->left;
		Tree* temp_r = root->right;
		delete root;
		if (!temp_r) return temp_l;
		if (!temp_l) return temp_r;
		Tree* min = _Find_min(temp_r);
		min->right = _Erase_min(temp_r);
		min->left = temp_l;
		return _Balance(min);
	}
	return _Balance(root);
}

void Map::Print() const
{
	_Print(root);
	cout << endl;
}

void Map::PrintTree() const
{
	_PrintTree(root, 1);
	cout << endl;
}

bool Map::Insert(int key, string data)
{
	root = _Insert(root, key, data);
	return true;
}

bool Map::Erase(int key)
{
	root = _Erase(root, key);
	return true;
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
			tree = tree->left;

		if (tree->key < key)
			tree = tree->right;
	}
}

unsigned Map::_Height(Tree* root)
{
	if (root)
		return root->height;

	else
		return 0;
}

void Map::_Fix_height(Tree* root)
{
	unsigned hl = _Height(root->left);
	unsigned hr = _Height(root->right);
	if (hl > hr)
		root->height = hl + 1;

	else
		root->height = hr + 1;
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
		return _Find_min(root->left);

	else
		return root;
}

Tree* Map::_Erase_min(Tree* root)
{
	if (root->left == nullptr)
		return root->right;
	root->left = _Erase_min(root->left);
	return _Balance(root);
}