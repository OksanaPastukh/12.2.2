#include <iostream>
#include <Windows.h>
#include <ctime>
#include <queue>
using namespace std;

struct Elem
{
	Elem* link;
	int info;
};
void enqueue(Elem*& first, Elem*& last, int size, int min_value, int max_value, int i)
{
	int ElemInfo = min_value + rand() % (max_value - min_value + 1);
	Elem* tmp = new Elem;
	tmp->info = ElemInfo;
	tmp->link = NULL;
	if (last != NULL)
	{
		last->link = tmp;
	}
	last = tmp;
	if (first == NULL)
	{
		first = tmp;
	}
	if (i < size - 1)
	{
		enqueue(first, last, size, min_value, max_value, i + 1);
	}
}
void Print(Elem* current)
{
	if (current == NULL)
	{
		exit(0);
	}
	cout << current->info << " ";
	if (current->link != NULL)
	{
		Print(current->link);
	}
	else
		cout << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	Elem* first = NULL,
		* last = NULL;
	int size;
	cout << "Розмір черги : "; cin >> size;
	int min_value = 0;
	int max_value = 10;
	enqueue(first, last, size, min_value, max_value, 0);// create
	Print(NULL);
	return 0;
}