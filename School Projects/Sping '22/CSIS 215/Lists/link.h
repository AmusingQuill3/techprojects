#pragma once
//link.h
#ifndef LINK_H
#define LINK_H

template <typename E> class Link {
public:
	E element;
	Link* next;
	int timesAccessed;
	// Constructors
	Link(const E& elemval, Link* nextval = NULL)
	{
		element = elemval; next = nextval;
	}
	Link(Link* nextval = NULL) { next = nextval; }

	//Function to set the number of accesses
	void setAccessed(int n)
	{
		timesAccessed = n;
	}

	//Function to return the number of accesses
	int getAccessed()
	{
		return timesAccessed;
	}
};

#endif
