#ifndef BPLUSTREENODE_H
#define BPLUSTREENODE_H

#include <cstddef>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <cstdlib>

#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

class BPTNode {

protected:

	int order;
	int *keys;
	int keyNum;

	bool isLeaf;

	BPTNode *parent;

	BPTNode *prev;
	BPTNode *next;
	int *arr;
	int total_size;
	int current_count;

public:

	BPTNode (int n);
	~BPTNode ();

	bool IsLeaf ();
	int *GetKeys ();
	int GetKeyNum ();
	void DecreaseKeyNum ();
	int GetKeyIndex (int key);
	BPTNode *GetParent ();
	void SetParent (BPTNode *node);
	BPTNode *GetNext ();
	void SetNext (BPTNode *node);
	BPTNode *GetPrev ();
	void SetPrev (BPTNode *node);




	int ins(int data);
	int del(int data){
		return 1;
	}
	int Heapify();
	int resize();
	int getcursize()
	{
		return current_count;
	}
	int gettotalelements(){
		return current_count;
	}
	int puttotalelements(int val){
		current_count = val;
		return 1;
	}




	virtual void Insert (int key, float value) {}
	virtual void Insert (int key, BPTNode* rightChild) {}
	virtual void Insert (int key, BPTNode* leftChild, BPTNode* rightChild) {}
	virtual void Search (int key) {}
	virtual void Search (int key1, int key2) {}
	virtual void Delete (int key) {}
	virtual void Merge (BPTNode* rightNode) {}
	virtual BPTNode *Split(int &key) { return NULL; }
	virtual BPTNode **GetChildren () { return NULL; }
	virtual float *GetValues () { return NULL; }

};


// internal node
class InternalNode : public BPTNode {

private:

	BPTNode **children;

public:

	InternalNode (int n);
	~InternalNode ();

	void Insert (int key, BPTNode* rightChild);
	void Insert (int key, BPTNode* leftChild, BPTNode* rightChild);
	void Delete (int key);
	void Merge (BPTNode* rightNode);
	BPTNode *Split (int &key);
	BPTNode **GetChildren ();

};


// leaf node
class LeafNode : public BPTNode {

private:

	float *values;



public:

	LeafNode (int n);
	~LeafNode ();

	void Insert (int key, float value);
	void Delete (int key);
	void Merge (BPTNode* rightNode);
	BPTNode *Split (int &key);
	float *GetValues ();


};

#endif
