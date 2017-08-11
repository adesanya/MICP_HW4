#include<iostream>
#include<fstream>
#include<string>

using namespace std;



struct wordTree
{
	string value;
	wordTree * left;
	wordTree * right;
	wordTree(string word,wordTree * l,wordTree * r)
	:value{word},left{l},right{r}
	{}
};

bool find(wordTree * T,string word)
{
    if(T==nullptr)
    {   
        return false;
    }
    if(T->value== word)
    {   
        return true;
    }
    else
    {   
        if(word>T->value)
        {   
            find(T->right,word);
        }
        else
        {   
            find(T->left,word);
        }
    }
}


void insert(wordTree * T,string word)
{
	if(T==nullptr)
	{
		cout<<"isnull";
		T=new wordTree(word,nullptr,nullptr);
		return;
	}
	else
	{
		if(word>T->value)
		{
			if(T->right!=nullptr)
			{	
				insert(T->right,word);
			}
			else
			{
				T->right=new wordTree(word,nullptr,nullptr);
				cout<<"R "<<word<<endl;
			}
		}
		else
		{
			if(T->left!=nullptr)
			{
				insert(T->left,word);
			}
			else
			{
				T->left=new wordTree(word,nullptr,nullptr);
				cout<<"L "<<word<<endl;
			}
		}
	}
}

void printTree(wordTree * T)
{
	if(T!= nullptr)	
	{
		cout<<T->value<<endl;
		printTree(T->left);
		printTree(T->right);

	}
	return;
}

int main()
{
	ifstream File("/usr/share/dict/words");
	string word;
	wordTree * Dictonary=new wordTree("O",nullptr,nullptr);
	while(File>>word)
	{
		insert(Dictonary,word);
	}
//	printTree(Dictonary);
	cout<< Dictonary->value;
	return 0;
}



;
