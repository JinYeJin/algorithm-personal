
/*
*/
#include <stdio.h>
#include <iostream> 

using namespace std;

int main(){
    FILE *stream =freopen("S2\\\\input\\.txt", "r", stdin);
    if(!stream) perror("freopen");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);



    return 0;
}