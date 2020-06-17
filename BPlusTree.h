#ifndef BPLUSTREE_H
#define BPLUSTREE_H

#include "BPlusTreeNode.h"

class BPlusTree {

private:

	int order;
	BPTNode *root;

	BPTNode *RecursivelySearch (BPTNode *node, int key);
	void Destruction (BPTNode *node);

	void Show (BPTNode *node, bool showAll);

public:

	BPlusTree ();
	~BPlusTree ();

	void Display ();

	void Initialize (int m);
	void Insert (int key, float value);
	bool Search (int key, float &value);
	bool *Search (int key1, int key2, float *&values, int &num);
	void Delete (int key);


	bool insert();
	void search();
	bool remove();
	void getroot(){
	}
	void maketree();
	int putgloabltime(long gt);
	bool RL();
	bool RR();
	void PrintJobs(int val, int flag, ofstream &result);
	int TravRootnxt(int val, int flag, ofstream &result, int a);
	int TravRootprev(int val, int flag, ofstream &result, int a);
	void PrintJobRange(int start, int end,ofstream &result);
	int PrintJobRangecall(int start, int end, ofstream &result, int a);


};

#endif
