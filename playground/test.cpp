#include <iostream>

using namespace std;

int x = 8;
int ans = 0;

int main(){
	while(x!=0){
		x = x/2;
		ans++;
	}

	printf("%d", ans);
	return 0;
}