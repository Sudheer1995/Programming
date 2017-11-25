#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    long N;
    cin>>N;
    int A[N];
    for (long i = 0; i < N; i++)
        cin>>A[i];
    int max_length = 0, length = 0;
    for (long i = 0; i < N; i++) {
        if (A[i] == 0) {
            if (length > max_length)
                max_length = length;
            length = 0;
            continue;
        }
        length++;
    }
    if (length > max_length)
        max_length = length;
    cout<<max_length<<endl;
    return 0;
}
