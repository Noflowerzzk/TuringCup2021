#include <iostream>
#include <vector>

using namespace std;


class node {
public:
	vector<int> nodes;
	bool is;
	int indegree;

	node() :nodes{ vector<int>{} }, is{ false }, indegree{ 0 }{}

	inline void add(int i) {
		nodes.push_back(i);
	}

	inline void clear() {
		nodes.clear();
		indegree = 0;
	}
};

vector<int> list{};
vector<node> graph{};
int n;

bool ifeulercircuit(int i, int j) {
	int od = 0;


	for (int ii = i; ii <= j; ii++)
		for (int jj = ii + 1; jj <= j; jj++) {
			if (list[ii] < list[jj]) {
				graph[ii].add(jj);
				graph[jj].add(ii);
			}
		}

	for (int ij = i; ij <= j; ij++) {
		for (int e : graph[ij].nodes)
			if (e >= i && e <= j)
				graph[ij].indegree++;
		if (graph[ij].indegree % 2 == 1)
			od++;
	}

	for (int m = 0; m < n; m++)
		graph[m].clear();


	if (od == 0)
		return true;
	else
		return false;
}


int main()
{
	cin >> n;

	list.resize(n);
	graph.resize(n);
	cin.get();

	for (int i = 0; i < n; i++)
		cin >> list[i];

	//for (int i = 0; i < n; i++)
	//	for (int j = i + 1; j < n; j++) {
	//		if (list[i] < list[j]) {
	//			graph[i].add(j);
	//			graph[j].add(i);
	//		}
	//	}

	int ngood = 0;

	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++) {
			if (i == j)
				ngood++;
			else if (ifeulercircuit(i, j))
				ngood++;
		};

	cout << ngood;
	
	return 0;
}