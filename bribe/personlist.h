#pragma once
#ifndef PERSON_H
#define PERSON_H

struct PersonRec;

class PersonList {

public:
	PersonList();
	~PersonList();
	void ViewList();
	void AddToList();

private:
	PersonRec* head;
	void insertAfter(PersonRec *, PersonRec *);
	void insertBefore(PersonRec *, PersonRec *);
	void reset(PersonRec *&);
	void advance(PersonRec *&);
};
#endif