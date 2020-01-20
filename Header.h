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

	MyList(int);
	MyList(const Node<Type>* node);
	~MyList();

	Node<Type>* get_last();
	void add_back(Type item);
	void delete_node(Type item);
	void print();
	void delete_list();
	Node<Type>* find(Type item);
};





#endif
