#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Interviewer
{
    vector<char> name;
    int score;
}Interviewer;

bool cmp(const Interviewer a, const Interviewer b){
    return a.score < b.score;
}

int main(){
    int T, num, name_length;
    char temp_char, temp_score;
    Interviewer temp_interviwer;
    vector<char> temp_vec;
    vector<Interviewer> interviewers(10);

    FILE *stream;
    stream = freopen("SWEA\\16\\4223_input.txt", "r", stdin);
    if(!stream)
        printf("freopen");

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

        sort(interviewers.begin(), interviewers.end(), cmp);

        for(int i = 0; i < interviewers.size(); i++){
            
        }
    }
    return 0;
}