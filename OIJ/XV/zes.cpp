// OIJ XV stage II
// Zespoły
// https://szkopul.edu.pl/problemset/problem/WsCEgGZvejeElRDr0xT7Nwwf/site/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, groups = 0;
    vector<int> members;

    cin >> n; // read count of members

    members.resize(n);
    for (int i = 0; i < n; i++) cin >> members[i]; // read peoples levels

    sort(members.begin(), members.end()); // sort by levels

    for (int i = 0; i < n; i++)
    {
    	if(members[i] + 1 >= members[i+2]) // if diffrence between two members arent greater than 1
        {
            groups++; // make group
            i+=3; // go to 3rd person after you (because we used 1st and 2nd to group)
        }
    }
    cout << groups << "\n"; // print number of groups

    return 0;
}
