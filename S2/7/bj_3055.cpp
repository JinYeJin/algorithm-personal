/*
2020-07-13 진예진
[백준 3055 탈출] https://www.acmicpc.net/problem/3055
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct Coord{
    Coord(int x, int y): x(x), y(y) {}
    int x, y;
}Coord;

char map[50][50];
int r, c;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
queue<Coord> water;
queue<Coord> hedgehog;


int main(){
    FILE *stream = freopen("S2\\7\\input\\3055_input.txt", "r", stdin);
    if(!stream) perror("freopen");

    int R, C;
    vector<vector<string>> map(50, vector<string>(50, 0));

    scanf("%d %d", &R, &C);
    scanf("%c", &map)

    return 0;
}
 
void solve() {
    r = sc.nextInt();
    c = sc.nextInt();
    map = new char[r][c];
 
    for (int i = 0; i < r; i++) {
        char[] input = sc.next().toCharArray();
        for (int j = 0; j < c; j++) {
            map[i][j] = input[j];
 
            if (input[j] == '*') {
                water.add(new Coord(i, j));
            }
 
            if (input[j] == 'S') {
                hedgehog.add(new Coord(i, j));
            }
        }
    }
 
    int ans = 0;
    while (true) {
        ++ans;
        if (hedgehog.size() == 0) {
            System.out.println("KAKTUS");
            return;
        }
 
        extendWater();
        if (extendHedgehog()) {
            System.out.println(ans);
            return;
        }
    }
}
 
public static void extendWater() {
    int size = water.size();
 
    for (int i = 0; i < size; i++) {
        Coord p = water.poll();
 
        for (int j = 0; j < 4; j++) {
            int nx = dx[j] + p.x;
            int ny = dy[j] + p.y;
 
            if (0 <= nx && nx < c && 0 <= ny && ny < r) {
                if (map[ny][nx] == '.') {
                    map[ny][nx] = '*';
                    water.add(new Coord(ny, nx));
                }
            }
        }
    }
}
 
public static boolean extendHedgehog() {
    int size = hedgehog.size();
 
    for (int i = 0; i < size; i++) {
        Coord p = hedgehog.poll();
 
        for (int j = 0; j < 4; j++) {
            int nx = dx[j] + p.x;
            int ny = dy[j] + p.y;
 
            if (0 <= nx && nx < c && 0 <= ny && ny < r) {
                if (map[ny][nx] == 'D') {
                    hedgehog.add(new Coord(ny, nx));
                    return true;
                }
                if (map[ny][nx] == '.') {
                    map[ny][nx] = 'S';
                    hedgehog.add(new Coord(ny, nx));
                }
            }
        }
    }
    return false;
}
 
