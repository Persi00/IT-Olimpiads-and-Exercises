// OIJ XV stage II
// Największy plus
// https://szkopul.edu.pl/problemset/problem/DJN8oaDlV5EfddZP8aBWyA_t/site/

#include <bits/stdc++.h>

using namespace std;

const int inf = 1e8+7; //infinity
int n;
vector<int> buildings;

int find(); // the biggest arm of plus fiding function using binary search
bool check(int mid); // checking function for bs

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n; // read count of buildings
	buildings.resize(n);

	for(int i = 0; i < n; ++i) cin >> buildings[i]; // read high of buildings

	cout << find(); //find the biggest arm of plus
}

int find()
{
	//just binary search
	int lo = 0, hi = inf, mid;
	while(lo < hi)
	{
		mid = (lo + hi + 1) / 2;
		if (check(mid)) lo = mid;
		else hi = mid - 1;
	}
	return lo;
}

bool check(int mid)
{
	for(int i = 0; i + (2 * mid + 1) <= n; ++i) // go for buildings while arm of plus is on buildings
	{
		if(buildings[i + mid] < 2 * mid + 1) continue; // if building isnt high enough, continue

		int j;
		for(j = i; j <= i + (2 * mid); ++j) // go for two arms
		{
			if(buildings[j] < mid + 1) // if building is too small for the plus
			{
				i = j; // go to hole
				break; // break loop
			}
		}

		if(j != i) return true; // if loop didnt end on hole, arm size is good
	}
	return false; // else, arm is too big
}
