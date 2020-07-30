/*
*/
#include <stdio.h>

using namespace std;

int main(){
    FILE *stream =freopen("s2\\9\\input\\1654_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    return 0;
}