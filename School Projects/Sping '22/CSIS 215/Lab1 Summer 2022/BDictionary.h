#pragma once

#include "ABag.h"
#include "dictionaryADT.h"
#include "kvpair.h"
#include <memory>

template <typename Key, typename E>
class BDictionary : public Dictionary<Key, E>
{
public:
	// Constructors
	BDictionary() //Default
	{
		aSmallBag = std::make_unique<ABag<KVpair<Key, E>>>(10);
	}
	
	BDictionary(int ten)
	{
		aSmallBag = std::make_unique <ABag<KVpair<Key, E>>>(ten);
	}


	// Destructor
	~BDictionary() {}


	// methods: clear, insert, remove, removeAny, find, size, etc.

	// Reinitialize Dictionary
	void clear()
	{
		aSmallBag->emptyBag(); //Emptys the bag
	}

	// Inserting a record
	// k: The key for the record being inserted.
	// e: The record being inserted.
	// Return true if insert is successful and false othewise.
	bool insert(const Key& k, const E& e)
	{
		KVpair<Key, E> Name(k, e);
		if (aSmallBag->addItem(Name)) // Inserting a record and if it works return true else return false
			return true;
		else
			return false;
	}

	// Looks for a record using the key and if found does the following:
	// - Updates the E& rtnVal
	// - Removes the record from the dictionary
	// - Returns true
	// If the record is not found the function returns false.
	bool remove(const Key& k, E& rtnVal)
	{
		KVpair<Key, E> Name(k, rtnVal);
		if (aSmallBag->remove(Name)) // Removes the record from the dictionary
		{
			rtnVal = Name.value(); // Updates the rtnVal
			return true;
		}
		else
			return false;
	}

	// Takes an arbitrary record from the dictionary and does the following:
	// - Updates the E& returnValue
	// - Removes the record from the dictionary
	// - Returns true
	// If the dictionary is empty the function returns false.
	bool removeAny(E& returnValue)
	{
		Key k{};
		KVpair<Key, E> Name(k, returnValue);
		if (aSmallBag->inspectTop(Name))
		{
			returnValue = Name.value(); // Using value for the E updating return value
			aSmallBag->removeTop(Name);
			return true;
		}
		else
		{
			return false;
		}
	}

	//Looks for a record using the key and if found does the following:
	// - Updates the E& returnValue
	// - Returns true
	// If the record is not found the function returns false.
	bool find(const Key& k, E& returnValue) const
	{
		KVpair<Key, E> Name(k, returnValue);
		if (aSmallBag->find(Name))
		{
			returnValue = Name.value(); // Using value to capture the E
			return true;
		}
		else
			return false;
	}

	// Return the number of records in the dictionary.
	int size()
	{
		return aSmallBag->size(); // Returns the size
	}

private:
	std::unique_ptr<ABag <KVpair<Key, E>>> aSmallBag;
};


