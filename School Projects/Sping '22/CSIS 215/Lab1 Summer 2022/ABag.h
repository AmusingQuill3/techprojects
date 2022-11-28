#pragma once

#include "bagADT.h"
#include <memory>

template <typename E>
class ABag : public Bag<E>
{
public:
	// Constructors
	ABag()
	{
		bagCP = 10;
		bagCS = 0;
		bagArray = std::make_unique<E[]>(bagCP); //Double check to make sure array is right
	}

	ABag(int capacity)
	{
		bagCP = capacity;
		bagCS = 0;
		bagArray = std::make_unique<E[]>(bagCP);
	}

	// Destructor
	~ABag() {}


	// bag methods: addItem, remove, operator+=, size, etc.

	//Insert a new item into the bag -- return false if it fails and true if it is successful
	bool addItem(const E& item)
	{
		if (bagCS < bagCP)
		{
			bagArray[bagCS] = item; //Inserts new item into the bag
			bagCS++; //Increments bagCS
			return true;
		}
		else
		{
			return false;
		}
	};

	// Looks for 'item' in the bag and if found updates 'item' with the bag value and returns true.
	// Otherwise 'item' is left unchanged and the method returns false.
	bool remove(E& item) //USED
	{
		if (bagCS == 0)
		{
			return false;
		}
		else
		{
			for (int x = 0; x < bagCS; x++)
			{
				if (item == bagArray[x])
				{
					item = bagArray[x];
					//Updates item and then decrements
					bagCS--;
					for (int y = x; y < bagCS; y++)
					{
						bagArray[y] = bagArray[y + 1];
					}
					return true;
				}
			}
			return false;
		}
	};

	// Removes the top record from the bag, puts it in returnValue, and returns true if the bag is not empty.
	// If the bag is empty the function returns false and returnValue remains unchanged.
	bool removeTop(E& returnValue)
	{
		if (bagCS == 0)
			return false;
		else
		{
			bagCS--; // Removes the top record
			returnValue = bagArray[bagCS]; //Puts the value into returnValue
			return true;
		}
	};

	// Find the record using returnValue and if the record is found it updates return Value based on the contents of the bag and returns true.
	// If the record is not found the function returns false.
	bool find(E& returnValue) const
	{
		if (bagCS == 0)
			return false;
		else
		{
			for (int x = 0; x < bagCS; x++) // Looks through bag until it finds the returnValue. When it is found returnValue is updated.
			{
				if (returnValue == bagArray[x])
				{
					returnValue = bagArray[x];
					return true;
				}
			}
			return false;
		}
	};

	// Inspect the top of the bag. If the bag is empty return false and leave 'item' unchaged.
	// Otherwise return true and update 'item' with the contents of the bag
	bool inspectTop(E& item) const
	{
		if (bagCS == 0)
			return false;
		else
		{
			item = bagArray[bagCS - 1];
			return true;
		}
	};

	// Empties the bag
	void emptyBag()
	{
		bagCS = 0;
	};

	// Use the += operator to add an item to the bag
	bool operator+=(const E& addend)
	{
		if (addItem(addend)) //Adding an item to the bag
			return true;
		else
			return false;
	};

	// Retrieve the number of items in the bag
	int size() const
	{
		return bagCS; // Returning current amount of items
	};

	// Retrieve the capacity of the bag
	int bagCapacity() const
	{
		return bagCP; // Returning bag capacity
	};

private:
	int bagCS;           // number of items the data array currently holds
	int bagCP;       // the number of items the bag can hold (size of array)
	std::unique_ptr<E[]> bagArray;            // an array of items
};


