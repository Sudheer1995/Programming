#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
    int T;
    cin>>T;
    char C[100][100];
    for (int i = 0; i < T; i++) {
        int N, M;
        cin>>N>>M;
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++)
                cin>>C[j][k];
        int score1 = 0, score2 = 0;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if ((j%2 == 0 && k%2 == 0) || (j%2 == 1 && k%2 == 1)) {
                    if (C[j][k] == 'G')
                        score1 += 3;
                    if (C[j][k] == 'R')
                        score2 += 5;
                }
                else {
                    if (C[j][k] == 'R')
                        score1 += 5;
                    if (C[j][k] == 'G')
                        score2 += 3;
                }
            }
        }
        cout<<min(score1, score2)<<endl;
    }
    return 0;
}
