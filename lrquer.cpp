#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
    int T;
    cin>>T;
    for (int i = 0; i < T; i++) {
        int N, Q, type, L, R, X, Y;
        cin>>N>>Q;
        long long int A[N];
        for (int j = 0; j < N; j++)
            cin>>A[j];
        for (int j = 0; j < Q; j++) {
            cin>>type;
            if (type == 1) {
                long long int ans = -1e+5;
                cin>>L>>R;
                if (L == R) {
                    cout<<0<<endl;
                }
                else {
                    for (int k = L-1; k < R; k++)
                        if (ans < (A[k]-A[L-1])*(A[R-1]-A[k]))
                            ans = (A[k]-A[L-1])*(A[R-1]-A[k]);
                    cout<<ans<<endl;
                }
            }
            else {
                cin>>X>>Y;
                A[X-1] = Y;
            }
        }
    }
    return 0;
}
