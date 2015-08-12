#pragma once
#include <vector>
namespace lib
{
	template<class T>
	class binaryheap
	{
	private:
		std::vector<T> array;
	public:
		binaryheap();
		void add (T);
		T extractmin();
	};
}