#pragma once

#include <vector>

class HashTableEntry
{
public:
	HashTableEntry();
	HashTableEntry(unsigned int key, int value);
	~HashTableEntry();

	unsigned int m_hashKey;
	int m_value;
};

class HashTable
{
public:
	enum kAddressingMode
	{
		AM_Open
	};

	enum kHashMode
	{
		HM_Linear
	};

	HashTable();
	HashTable(size_t tableSize);
	~HashTable();

	bool Insert(int value);
	int Search(int value);
	bool Remove(int value);

private:
	unsigned int Hash(int value);

	std::vector<HashTableEntry*> m_entryList;
	size_t m_tableSize;
	size_t m_numEntries;
};
