#include<string>
#include<stdlib.h>
#include<iostream>
int main(int argn,char **arg){	std::string ar= arg[1];
	std::string op[10];
	std::string intap[50];
	int r,j,e;
	for(r=1,j=0,e=0;r<argn;r++){
		if(arg[r][0]=='-') {op[j]=arg[r];j++;}
		else {intap[e]=arg[r];e++;}
	}
	std::string a,c="g++ -o exec/"+ar+" bin/"+ar+".cpp";
	for(j--;j>=0;j--){
	c+=" "+op[j];
	}
	std::cout<<"\n**************************************************************\n";
	int re = system(c.c_str());
	if ( re == 0 ){
	 // c = "notify-send \"Build done\" \""+ar+" Build successful\"";      -previous implementation
		std::cout<<"\n**************************************************************\n";
		std::cout<<ar+" Build successful\n";
		std::cout<<"**************************************************************\n\n^\n";
		std::cout.flush();
	    c = "./exec/"+ar;
	    for(int i=1;i<e;i++){
	        c += " "+intap[i];
	    }
		system(c.c_str());
	}
	else
		exit(0);
}