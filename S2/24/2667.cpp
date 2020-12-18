#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    FILE *stream =freopen("S2\\\\input\\.txt", "r", stdin);
    if(!stream) perror("freopen");

    int N;
    int arr[100];

    scanf("%d", &N);

    sort(arr, arr+N);

    return 0;
}