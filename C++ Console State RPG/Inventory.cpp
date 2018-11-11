#include "Inventory.h"

//Private functions

void Inventory::initialize(const unsigned from)
{
	for (size_t i = from; i < this->cap; i++)
	{
		this->items[i] = nullptr;
	}
}

void Inventory::expand()
{
	this->cap *= 2;

	Item** temp = new Item*[this->cap];

	for (size_t i = 0; i < this->nrOfItems; i++)
	{
		temp[i] = this->items[i];
	}

	delete[] this->items;

	this->items = temp;

	this->initialize(this->nrOfItems);
}

//Constructor / Destructors
Inventory::Inventory(unsigned cap)
{
	this->cap = cap;
	this->nrOfItems = 0;
	this->items = new Item*[cap];

	this->initialize();
}

Inventory::Inventory(const Inventory& other)
{
	this->cap = other.cap;
	this->nrOfItems = other.nrOfItems;

	this->items = new Item*[this->cap];

	this->initialize();

	for (size_t i = 0; i < this->nrOfItems; i++)
	{
		this->items[i] = new Item(*other.items[i]);
	}
}

Inventory::~Inventory()
{
	for (size_t i = 0; i < this->nrOfItems; i++)
	{
		delete this->items[i];
	}

	delete [] this->items;
}

//Operators
void Inventory::operator=(const Inventory& other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < this->nrOfItems; i++)
		{
			delete this->items[i];
		}
		delete[] this->items;

		this->cap = other.cap;
		this->nrOfItems = other.nrOfItems;

		this->items = new Item*[this->cap];

		this->initialize();

		for (size_t i = 0; i < this->nrOfItems; i++)
		{
			this->items[i] = new Item(*other.items[i]);
		}
	}
}

Item& Inventory::operator[](const unsigned index)
{
	if (index < 0 || index >= this->nrOfItems)
	{
		throw("OUT OF BOUNDS!");
	}

	return *this->items[index];
}

//Accessors
const unsigned & Inventory::size() const
{
	return this->nrOfItems;
}

const unsigned & Inventory::capacity() const
{
	return this->cap;
}

Item & Inventory::at(const unsigned index)
{
	if (index < 0 || index >= this->nrOfItems)
	{
		throw("OUT OF BOUNDS!");
	}

	return *this->items[index];
}

//Functions
void Inventory::add(const Item & item)
{
	if (this->nrOfItems >= this->cap)
		this->expand();

	this->items[this->nrOfItems++] = new Item(item);
}

void Inventory::remove(const unsigned index)
{

}

std::string Inventory::toString() const
{
	std::stringstream ss;

	for (size_t i = 0; i < this->nrOfItems; i++)
	{
		ss << i << ": " << this->items[i]->toString() << "\n";
	}

	return ss.str();
}