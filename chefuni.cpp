#include <iostream>
#include <algorithm>
using namespace std;

int three_min(int a, int b, int c) {
    return min(a, min(b, c));
}

int seven_min(int a, int b, int c, int d, int e, int f, int g) {
    return min(a, min(b, min(c, min(d, min(e, min(f, g))))));
}

int main(int argc, char const *argv[]) {
    int T;
    cin>>T;
    for (int i = 0; i < T; i++) {
        int X, Y, Z, A, B, C;
        cin>>X>>Y>>Z>>A>>B>>C;
        int path[X+1][Y+1][Z+1];
        for (int z = 0; z <= Z; z++) {
            for (int y = 0; y <= Y; y++) {
                for (int x = 0; x <= X; x++) {
                    if (z == 0) {
                        if (x == 0) {
                            if (y == 0)
                                path[x][y][z] = 0;
                            else
                                path[x][y][z] = A+path[x][y-1][z];
                        }
                        else {
                            if (y == 0)
                                path[x][y][z] = A+path[x-1][y][z];
                            else
                                path[x][y][z] = three_min(A+path[x-1][y][z], A+path[x][y-1][z],
                                                        B+path[x-1][y-1][z]);
                        }
                    }
                    else {
                        if (x == 0) {
                            if (y == 0)
                                path[x][y][z] = A+path[x][y][z-1];
                            else
                                path[x][y][z] = three_min(A+path[x][y-1][z], A+path[x][y][z-1],
                                                        B+path[x][y-1][z-1]);
                        }
                        else {
                            if (y == 0)
                                path[x][y][z] = three_min(A+path[x-1][y][z], A+path[x][y][z-1],
                                                        B+path[x-1][y][z-1]);
                            else
                                path[x][y][z] = seven_min(A+path[x-1][y][z], A+path[x][y-1][z], A+path[x][y][z-1],
                                                        B+path[x-1][y-1][z], B+path[x-1][y][z-1], B+path[x][y-1][z-1],
                                                        C+path[x-1][y-1][z-1]);
                        }
                    }
                }
            }
        }
        cout<<path[X][Y][Z]<<endl;
    }
    return 0;
}
