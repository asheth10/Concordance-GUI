#include "concordance.h"
#include<cstring>
#include <string>
#include <iomanip>

	/**concordance::concordance(concordance source)//copy constructor
	{
		Node *p;//to move through the concordance
		Node *last;//always point to the last node
		if (source.first == NULL)//if the concordance is empty
		{
			first = NULL;
		}
		else
		{
			first = get_node(source.first->w, NULL, 1);//copy the first node
			last = first;
			p = source.first->next;
			while (p != NULL)//to copy remaining nodes
			{
				last->next = get_node(p->w, NULL, p->c);
				last = last->next;
				p = p->next;
			}
		}
	}/**/

	concordance::~concordance()//destructor
	{
		Node *temp;
		while (first != NULL)
		{
			temp = first;
			first = first->next;
			delete temp;
		}
	}

	void concordance::insert(word entry)
	{
		Node *prev;//to move through the list
		size_t coun;
		if (first == NULL || strcmp(entry, first->w)<0)//if the concordance is empty or entry less than the first word
			first = get_node(entry, first, 1);//first assigned pointer to new node with entry
		else
		{
			prev = first;
			while (prev->next != NULL&&strcmp(prev->next->w, entry) <= 0)//if entry is not greater than a word in the concordance
				prev = prev->next;
			if (strcmp(prev->w, entry) == 0)//if word is present in the concordance
				prev->c += 1;//increment count
			else
				prev->next = get_node(entry, prev->next, 1);//if entry greater than any word in the concordance
		}
	}

	size_t concordance::get_count(word entry)
	{
		Node *cursor;//to move through the list
		for (cursor = first; cursor != NULL; cursor = cursor->next)
		{
			if (strcmp(entry, cursor->w) == 0)//if word in the node is the entry
				return cursor->c;//return the count associated with the word
		}
		return 0;//else, return 0
	}

	size_t concordance::length()
	{
		Node *cursor;//to move through the list
		size_t len;
		len = 0;
		for (cursor = first; cursor != NULL; cursor = cursor->next)
			++len;
		return len;
	}
	

/**	ostream& operator<<(std::ostream& out_s,concordance c)
	{
		concordance::Node *cursor;
		out_s << setw(17) << left << "Word" << "Count" << endl;
		out_s << "----------------------" << endl;
		for (cursor = c.first;cursor->next != NULL;cursor = cursor->next)
		{
			out_s << setw(18) << left << cursor->w << cursor->c << endl;
		}
		if (cursor != NULL)
		{
			out_s << setw(18) << left << cursor->w << cursor->c << endl;
		}
		out_s << "----------------------" << endl;
		return out_s;
	}/**/

	concordance::Node* concordance::get_node(word entry, Node* link, count counts)
	{
		Node *temp;
		temp = new Node;
		strcpy(temp->w, entry);
		temp->next = link;
		temp->c = counts;
		return temp;
	}




