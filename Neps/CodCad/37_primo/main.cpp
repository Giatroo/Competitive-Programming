#include <iostream>

using namespace std;

bool eh_primo(int x){
    if(x <= 2)
        return true;
	for(int i = 2; i < x-1; i++)
        if(x % i == 0)
            return false;
    return true;
}

int main(){
	int x;

	cin>>x;

	if(eh_primo(x)){
		cout<<"S"<<"\n";
	}else{
		cout<<"N"<<"\n";
	}
}
