#pragma once
#ifndef Header
#define Header
template <typename Type>

struct Node
{
	Type item;
	Node<Type>* next;
};

template <typename Type>

class MyList {
	int counter;
	int size;
	Node<Type>* root;

public:

	MyList();
	MyList(const Node<Type>* node);
	~MyList();

	Node<Type>* getLast();
	void Add_back(Type item);
	void Delete(Type item);
	void Print();
	void DeleteList();
	Node<Type>* Find(Type item);
};





#endif
