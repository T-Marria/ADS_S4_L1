#include <stdio.h>
#include <chrono>
#include "Map.h"
using namespace std;

int main()
{
	Map shapes;
	shapes.Insert(1, "dot");
	shapes.Insert(3, "triangle");
	shapes.Insert(4, "rectangle");
	shapes.Insert(2, "line");
	//shapes.Insert(10, "decagon");
	//shapes.Insert(-3, "(((");
	//shapes.Insert(-7, "((((((");
	//shapes.Insert(25, "25dots");
	//shapes.Insert(9, "nonagon");
	//shapes.Insert(90, "90dots");
	//shapes.Insert(0, "zero");
	try {
		shapes.Insert(0, "zero");
	}
	catch (const char* msg) {
		cout << msg;
	}
	cout << "_________________";

	try
	{
		string found;
		found = shapes.Find(1);
		cout << "\nshapes.Find(1) = " << found << endl;
		cout << "shapes.Find(7):\n";
		shapes.Find(7);
	}
	catch (const char* msg)
	{
		cout << msg;
	}
	cout << "_________________" << endl;
	shapes.Print();
	shapes.Erase(2);
	shapes.Insert(6, "hexagon");
	shapes.Print();

	cout << "_________________" << endl;
	shapes.PrintTree();

	/*chrono::steady_clock::time_point begin;
	chrono::steady_clock::time_point end;
	for (int i = 0; i < 10; i++)
	{
		begin = chrono::steady_clock::now();
		for (int j = 1; j < 100000; j++)
		{
			shapes.Insert(i * 100000 + j, "test");
		}
		end = chrono::steady_clock::now();
		cout << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << endl;
	}*/


	return 0;
}