#ifndef CORE_HPP
#define CORE_HPP
#include <iostream>
#include <string>
#include <iterator>
using namespace std;
//expression object...
struct expr{
	char Char;
	double num;

	expr(){ Char = -1; num = -1; }

	//sets Char to symbol/digit. if digit, set num to numeric representation
	expr(char a){ Char = a;
	if (a >= 48 || a <= 57)
	{
		num = a - 48;
	}
	else
		num = -1;
	}
	//
	expr(double a){  num = a; }
	
};
//node. expr value + left&right children
struct node{ 
	expr* value;
	node* left = NULL;
	node* right = NULL;
	node(expr* a){ value = a; }
	node(char a){ value = new expr(a); }

};
struct tree{
	node* root=NULL;
	tree(){	root = NULL;};
tree(char a){ root = new node(a); }
};
tree* ast(string a){
	if (a.length() % 2 == 0||a.empty()== true){
		cout << "invalid sequence length"<<endl; return NULL;
	}
	else if (a.length() == 1)
		return new tree(a[0]);
	string::iterator it = a.begin()+a.length()-1;
	string::iterator it2 = a.begin() + a.length() - 2;
	tree* b = new tree(*it2);
	b->root->right = new node(*it);
	node* temp = b->root;
	for (it2; it2 != a.begin()+1; it2+0 )
	{
		advance(it2, -2);
		temp->left = new node(*it2);
		temp = temp->left;
		advance(it, -2);
		temp->right = new node(*it);
	}
	advance(it2, -1);
	temp->left = new node(*it2);
	
	return b;
	
	
}

//remove whitespace
string WSR(string& str)
{
	for (int i = 0; i < str.length(); i++){
		if (str[i] == ' ') str.erase(i, 1);
		
	}
	return str;
}
void PRINT(node* a)
{
	if (a->left == NULL || a->right == NULL)
	{
		cout << "leaf: " << a->value->Char << endl; return;
	}
	cout << "current: " << a->value->Char << "____left: " << a->left->value->Char << "____right: " << a->right->value->Char << endl;
	PRINT(a->left);
	PRINT(a->right);
}

#endif