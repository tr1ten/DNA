#include <iostream>
#include <vector>
using namespace std;
// [2,7,13,19] mul - index [0,0,0,0] ugly numbers [1,2..]
int nthSuperUglyNumber(int n, vector<int> &primes)
{  

    int primesSize = primes.size();
    vector<int> muls(primesSize, 0);
    vector<int> uglyNumbers(n, 1);
    for (int i = 1; i < n; i++)
    {
        uglyNumbers[i] = primes[0] * uglyNumbers[muls[0]];
        vector<int> finalNs = {0};
        for (int j = 1; j < primesSize; j++)
        {
            int nextUgly = primes[j] * uglyNumbers[muls[j]];
            if ((nextUgly) < uglyNumbers[i])
            {
                uglyNumbers[i] = nextUgly;
                finalNs = {j};
            }
            else if ((primes[j] * uglyNumbers[muls[j]]) == uglyNumbers[i])
            {
                finalNs.push_back(j);
            }
        }
        for (auto k:finalNs)
        {

            muls[k]++;
        }
    }
    return uglyNumbers[n - 1];
}
int main()
{
    vector<int> primes = {7,19,29};
    cout << nthSuperUglyNumber(100, primes);
    return 0;
}

// 1000000
// [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541]
