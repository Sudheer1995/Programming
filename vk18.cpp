#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int get_diamonds(int N) {
    int evens = 0, odds = 0;
    while (N != 0) {
        int digit = N%10;
        if (digit%2 == 0)
            evens += digit;
        else
            odds += digit;
        N /= 10;
    }
    return fabs(evens-odds);
}

int main(int argc, char const *argv[]) {
    int T;
    cin>>T;
    long long int N = 1e+6;
    long long int previous = 2;
    vector <long long int> ans(N+1, 0);

    ans[1] = 2;
    for (int i = 1; i <= N; i++) {
        previous = previous - get_diamonds(i+1) + get_diamonds(2*i+1);
        ans[i+1] = ans[i] + 2*previous + get_diamonds(2*i+2);
        previous += get_diamonds(2*i+2);
    }

    for (int i = 0; i < T; i++) {
        int n;
        cin>>n;
        cout<<ans[n]<<endl;
    }
    return 0;
}
