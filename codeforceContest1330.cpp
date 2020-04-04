/*
A. Dreamoon and Ranking Collection

One day, he claimed that he will collect all the places from 1 to 54 after two more rated contests. It's amazing!

Based on this, you come up with the following problem:

There is a person who participated in n Codeforces rounds. His place in the first round is a1, his place in the second round is a2, ..., his place in the n-th round is an.

You are given a positive non-zero integer x.

Please, find the largest v such that this person can collect all the places from 1 to v after x more rated contests.

In other words, you need to find the largest v, such that it is possible, that after x more rated contests, for each 1≤i≤v, there will exist a contest where this person took the i-th place.

For example, if n=6, x=2 and a=[3,1,1,5,7,10] then answer is v=5, because if on the next two contest he will take places 2 and 4, then he will collect all places from 1 to 5, so it is possible to get v=5.

Input
The first line contains an integer t (1≤t≤5) denoting the number of test cases in the input.

Each test case contains two lines. The first line contains two integers n,x (1≤n,x≤100). The second line contains n positive non-zero integers a1,a2,…,an (1≤ai≤100).

Output
For each test case print one line containing the largest v, such that it is possible that after x other contests, for each 1≤i≤v, there will exist a contest where this person took the i-th place.

Example
input
5
6 2
3 1 1 5 7 10
1 100
100
11 1
1 1 1 1 1 1 1 1 1 1 1
1 1
1
4 57
80 60 40 20
output
5
101
2
2
60
*/



#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<bool> v(201, false);
        int a;
        for (int i = 0; i < n; i++) {
            cin >> a;
            v[a] = true;
        }
        int remain = x;
        for (int i = 1; i <= 200; i++) {
            if (!v[i]) {
                v[i] = true;
                remain--;
                if (remain <= 0) {
                    break;
                }
            }
        }
        for (int i = 1; i <= 201; i++) {
            if (!v[i]) {
                cout << i - 1 << endl;
                break;
            }
        }
    }
}

