// Kontenery
#include <vector>	// Tablica
#include <set>		// Zbiór
#include <map>		// Słownik

// Adaptery
#include <queue>	// Kolejka
#include <stack>	// Stos

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include "Slav.h"

#define REPORT_ADAPTERS showMeAdapterSizes(queueOfSlavs,stackOfSlavs)
#define REPORT_CONTAINERS showMeContainerSizes(vectorOfSlavs,setOfSlavs,mapOfSlavs)

using namespace std;

void showMeContainerSizes(vector <Slav *>, set <Slav *>, map <Slav *, Slav*>);
void showMeAdapterSizes(queue <Slav *>, stack <Slav *>);

void containers(Slav *, int);
void adapters(Slav *, int);

int main(int argc, char const *argv[])
{
	int n = 2 * atoi(argv[1]);
	Slav *slavs = new Slav[n];
	cout << "# Generated Slavs" << endl;
	for (int i = 0; i < n; ++i)
		cout << slavs[i].description() << endl;

	containers(slavs, n);
	adapters(slavs, n);

	delete [] slavs;
}

void containers(Slav * slavs, int n)
{
	vector <Slav *> vectorOfSlavs;
	set <Slav *> setOfSlavs;
	map <Slav *, Slav *> mapOfSlavs;
	
	printf("# Containers\n");
	REPORT_CONTAINERS;
	printf("## vector\n");
	int where=0;
	// Umieść Słowian w losowej kolejności w wektorze.
	for (int i = 0; i < n; ++i)
	{
		vectorOfSlavs.insert(vectorOfSlavs.begin()+where,slavs+i);
		where=rand()%vectorOfSlavs.size();
	}
	// Wykorzystując iterator i funkcję description(), wyświetl wszystkich Słowian w wektorze
	for (vector <Slav *>::iterator iter = vectorOfSlavs.begin();iter != vectorOfSlavs.end(); iter++)
		cout << (*iter)->description() << endl;
	REPORT_CONTAINERS;
	printf("## set\n");

	// Przenieś wszystkich Słowian z wektoru do zbioru.
	for (int i = 0; i < n; ++i)
	{
		where=rand()%vectorOfSlavs.size();
		setOfSlavs.insert(vectorOfSlavs.front());
		vectorOfSlavs.erase(vectorOfSlavs.begin());
	}
	REPORT_CONTAINERS;
	printf("## map\n");

	// Stwórz słownik tworzący pary Słowian, z tych znajdujących się w zbiorze, czyszcząc zbiór
	for (set <Slav *>::iterator iter = setOfSlavs.begin();iter != setOfSlavs.end(); iter++)
	{
		mapOfSlavs[*iter++]=*iter--;
		setOfSlavs.erase(iter);
		setOfSlavs.erase(++iter);
	}
	// Wykorzystując iterator, wyświetl wszystkie pary Słowian
	for (map <Slav *, Slav *>::iterator iter = mapOfSlavs.begin(); iter != mapOfSlavs.end(); iter++)
	{
		cout<< (*iter).first->description() << " --- \t";
		cout<< (*iter).second->description() << endl;
	}
	REPORT_CONTAINERS;
}

void adapters(Slav * slavs, int n)
{
	queue <Slav *> queueOfSlavs;
	stack <Slav *> stackOfSlavs;

	printf("# Adapters\n");
	REPORT_ADAPTERS;
	printf("## queue\n");

	// Umieść Słowian w kolejce.
	
	REPORT_ADAPTERS;

	printf("## stack\n");
	// Przenieś Słowian z kolejki do stosu.

	REPORT_ADAPTERS;

	// Wyświetl Słowian zdejmowanych ze stosu.

	REPORT_ADAPTERS;
}

void showMeContainerSizes(vector <Slav *> vector, set <Slav *> set, map <Slav *, Slav*> map)
{
	printf("[vector_size = %u, set_size = %u, map_size = %u, existingSlavs = %i]\n",
		vector.size(),
		set.size(),
		map.size(),
		Slav::counter());
}

void showMeAdapterSizes(queue <Slav *> queue, stack <Slav *> stack)
{
	printf("[queue_size = %u, stack_size = %u, existingSlavs = %i]\n",
		queue.size(),
		stack.size(),
		Slav::counter());

}
