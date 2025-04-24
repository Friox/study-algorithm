/*
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int value[10];

int main()
{
	int N, end, begin;

	vector<pair<int, int>> schedule;

	cin >> N ;

	for (int i = 0; i < N; i++)
	{
		cin >> begin >> end;
		schedule.push_back(make_pair(end, begin));
	}
	
	sort(schedule.begin(), schedule.end());
	
	int time = schedule[0].first;
	int count = 1;
	for (int i = 1 ;i < N; i++) 
	{
		if (time <= schedule[i].second )
		{
			count++;
			time = schedule[i].first;
		}
	}

	cout << count;
}
*/

#include <ios>
#include <vector>
#include <algorithm>

int main() {
    int n, start, end, cnt = 1;
    std::vector<std::pair<int, int>> v;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &start, &end);
        v.push_back({ end, start });
    }
    std::sort(v.begin(), v.end());
    int time = v[0].first;
    for (int i = 1; i < n; ++i) {
        if (time <= v[i].second) {
            cnt++;
            time = v[i].first;
        }
    }
    printf("%d", cnt);
}