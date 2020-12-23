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
		return;
	}
	cout << current->info << " ";
	if (current->link != NULL)
	{
		Print(current->link);
	}
	else
	{
		cout << endl;
	}
}
bool check_info(Elem* previous)
{
	if (previous == NULL)
	{
		return false;
	}
	Elem* current = previous->link;
	if (previous->info == current->info)
		{
			return true;
		}
	previous = current;
	current = current->link;
	if (current->link != NULL)
	{
		check_info(previous->link);
	}
	else
	{
		return false;
	}
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
	Print(first);
	if (check_info(first) == true)
	{
		cout << "В списку є пара" << endl;
	}
	else
	{
		cout << "В списку немає пари" << endl;
	}
	return 0;
}