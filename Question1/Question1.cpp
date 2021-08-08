#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

stack <pair<int, char>> stk;
// vector <pair<int, int>> vct;
int n, p;

int main()
{
	cin >> n;
	cin >> p;

	char ch;
	int output;

	cin.get();

	for (int i = 1; i <= n; i++) {
		cin.get(ch);

		if (stk.empty()) {
			stk.push(pair<int, char>{i, ch});
			continue;
		}
		else if (stk.top().second == '{' && ch == '}') {

			if (stk.top().first == p) {
				// cout << static_cast<char>(i);
				// printf("%d", i);
				// return 0;
				output = i;
				break;
			}
			else if (i == p) {
				// cout << static_cast<char>(stk.top().first);
				// printf("%d", stk.top().first);
				// return 0;
				output = stk.top().first;
				break;
			}
			else
				stk.pop();
		}
		else
			stk.push(pair<int, char>{i, ch});
	}

	cout << output;


	return 0;
}