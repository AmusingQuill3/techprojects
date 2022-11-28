#pragma once
//llist.h
#include "list.h"
#include "link.h"
#include "book.h"
using namespace std;

#ifndef LLIST_H
#define LLIST_H

template <typename E>
class LList : public List<E> {
private:
	Link<E>* head;
	Link<E>* tail;
	Link<E>* curr;
	int cnt;
	int accessed;

	void init() {
		curr = tail = head = new Link<E>;
		cnt = 0;
	}

	void removeall() {
		while (head != NULL) {
			curr = head;
			head = head->next;
			delete curr;
		}
	}

public:
	LList() { init(); }
	~LList() { removeall(); }
	//void print() const;
	void clear() { removeall(); init(); }

	// Insert "it" at current position
	void insert(const E& it) {
		curr->next = new Link<E>(it, curr->next);
		if (tail == curr) tail = curr->next; // New tail
		//cout << endl << it << " has been inserted.";
		cnt++;
	}

	void append(const E& it) { // Append "it" to list
		tail = tail->next = new Link<E>(it, NULL);
		tail->setAccessed(0);
		head->setAccessed(0);
		cnt++;
	}

	// Remove and return current element
	E remove() {
		//Assert(curr->next != NULL, "No element");
		E it = curr->next->element;
		Link<E>* ltemp = curr->next;
		if (tail == curr->next) tail = curr;
		curr->next = curr->next->next;
		delete ltemp;
		cnt--;
		//cout << endl << it << " has been removed.";
		return it;
	}

	void moveToStart()
	{
		curr = head;
	}

	void moveToEnd()
	{
		curr = tail;
	}

	// Move curr one step left; no change if already at front
	void prev() {
		if (curr == head) return;
		Link<E>* temp = head;
		// March down list until we find the previous element
		while (temp->next != curr) temp = temp->next;
		curr = temp;
	}

	// Move curr one step right; no change if already at end
	void next()
	{
		if (curr != tail) curr = curr->next;
	}

	int length() const { return cnt; }

	// Return the position of the current element
	int currPos() const {
		Link<E>* temp = head;
		int i;
		for (i = 0; curr != temp; i++)
			temp = temp->next;
		return i;
	}

	// Move down list to "pos" position
	void moveToPos(int pos) {
		Assert((pos >= 0) && (pos <= cnt), "Position out of range");
		curr = head;
		for (int i = 0; i < pos; i++) curr = curr->next;
	}

	const E& getValue() const {
		Assert(curr->next != NULL, "No value");
		return curr->next->element;
	}

	//Function to set the number of accesses for an item
	void setTimesAccessed(int n) {
		curr->setAccessed(n);
	}

	//Return the current number of accesses for a link
	int getTimesAccessed() const {
		return curr->getAccessed();
	}

	//Return the tail value from the list
	E tailValue() {
		return tail->element;
	}

	//Return the front value from the list
	E frontValue() {
		return head->next->element;
	}

	//Function to print the list
	void print() const {
		//Temp pointer to head next
		Link<E>* temp = head->next;

		//Temp pointer to head
		Link<E>* temp2 = head;
		cout << endl;

		//Loop to go through and print all items in the list
		for (int i = 0; i < cnt; i++)
		{
			//Display the element and the number of accesses
			cout << " " << temp->element << "-" << temp2->getAccessed();
			temp = temp->next;
			temp2 = temp2->next;
		}
	}

	//Same as above, but the loop is for a specific number as specified by n
	void print(int n) const {
		Link<E>* temp = head->next;
		Link<E>* temp2 = head;
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			cout << " " << temp->element << "-" << temp2->getAccessed();
			temp = temp->next;
			temp2 = temp2->next;
		}
	}
};

#endif
