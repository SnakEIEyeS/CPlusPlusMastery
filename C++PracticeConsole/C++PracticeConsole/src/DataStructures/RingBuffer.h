#pragma once

namespace DataStructures
{
	template<typename T>
	class RingBuffer
	{
	public:
		RingBuffer();
		RingBuffer(size_t i_capacity);
		~RingBuffer();

		inline void Write(T element);
		inline T Read();

		inline bool const empty();
		inline bool const full();
		inline size_t const size();

		inline size_t const mask(size_t index);

		inline size_t const GetReadIndex();
		inline size_t const GetWriteIndex();

	private:
		static const int ringBufferMaxCapacity = 64;
		
		T* m_array;
		size_t m_writeHead;
		size_t m_readHead;
		size_t m_maxCapacity;
	};
}

#include "RingBuffer-inl.h"
