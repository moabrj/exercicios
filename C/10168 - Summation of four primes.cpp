#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<bool>* sieve(int n)
{
    vector<bool>* pNums = new vector<bool>(n+1, true);
    vector<bool>& nums = *pNums;
    nums[0] = nums[1] = false;

    for(int i = 2; i * i <= n; i++)
    {
        printf("%d\n", i);
        if(nums[i])
        {
            for(int j = 2 * i; j <= n; j += i)
            {
                nums[j] = false;
            }
        }
    }

    return pNums;
}

int main(int argc, char *argv[])
{
    const int N = 10000000;
    vector<bool> *pNums = sieve(N);
    vector<bool> &nums = *pNums;

    int n;

    while(cin >> n)
    {
        if(n < 8)
            printf("Impossible.\n");
        else
        {
            int remainingSum;

            if(n%2 == 0)
            {
                cout << "2 2 ";
                remainingSum = n - 4;
            }
            else
            {
                cout << "2 3 ";
                remainingSum = n - 5;
            }

            int i;
            for (i = 2; i < remainingSum;++i)
            {
                if(nums[i] && nums[remainingSum-i])
                {
                    cout << i << " " << remainingSum - i << endl;
                    break;
                }
            }
            if(!(nums[i] && nums[remainingSum-i]))
                printf("Impossible.\n");
        }
    }
    delete pNums;
    return 0;
}
