#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
    int T;
    cin>>T;
    for (int i = 0; i < T; i++) {
        int distA = 0, consecutive = 0, N;
        cin>>N;
        vector <int> A(N, 0), B(N, 0);
        for (int j = 0; j < N; j++) {
            cin>>B[j];
            A[j] = B[j];
        }
        for (int j = 0; j < N; j++) {
            if (A[j%N] == A[(j+1)%N]) {
                consecutive = 1;
                break;
            }
        }
        if (consecutive) {
            A.insert(A.begin(), A.back());
            A.pop_back();
        }
        A.insert(A.begin(), A.back());
        A.pop_back();
        for (int j = 1; j <= N; j++) {
            if (A[j] == B[j]) {
                int temp = A[(j-1)%N];
                A[(j-1)%N] = A[j%N];
                A[j%N] = temp;
            }
        }
        for (int j = 0; j < N; j++)
            if (A[j]!=B[j])
                distA++;
        cout<<distA<<endl;
        for (int j = 0; j < N; j++)
                cout<<A[j]<<" ";
        cout<<endl;
    }
    return 0;
}
