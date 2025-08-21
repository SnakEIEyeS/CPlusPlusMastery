#include "HashTable.h"

static size_t defaultTableSize = 31;

HashTableEntry::HashTableEntry()
{
}

HashTableEntry::HashTableEntry(unsigned int key, int value) : m_hashKey(key), m_value(value)
{
}

HashTableEntry::~HashTableEntry()
{
}

HashTable::HashTable() : m_entryList(std::vector<HashTableEntry*>(defaultTableSize, nullptr)), m_tableSize(defaultTableSize), m_numEntries(0)
{
	//m_entryList.reserve(defaultTableSize);
}

HashTable::HashTable(size_t tableSize) : m_entryList(std::vector<HashTableEntry*>(tableSize, nullptr)),  m_tableSize(tableSize), m_numEntries(0)
{
	//m_entryList.reserve(tableSize);
}

HashTable::~HashTable()
{
	for (HashTableEntry* tableEntry : m_entryList)
	{
		delete tableEntry;
	}
	m_entryList.clear();
}

bool HashTable::Insert(int value)
{
	if (m_numEntries >= m_tableSize)
	{
		return false;
	}

	unsigned int hashKey = Hash(value);
	HashTableEntry* pEntry = new HashTableEntry(hashKey, value);
	size_t index = hashKey % m_tableSize;
	while (m_entryList[index] != nullptr)
	{
		++index;
		index %= m_tableSize;
	}
	m_entryList[index] = pEntry;
	++m_numEntries;
	return true;
}

int HashTable::Search(int value)
{
	unsigned int hashKey = Hash(value);
	size_t index = hashKey % m_tableSize;
	size_t i = 0;
	do
	{
		HashTableEntry* pEntry = m_entryList[index];
		if (pEntry && pEntry->m_hashKey == hashKey
			&& pEntry->m_value == value) //TODO SHMANE not sure whether last check needed. Confirm.
		{
			return index;
		}
		++index;
		index %= m_tableSize;
		++i;
	} while (i < m_tableSize);
	return -1;
}

bool HashTable::Remove(int value)
{
	int numDeleted = 0;
	while (true)
	{
		int index = Search(value);
		if (index > -1)
		{
			HashTableEntry* pEntry = m_entryList[index];
			m_entryList[index] = nullptr;
			delete pEntry;
			--m_numEntries;
			++numDeleted;
		}
		else
		{
			break;
		}
	}

	if (numDeleted > 0)
	{
		return true;
	}

	return false;
}

unsigned int HashTable::Hash(int value)
{
	unsigned int hash = static_cast<unsigned int>(value) % m_tableSize;
	return hash;
}
