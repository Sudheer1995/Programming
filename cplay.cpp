#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
    string s;
    while (cin>>s) {
        int a = 0, b = 0, r_a = 5, r_b = 5;
        for (int i = 0; i < 20; i++) {
            if (i < 10) {
                if (i%2 == 0) {
                    a += s[i]-'0';
                    r_a -= 1;
                }
                else {
                    b += s[i]-'0';
                    r_b -= 1;
                }
                if (b>a+r_a) {
                    cout<<"TEAM-B "<<i+1<<endl;
                    break;
                }
                if (a>b+r_b) {
                    cout<<"TEAM-A "<<i+1<<endl;
                    break;
                }
            }
            else {
                if (i%2 == 0)
                    a += s[i]-'0';
                else {
                    b += s[i]-'0';
                    if (a > b) {
                        cout<<"TEAM-A "<<i+1<<endl;
                        break;
                    }
                    if (b > a) {
                        cout<<"TEAM-B "<<i+1<<endl;
                        break;
                    }
                }
            }
            if (i == 9) {
                if (a > b) {
                    cout<<"TEAM-A "<<i+1<<endl;
                    break;
                }
                if (b > a) {
                    cout<<"TEAM-B "<<i+1<<endl;
                    break;
                }
            }
        }
        if (a == b)
            cout<<"TIE"<<endl;
    }
    return 0;
}
