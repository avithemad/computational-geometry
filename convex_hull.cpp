#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool goesright(vector<pair<int, int> > &points, int next_index, int p1, int base) {
	// x1y2 - x2y1, get the cross product
	int x1 = points[base].first - points[p1].first;
	int x2 = points[base].first - points[next_index].first;
	int y1 = points[base].second - points[p1].second;
	int y2 = points[base].second - points[next_index].second;

	int cross = x1*y2 - x2*y1;
	return cross < 0;
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int> > points;
	for (int i=0; i<n; i++) {
		pair<int, int> p;
		cin >> p.first >> p.second;
		points.push_back(p);
	}

	// Jarvis march algorithm based on the x co-ordinates
	// Sort the points based on the x-axis first
	sort(points.begin(), points.end());

	// vector to keep track of the included points
	stack<int> included;

	// add the first 2 elements
	included.push(0);
	included.push(1);

	for (int i=2; i<n; i++) {
		// if the direction goes to the right, keep on going
		int p1 = included.top(); included.pop();
		int p2 = included.top(); included.push(p1);
		if (goesright(points, i, p1, p2)) {
			included.push(i);
		} else {
			// back track until you find a point that goes right
			while(included.size()>=2 && !goesright(points, i, p1, p2)) {
				included.pop();
				// if stack size is one, then add i and break the loop
				if (included.size() == 1) {
					break;
				}
				p1 = included.top();
				included.pop();
				p2 = included.top();
				included.push(p1);
			}
			included.push(i);
		}
	}
// vector to keep track of the included points
	stack<int> included1;

	// add the first 2 elements
	included1.push(0);
	included1.push(1);

	for (int i=2; i<n; i++) {
		// if the direction goes to the right, keep on going
		int p1 = included1.top(); included1.pop();
		int p2 = included1.top(); included1.push(p1);
		if (!goesright(points, i, p1, p2)) {
			included1.push(i);
		} else {
			// back track until you find a point that goes right
			while(included1.size()>=2 && goesright(points, i, p1, p2)) {
				included1.pop();
				// if stack size is one, then add i and break the loop
				if (included1.size() == 1) {
					break;
				}
				p1 = included1.top();
				included1.pop();
				p2 = included1.top();
				included1.push(p1);
			}
			included1.push(i);
		}
	}
	
	while(!included.empty()) {
		int i = included.top();
		cout << points[i].first << " " << points[i].second << endl;
		included.pop();
	}
	while(!included1.empty()) {
		int i = included1.top();
		cout << points[i].first << " " << points[i].second << endl;
		included1.pop();
	}
	return 0;	
}
