vector<int> primes;
void SieveOfEratosthenes(int n = 1000)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.push_back(p);
}

struct node {
    node() {
        SieveOfEratosthenes();
    }
}_;

class Solution {
public:
    bool primeSubOperation(vector<int>& v) {
        for(int i = 0; i < v.size(); i += 1) {
            if(i > 0 && v[i] <= v[i - 1]) return false;
            int idx = lower_bound(primes.begin(),primes.end(),v[i]) - primes.begin();
            for(int j = idx - 1; j >= 0; j -= 1) {
                if(i == 0 || v[i] - primes[j] > v[i - 1]) {
                    v[i] -= primes[j];break;
                }
            }
            if(i > 0 && v[i] <= v[i - 1]) return false;
        }
        return true;
    }
};