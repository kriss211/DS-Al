#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
#include "CIP.h"

catNode::catNode()
{
	this->order = 0;
	this->next = nullptr;
}

dogNode::dogNode()
{
	this->order = 0;
	this->next = nullptr;
}

petQueue::petQueue()
{
	totalPet = 0;
	headCat = nullptr;
	tailCat = nullptr;
	headDog = nullptr;
	tailDog = nullptr;
}

void petQueue::enqueue(petType type)
{
	totalPet++;
	if (type == cat)
	{
		catNode* cat = new catNode();
		cat->order = totalPet;
		if (tailCat == nullptr && headCat == nullptr) tailCat = headCat = cat;
		tailCat->next = cat;
		tailCat = cat;
	}
	else
	{
		dogNode* dog = new dogNode();
		dog->order = totalPet;
		if (tailDog == nullptr && headDog == nullptr) tailDog = headDog = dog;
		tailDog->next = dog;
		tailDog = dog;
	}
}

void petQueue::dequeueAny()
{
	if (headCat == nullptr && headDog == nullptr) cout << "there is no pet left! \n";
	else if(headCat != nullptr && headDog == nullptr) dequeueCat();
	else if (headCat == nullptr && headDog != nullptr) dequeueDog();
	else {
		if (headCat->order < headDog->order)
		{
			dequeueCat();
		}
		else
		{
			dequeueDog();
		}
	}
}

void petQueue::dequeueCat()
{
	if (headCat == nullptr) cout << "there is no cat left! \n";
	catNode* tempCat = headCat;
	headCat = headCat->next;
	cout << "dequeue cat pos:" << tempCat->order << "\n";
	delete tempCat;
}

void petQueue::dequeueDog()
{
	if (headDog == nullptr) cout << "there is no dog left! \n";
	dogNode* tempDog = headDog;
	headDog = headDog->next;
	cout << "dequeue dog pos:" << tempDog->order << "\n";
	delete tempDog;
}

void checkPetQueue()
{
	petQueue petSelter = petQueue();
	petSelter.enqueue(cat);
	petSelter.enqueue(cat);
	petSelter.enqueue(dog);
	petSelter.enqueue(cat);
	petSelter.enqueue(dog);

	/*first case*/
	//petSelter.dequeueAny();
	//petSelter.dequeueAny();
	//petSelter.dequeueAny();
	//petSelter.dequeueAny();
	//petSelter.dequeueAny();

	/*second case*/
	//petSelter.dequeueCat();
	//petSelter.dequeueCat();
	//petSelter.dequeueAny();
	//petSelter.dequeueDog();
	//petSelter.dequeueAny();

	/*third case*/
	petSelter.dequeueDog();
	petSelter.dequeueAny();
	petSelter.dequeueAny();
	petSelter.dequeueDog();
	petSelter.dequeueCat();
}