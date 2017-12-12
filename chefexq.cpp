#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
    int N, Q;
    cin>>N>>Q;
    std::vector<long long int> A(N, 0);
    for (int i = 0; i < N; i++)
        cin>>A[i];
    for (int i = 0; i < Q; i++) {
        int type;
        cin>>type;
        if (type == 1) {
            int a;
            long long int b;
            cin>>a>>b;
            A[a-1] = b;
        }
        else {
            int a, count = 0;
            long long int b, x = 0;
            cin>>a>>b;
            for (int j = 0; j < a; j++) {
                x = x^A[j];
                if (x == b)
                    count++;
            }
            cout<<count<<endl;
        }
    }
    return 0;
}
