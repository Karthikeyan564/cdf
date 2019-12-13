#include<string>
#include<stdlib.h>
#include<iostream>
struct node{
	std::string info;
	node *next;
};
template <class T,class M> class stack{
    public:
    	void push(T* &top,M ele){
    		T* temp;
    		temp = new T;
    		temp->info = ele;
    		temp->next = top;
    		top = temp;
    	}
    	M pop(T* &top){
    		T* temp;
    		temp = top;
    		M con=top->info;
    		top = top->next;
    		free(temp);
    		return con;
    	}
};
int main(int argn,char **arg){
	node* top1 = nullptr , * top2= nullptr;
	stack<node,std::string> op;
	stack<node,std::string> intap;
	int r;
	std::string tem;
	std::string ar = arg[1];
	for(r=2;r<argn;r++){
        tem = arg[r];
		if(arg[r][0]=='-') op.push(top1,tem);
		else intap.push(top2,tem);
	}
	std::string a,c="g++ -o ../exec/"+ar+" ../bin/"+ar+".cpp";
	while ( top1!=nullptr ){
	    a=op.pop(top1)+" "+a;
	}
	c+=" "+a;
	std::cout<<"\n**************************************************************\n";
	int re = system(c.c_str());
	if ( re == 0 ){
	 // c = "notify-send \"Build done\" \""+ar+" Build successful\"";      -previous implementation
		std::cout<<"\n**************************************************************\n";
		std::cout<<ar+" Build successful\n";
		std::cout<<"**************************************************************\n\n^\n";
		std::cout.flush();
	    c = "./../exec/"+ar;
	    while ( top2!=nullptr ){
	        a =intap.pop(top2)+" "+a;
	    }
	    c+=" "+a;
		system(c.c_str());
	}
	else
		exit(0);
	return 0;
}