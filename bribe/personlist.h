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
		temp = dltNodes->link; //assigning temp to the next node in the link list
		delete dltNodes; //deleting the actual current node, not the next node (dltNodes->link)
						 //dltNodes = dltNodes->link;
		dltNodes = temp; //assign deletenodes to temp which was assigned to the next node in the link above.
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
	CurrPtr = head; //CHANGED THIS TO HEAD AND THE PROGRAM WORKS MUCH BETTER.
					//CurrPtr->link = NULL;
					//CurrPtr->link = node;



	if (head == NULL) //Can use IsEmpty function here as an alternate method.
	{
		//insertAfter(node, CurrPtr);
		head = node;
		//CurrPtr = node;
		//CurrPtr->link = NULL;
		//node->link = NULL;
		//CurrPtr = node;
		//head->link = NULL;
		//CurrPtr->link = node;

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
			else if (node->bribe == CurrPtr->bribe /*&& node->bribe > CurrPtr->link->bribe*/  && CurrPtr->link != NULL)
			{
				//CurrPtr->link = node;
				insertBefore(node, CurrPtr);
				/*while(node->bribe == CurrPtr->bribe && node->bribe != CurrPtr->link->bribe && node->bribe > CurrPtr->link->bribe)
				{
				if (node->bribe == CurrPtr->bribe && node->bribe > CurrPtr->link->bribe)
				insertBefore(node, CurrPtr);
				else if (node->bribe == CurrPtr->bribe && node->bribe == CurrPtr->link->bribe)
				advance(CurrPtr);*/
				//return;
				//}
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
	//CurrPtr = CurrPtr->link;
	//CurrPtr->link=NULL;
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