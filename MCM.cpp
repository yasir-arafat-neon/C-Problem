#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n = 5;
    int p[] = {5, 4, 6, 2, 7};

    int m[5][5];
    int s[5][5];


    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }


    for (int d = 1; d < n - 1; d++) {
        for (int i = 1; i < n - d; i++) {
            int j = i + d;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum number of multiplications: " << m[1][n - 1] << endl;

    return 0;
}
