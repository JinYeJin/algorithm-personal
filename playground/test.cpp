#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

vector<string> v;
bool check(string a, string b) {
	vector<char> vv[26]; // a꺼
    vector<char> vv2[26]; // b꺼
	for (int i = 0; i < a.size(); ++i) {
		if (vv[a[i] - 'a'].size() > 0 || vv2[b[i] - 'a'].size() > 0) { //존재한다면
			if (vv[a[i] - 'a'].size() > 0 && vv[a[i] - 'a'][0] != b[i]) {
				return false;
			}
			else if (vv2[b[i] - 'a'].size() > 0 && vv2[b[i] - 'a'][0] != a[i]) {
				return false;
			}
		}
		else {//존재하지 않는다면
			vv[a[i] - 'a'].push_back(b[i]);
			vv2[b[i] - 'a'].push_back(a[i]);
		}
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	int cnt = 0;
	for (int i = 0; i < v.size() - 1; ++i) {//0 1 2 3 4
		for (int j = i + 1; j < v.size(); ++j) {//1 2 3 4
			if (check(v[i], v[j])) {
				//cout << v[i] << ", " << v[j] << endl;
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}