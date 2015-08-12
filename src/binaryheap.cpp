#include "binaryheap.h"
#include "gameevent.h"
#include <utility>
namespace lib
{
	template <class T>
	binaryheap<T>::binaryheap()
	{

	}

	template <class T>
	void binaryheap<T>::add(T t)
	{
		int pos = array.size();
		array.push_back(t);
		while (array[pos] < array[(pos - 1)/2])
		{
			std::swap(array[pos], array[(pos - 1) / 2]);
			pos = (pos -1)/2;
		}
	}

	template <class T>
	T binaryheap<T>::extractmin()
	{
		int pos = array.size() - 1;
		int newpos = 0;
		T res = array.front();
		do 
		{
			std::swap(array[pos], array[newpos]);
			pos = newpos;
			if (array[pos * 2 + 1] < array[newpos])
				newpos = pos * 2 + 1;
			if (array[pos * 2 + 2] < array[newpos])
				newpos = pos * 2 + 2
		} while (newpos != pos);
		return res;
	}
	template class binaryheap<game_event>;
}
