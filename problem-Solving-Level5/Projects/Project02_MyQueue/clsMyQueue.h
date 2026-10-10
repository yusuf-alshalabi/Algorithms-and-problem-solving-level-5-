#pragma once

#include <iostream>
#include "../Project01_DoublyLinkedList/clsDblLinkedList.h"


using namespace std;
template <class T>

class clsMyQueue
{

protected:
	clsDblLinkedList <T> _MyList;

public:

	void push(T Item)
	{
		_MyList.InsertAtEnd(Item);
	}


	void pop()
	{
		_MyList.DeleteFirstNode();
	}

	void Print()
	{
		_MyList.PrintList();
	}

	int Size()
	{
		return _MyList.Size();
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	T front()
	{
		return _MyList.GetItem(0);
	}

	T back()
	{
		return _MyList.GetItem(Size() - 1);
	}

	// Extension 1 
	T GetItem(int Index)
	{
		return _MyList.GetItem(Index);
	}

	// Extension 2 
	void Reverse()
	{
		_MyList.Reverse();
	}

	// Extension 3 
	bool UpdateItem(int Index, T NewValue)
	{
		return _MyList.UpdateItem(Index, NewValue);
	}

	// Extension 4
	void InsertAfter(int Index, T NewValue)
	{
		_MyList.InsertAfter(Index, NewValue);
	}

	// Extension 5
	void InsertAtFront(T NewValue)
	{
		_MyList.InsertAtBeginning(NewValue);
	}

	// Extension 6 
	void InsertAtBack(T NewValue)
	{
		_MyList.InsertAtEnd(NewValue);
	}

	// Extension 7
	void Clear()
	{
		_MyList.Clear();
	}

};


