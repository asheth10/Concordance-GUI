#pragma once
#include <cstdlib>
#include <string>
#include <iostream>
const size_t MAX = 8;
class concordance
{
public:
	typedef char word[MAX + 1];//what can go in concordance
	typedef size_t count;//number of words

	concordance() { first = NULL; }//default constructor
								   //post: concordance initialized to be empty

	//concordance(concordance source);//copy constructor
										   //post:the invoking concordance initialized as copy of source

	~concordance();//destructor

	void insert(word entry);
	//pre ::a word no longer than 8 characters
	//post::inserts the word in the invoking concordance

	size_t get_count(word w);
	//pre::a word
	//post::returns the count associated with the word in the invoking concordance

	std::size_t length();
	//post::returns the length of invoking concordance

	

//	friend std::ostream& operator<<(std::ostream& out_s, concordance c);
	//post:: concordance c written to out_s

private:
	struct Node
	{
		word w;//word
		count c;//count for the word
		Node *next;//pointer to the next word
	};
	Node *first;//pointer to the first word

	Node* get_node(word entry, Node* link, count counts);
	//post::returns a pointer to the new node with a word,count and pointer to next node
};

