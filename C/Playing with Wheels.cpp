#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define N 1000000
#define LL long long
using namespace std;
 
int main ()
{
    int testCase;
    scanf ("%d", &testCase);
 
    while ( testCase-- ) {
        int input;
        vector <int> v;
        map <vector <int>, int> pressCnt;
        map <vector <int>, bool> visited;
        queue <vector <int> > q;
 
        for ( int i = 0; i < 4; i++ ) {
            scanf ("%d", &input);
            v.push_back (input);
        }
 
        pressCnt [v] = 0;
        q.push (v);
 
        vector <int> dest;
 
        for ( int i = 0; i < 4; i++ ) {
            scanf ("%d", &input);
            dest.push_back (input);
        }
 
        int n;
        scanf ("%d", &n);
 
        for ( int i = 0; i < n; i++ ) {
            v.clear ();
            for ( int j = 0; j < 4; j++ ) {
                scanf ("%d", &input);
                v.push_back (input);
            }
            visited [v] = true;
        }
 
        bool resultFound = false;
 
        while ( !q.empty () ) {
            v.clear ();
            v = q.front ();
            q.pop ();
 
            if ( visited [v] == true ) continue;
 
            visited [v] = true;
 
            if ( v == dest ) {
                resultFound = true;
                break;
            }
 
            vector <int> child = v;
 
            for ( int i = 0; i < 4; i++ ) {
                child [i] += 1;
                child [i] %= 10;
                if ( visited [child] == false )
                    q.push (child);
                pressCnt [child] = pressCnt [v] + 1;
                child = v;
            }
 
            for ( int i = 0; i < 4; i++ ) {
                child [i] -= 1;
                if ( child [i] == -1 ) child [i] = 9;
                if ( visited [child] == false )
                    q.push (child);
                pressCnt [child] = pressCnt [v] + 1;
                child = v;
            }
        }
 
        if ( resultFound ) printf ("%d\n", pressCnt [dest]);
        else printf ("-1\n");
    }
 
    return 0;
}
