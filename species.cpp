#include <iostream>
using namespace std;
long long int mod = 7+1e+9;
char A[50][50];

long long int possibilities(int N) {
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            if (A[j][k] == 'B') {
                // conflict check
                if (j > 0 && A[j-1][k] == 'P')
                    return 0;
                if (k > 0 && A[j][k-1] == 'P')
                    return 0;
                if (j < N-1 && A[j+1][k] == 'P')
                    return 0;
                if (k < N-1 && A[j][k+1] == 'P')
                    return 0;
                // Neighbours update
                if (j > 0 && A[j-1][k] == '?')
                    A[j-1][k] = A[j][k];
                if (k > 0 && A[j][k-1] == '?')
                    A[j][k-1] = A[j][k];
                if (j < N-1 && A[j+1][k] == '?')
                    A[j+1][k] = A[j][k];
                if (k < N-1 && A[j][k+1] == '?')
                    A[j][k+1] = A[j][k];
            }
            else if(A[j][k] == 'P') {
                // conflict check
                if (j > 0 && A[j-1][k] == 'B')
                    return 0;
                if (k > 0 && A[j][k-1] == 'B')
                    return 0;
                if (j < N-1 && A[j+1][k] == 'B')
                    return 0;
                if (k < N-1 && A[j][k+1] == 'B')
                    return 0;
                // Neighbours update
                if (j > 0 && A[j-1][k] == '?')
                    A[j-1][k] = A[j][k];
                if (k > 0 && A[j][k-1] == '?')
                    A[j][k-1] = A[j][k];
                if (j < N-1 && A[j+1][k] == '?')
                    A[j+1][k] = A[j][k];
                if (k < N-1 && A[j][k+1] == '?')
                    A[j][k+1] = A[j][k];
            }
            else if(A[j][k] == 'G') {
                // conflict check
                if (j > 0 && A[j-1][k] != '.')
                    return 0;
                if (k > 0 && A[j][k-1] != '.')
                    return 0;
                if (j < N-1 && A[j+1][k] != '.')
                    return 0;
                if (k < N-1 && A[j][k+1] != '.')
                    return 0;
            }
        }
    }
    long long int ans = 1;
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            if (A[j][k] == '?') {
                int nothing = 0;
                if (j > 0 && A[j-1][k] != '.')
                    nothing = 1;
                if (k > 0 && A[j][k-1] != '.')
                    nothing = 1;
                if (j < N-1 && A[j+1][k] != '.')
                    nothing = 1;
                if (k < N-1 && A[j][k+1] != '.')
                    nothing = 1;
                if (nothing == 0) {
                    ans = (ans*3)%mod;
                }
                else {
                    int notvisited = 0;
                    if (j > 0 && A[j-1][k] == 'v')
                        { notvisited = 1; A[j][k] = 'v';}
                    else if (k > 0 && A[j][k-1] == 'v')
                        { notvisited = 1; A[j][k] = 'v';}
                    else if (j < N-1 && A[j+1][k] == 'v')
                        { notvisited = 1; A[j][k] = 'v';}
                    else if (k < N-1 && A[j][k+1] == 'v')
                        { notvisited = 1; A[j][k] = 'v';}
                    if (notvisited == 0) {
                        ans = (ans*2)%mod;
                        if (j > 0 && A[j-1][k] == '?')
                            A[j-1][k] = 'v';
                        if (k > 0 && A[j][k-1] == '?')
                            A[j][k-1] = 'v';
                        if (j < N-1 && A[j+1][k] == '?')
                            A[j+1][k] = 'v';
                        if (k < N-1 && A[j][k+1] == '?')
                            A[j][k+1] = 'v';
                    }
                }
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    int T;
    cin>>T;
    for (int i = 0; i < T; i++) {
        int N;
        cin>>N;
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                cin>>A[j][k];
        cout<<possibilities(N)<<endl;
    }
    return 0;
}
