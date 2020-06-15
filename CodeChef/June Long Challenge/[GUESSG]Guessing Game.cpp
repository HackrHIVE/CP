#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    long int n;
    cin >> n;
    long int lo = 1;
    long int hi = n;
    long int mid = lo + (hi - lo) / 2;
    char x = 'L';
    int gCounter = 0;
    int lCounter = 0;
    int eCounter = 0;
    int queryCounter = 0;
    while (x != 'E' && queryCounter <= 120 && lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        cout << mid << endl;
        cin >> x;
        gCounter = 0;
        lCounter = 0;
        eCounter = 0;
        queryCounter++;
        switch (x)
        {
        case 'G':
            gCounter++;
            break;
        case 'E':
            eCounter++;
            break;
        case 'L':
            lCounter++;
            break;
        }
        while (queryCounter % 4 != 0 && x != 'E' && queryCounter <= 120)
        {
            cout << mid << endl;
            cin >> x;
            queryCounter++;
            switch (x)
            {
            case 'G':
                gCounter++;
                break;
            case 'E':
                eCounter++;
                break;
            case 'L':
                lCounter++;
                break;
            }
        }
        if (gCounter > lCounter && gCounter > eCounter)
            lo = mid + 1;
        else if (lCounter > gCounter && lCounter > eCounter)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return 0;
}