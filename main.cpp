#include "BPlusTree.h"

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;


const string OUTPUT_FILE ("output_file.txt");


int main (int argc, char **argv) {


	int flag = 0;

	if(flag == 1)
{



	ifstream check;
	ofstream result;

	char cmdins[]="Insert";
	char cmdprint[]="PrintJob";
	char cmdnxt[]="NextJob";
	char cmdprev[]="PreviousJob";
	char delim[]=" ,():";
	char *token;
	string *str;
	streampos oldpos;
	char *cstr1;

	here:
	str= new string();
	oldpos = check.tellg();





	getline (check,*str);

	cstr1=new char[str->length()];

	strcpy(cstr1,str->c_str());

	if((token=strtok(cstr1, delim))==NULL)
	{
			return oldpos;
	}




	if(atoi(token)==0){


			token=strtok(NULL, delim);
			//cout<<token;

			if(strcmp(token,cmdins)==0)
			{

					//cout<< " this count";
				 token=strtok(NULL, delim);





					token=strtok(NULL, delim);

					//cout<<"\n last val"<<token<<endl;




		 }
			else if(strcmp(token,cmdprint)==0)
			{
					token=strtok(NULL, delim);
					if((token=strtok(NULL, delim))==NULL)
					{

					if(0!=0)
					{

					}

					}
					else
					{

							int end=atoi(token);

					}

			}
			else if(strcmp(token,cmdnxt)==0)
			{
					token=strtok(NULL, delim);
					int param=atoi(token);
					//rbtnode * temp= new rbtnode();

//            while(temp!=NULL)
//            {
//                if(temp->jobID<=param)
//                {
//                    temp=temp->right;
//                    //cout<<"something";
//                }
//
//            }

			}
			else if(strcmp(token,cmdprev)==0)
			{
					token=strtok(NULL, delim);
					int param=atoi(token);
					//rbtnode * temp= new rbtnode();

//            while(temp!=NULL)
//            {
//                if(temp->jobID<=param)
//                {
//                    temp=temp->right;
//                    //cout<<"something";
//                }
//
//            }

			}
			else
			{
			}




	}



	else
	{


	}





	//check.close();














	// old code for input.txt





//    int inputstream;
//    //rbtnode *a = new rbtnode();
//
//
//
//
//
//
//    label:
//
//    rbtnode *a = new rbtnode();
//
//
//
//    tasklist >> inputstream;
//
//    a->jobID=inputstream;
//
//    tasklist >> inputstream;
//
//    a->total_time=inputstream;
//
//    a->executed_time=0;
//
//    a->rem_time=a->total_time-a->executed_time;
//
//    b.executed_time=a->executed_time;
//
//
//
//
//
//    a->ptr=NULL;
//
//    joblist.insert(a);
//
//    b.ptr=joblist.search(a);
//
//
//
//    //joblist.insert(a);
//
//    scheduler.Insert(b);
//
//
//
//    //delete a;
//
//
//    if(tasklist.eof()!=1)
//    tasklist >> inputstream;
//    else
//        return -1;
//
//
//    if(inputstream==0)
//        goto label;
//    else
//        return inputstream;


}


	if (argc != 2) {

		cout << "Please enter the name of the input file!" << endl;
		exit (-1);

	}

	ifstream in (argv[1]);
	ofstream out (OUTPUT_FILE.c_str ());

	int i = 0;

	string line;
	string command;
	string data;

	BPlusTree tree;

	while (!in.eof ()) {

		i++;
		getline (in, line);

		// cout << line << endl;

		command = line.substr(0, line.find('('));
		data = line.substr(line.find('(') + 1, line.find(')') - line.find('(') - 1);

		// cout << command << endl;
		// cout << data << endl;

		if (command.compare ("Initialize") == 0) {

			int order = stoi(data);

			tree.Initialize (order);

		} else if (command.compare ("Insert") == 0) {

			int key = stoi (data.substr(0, data.find(',')));
			float val = stof (data.substr(data.find(',') + 1, data.length() - data.find(',')));

			tree.Insert (key, val);

		} else if (command.compare ("Delete") == 0) {

			int key = stoi (data);

			tree.Delete (key);

		} else if (command.compare ("Search") == 0) {

			if (data.find(',') != string::npos) {

				int num;
				bool *flags;
				float *vals;

				int key1 = stoi (data.substr(0, data.find(',')));
				int key2 = stoi (data.substr(data.find(',') + 1, data.length() - data.find(',')));

				flags = tree.Search (key1, key2, vals, num);

				if (!flags[0]) {

					out << ", ";

				}

				for (int i = 0; i < num; i++) {

					out << vals[i];
					if (i != num - 1) out << ", ";

				}

				if (!flags[1]) {

					out << ", ";

				}

				out << endl;

			} else {

				float val;

				int key = stoi (data);

				if (tree.Search (key, val)) {

					out << val << endl;

				} else {

					out << "" << endl;

				}

			}

		} else {

			out << "Command not recognized " << i << endl;

		}

	}

	in.close ();
	out.close ();

	return 0;

}
