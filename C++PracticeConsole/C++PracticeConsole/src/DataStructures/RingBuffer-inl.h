#pragma once

#include <assert.h>
#include <intrin.h>
#include <math.h>

namespace DataStructures
{
	template<typename T>
	RingBuffer<T>::RingBuffer() : m_array(new T[ringBufferMaxCapacity]), m_maxCapacity(ringBufferMaxCapacity),
		m_writeHead(0), m_readHead(0)
	{
	}

	template<typename T>
	RingBuffer<T>::RingBuffer(size_t i_capacity) : m_writeHead(0), m_readHead(0)
	{
		size_t capacity;
		assert(i_capacity != 0 && "Tried to set Ring Buffer capacity to 0");
		if (i_capacity && !(i_capacity & (i_capacity - 1)))	//Still checking if i/p is 0 for future reference.
		{
			capacity = i_capacity;
		}
		else
		{
			unsigned long inputMSB;
			_BitScanReverse(&inputMSB, i_capacity);
			capacity = static_cast<size_t>(pow(2, inputMSB + 1));
		}
		m_array = new T[capacity];
		m_maxCapacity = capacity;
	}

	template<typename T>
	RingBuffer<T>::~RingBuffer()
	{
		delete[] m_array;
	}

	template<typename T>
	inline void RingBuffer<T>::Write(T element)
	{
		assert(!full());
		m_array[mask(m_writeHead++)] = element;
	}

	template<typename T>
	inline T RingBuffer<T>::Read()
	{
		assert(!empty());
		return m_array[mask(m_readHead++)];
	}

	template<typename T>
	inline bool const RingBuffer<T>::empty()
	{
		return m_readHead == m_writeHead;
	}

	template<typename T>
	inline bool const RingBuffer<T>::full()
	{
		return size() == m_maxCapacity;
	}

	template<typename T>
	inline size_t const RingBuffer<T>::size()
	{
		return m_writeHead - m_readHead;
	}

	template<typename T>
	inline size_t const RingBuffer<T>::mask(size_t index)
	{
		return index & (m_maxCapacity - 1);
	}

	template<typename T>
	inline size_t const RingBuffer<T>::GetReadIndex()
	{
		return mask(m_readHead);
	}

	template<typename T>
	inline size_t const RingBuffer<T>::GetWriteIndex()
	{
		return mask(m_writeHead);
	}
}
