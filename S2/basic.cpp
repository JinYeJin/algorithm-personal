/*
*/
#include <stdio.h>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\\\input\\.txt", "r", stdin);
    if(!stream) perror("freopen");

    return 0;
}