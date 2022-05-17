#include "Map.h"

int main()
{
	Map shapes;
	shapes.Insert(1, "dot");
	shapes.Insert(3, "triangle");
	shapes.Insert(4, "rectangle");
	shapes.Insert(2, "line");
	try
	{
		string found;
		found = shapes.Find(1);
		cout << "shapes.Find(1) = " << found << endl;
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
}