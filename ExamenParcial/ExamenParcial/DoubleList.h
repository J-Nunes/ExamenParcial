#include <iostream>
#ifndef __DOUBLELIST_H__
#define __DOUBLELIST_H__


template<class TYPE>
struct doubleNode
{
	TYPE value;
	node<TYPE>* next;
	node<TYPE>* pervious;
};


template<class TYPE>
class Doublelist
{
private:
	doubleNode<TYPE>* start;

public:

	Doublelist()
	{
		start = NULL;
	}

	~Doublelist()
	{
		delAll();
	}


	void add(TYPE newNode)
	{
		node<TYPE>* newNode = new node;
		newNode->value = valor;
		newNode->next = NULL;
		newNode->pervious = NULL;

		if (start == NULL)
		{
			start = newNode;
		}

		else
		{
			node<TYPE>* tmp = start;

			while (tmp->next != NULL)
			{

				tmp = tmp->next;
				tmp->next = newNode;
			}
			tmp->next = newNode;
			newNode->previous = tmp;
		}
	}

	doubleNode<TYPE>* getNode(unsigned int position) const
	{
		if (start != NULL && position < count())
		{
			doubleNode<TYPE>* tmp = start;

			for (unsigned int i = 0; i < position; i++;)
			{
				tmp = tmp->next;
			}
			return tmp;
		}
		return NULL;
	}

	bool del(node<TYPE>* nodeToDelete)
	{
		if (nodeToDelete != NULL && start != NULL)
		{
			if (nodeToDelete != start)
			{
				node<TYPE>* tmp = start;


				while (tmp->next != nodeToDelete)
				{
					tmp = tmp->next;
					if (tmp->next == NULL)
					{
						return false;
					}
				}

				tmp->next = nodeToDelete->next;
				node<TYPE>* tmp2 = nodeToDelete;
				tmp2 = tmp2->next;
				tmp2->previous = tmp;
				delete nodeToDelete;
				return true;
			}
			else
			{
				start = start->next;
				delete DelNode;
				return true;
			}
		}
	}

	unsigned int Count() const
	{
		unsigned int counter = 0;
		node* tmp = start;

		if (start != NULL)
		{
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
				counter++;
			}
		}
		return counter;
	}

	void delAll()
	{
		if (start != NULL)
		{
			node<TYPE>* tmp = start;

			while (tmp->next != NULL)
			{
				node<TYPE>* tmp2 = tmp;
				tmp = tmp->next;
				delete tmp2;
			}
			delete tmp;
			start = NULL;
		}

		else{
			return false;
		}
	}
};

#endif