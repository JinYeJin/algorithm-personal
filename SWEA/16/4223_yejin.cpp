#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;

typedef struct Interviewer{
    vector<char> name;
    int score;
}Interviewer;

int T, num, name_length;
char temp_char, temp_score;
char check[30], samsung[30];
Interviewer temp_interviwer;
vector<char> temp_vec;
vector<Interviewer> interviewers(10);

int dfs(){

}

int main(){
    FILE *stream;
    stream = freopen("SWEA\\16\\4223_input.txt", "r", stdin);
    if(!stream)
        printf("freopen");

    char tmp[10] = { "SAMSUNG" };
    for (int i = 0; i < strlen(tmp); i++)
        samsung[tmp[i] - 'A'] ++;

    scanf("%d", &T);
    for(int testcase = 1; testcase <T; testcase++){
        scanf("%d", num);

        for(int i = 0; i < num; i++){
            scanf("%d", &name_length);

            for(int j = 0; j < name_length; j++){
                scanf("%d", temp_char);
                temp_vec.push_back(temp_char);
            }

            scanf("%d",&temp_score);
            temp_interviwer.name = temp_vec;
            temp_interviwer.score = temp_score;
            interviewers.push_back(temp_interviwer);
        }



    }
    return 0;
}