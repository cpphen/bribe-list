#pragma once

#include "personlist.h"
#include <iostream>
#include <string>
using namespace std;

struct PersonRec {
	int bribe;
	char name[20];
	PersonRec * link;
};


PersonList::PersonList()
{
	head = NULL;
}

PersonList::~PersonList()
{
	PersonRec * dltNodes;
	PersonRec * temp;
	dltNodes = head;

	while (dltNodes != NULL)
	{
		temp = dltNodes->link; 
		delete dltNodes; 
		dltNodes = temp; 
	}
}

void PersonList::AddToList()
{
	char UserName[20];
	int UserBribe;
	cout << "Enter name: ";
	cin.getline(UserName, 20);
	cout << "Enter bribe amount: ";
	cin >> UserBribe;

	PersonRec * CurrPtr; //temp
	PersonRec * node = new PersonRec;
	strcpy(node->name, UserName);
	node->bribe = UserBribe;
	node->link = NULL;
	CurrPtr = head; 



	if (head == NULL) 
	{
		head = node;
	}
	else if (head != NULL)
	{
		reset(CurrPtr);
		if (node->bribe > CurrPtr->bribe)
		{
			head = node;
			head->link = CurrPtr;
			return;
		}
		while (CurrPtr != NULL  && CurrPtr->bribe > node->bribe)
		{

			if (node->bribe < CurrPtr->bribe && CurrPtr->link != NULL && node->bribe > CurrPtr->link->bribe)
			{
				insertBefore(node, CurrPtr);
				return;
			}
			else if (node->bribe == CurrPtr->bribe && CurrPtr->link != NULL)
			{
				insertBefore(node, CurrPtr);
			}
			else if (node->bribe == CurrPtr->bribe && CurrPtr->link == NULL)
				insertAfter(node, CurrPtr);
			else if (CurrPtr->link == NULL)
			{
				insertAfter(node, CurrPtr);
				return;
			}
			else
				advance(CurrPtr);
		}


	}

}

void PersonList::insertAfter(PersonRec * node, PersonRec * CurrPtr)
{
	CurrPtr->link = node;
}

void PersonList::insertBefore(PersonRec * node, PersonRec * CurrPtr)
{
	PersonRec * CurrPtr2;
	CurrPtr2 = CurrPtr->link;
	CurrPtr->link = node;
	node->link = CurrPtr2;
}

void PersonList::reset(PersonRec *& CurrPtr)
{
	CurrPtr = head;
}

void PersonList::advance(PersonRec *& CurrPtr)
{
	CurrPtr = CurrPtr->link;
}

void PersonList::ViewList()
{
	PersonRec * tempView;
	int numCounter = 0;
	tempView = head;
	if (tempView == NULL)
		cout << "List is empty.\n";
	else if (tempView != NULL)
		while (tempView != NULL)
		{
			numCounter++;
			cout << numCounter << ": " << "Name: " << tempView->name << " / " << "Bribe: $" << tempView->bribe << endl;
			tempView = tempView->link;
		}
}