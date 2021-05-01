#include <iostream>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"

using namespace std;

int main() {

    string filename = "testG1.txt";

    SparseGraph g1(13, false);
    ReadGraph<SparseGraph> readGraph1 (g1, filename);
    g1.show();

    cout << endl;

    DenseGraph g2(13, false);
    ReadGraph<DenseGraph> readGraph2 (g2, filename);
    g2.show();

    return 0;
}
/*将filename中的内容读进G1，输出：

vertext 0:      5       1       2       6
vertext 1:      0
vertext 2:      0
vertext 3:      4       5
vertext 4:      3       6       5
vertext 5:      0       4       3
vertext 6:      4       0
vertext 7:      8
vertext 8:      7
vertext 9:      12      10      11
vertext 10:     9
vertext 11:     12      9
vertext 12:     9       11


*将filename中的内容读进G2，输出：

0       1       1       0       0       1       1       0       0       0       0       0       0
1       0       0       0       0       0       0       0       0       0       0       0       0
1       0       0       0       0       0       0       0       0       0       0       0       0
0       0       0       0       1       1       0       0       0       0       0       0       0
0       0       0       1       0       1       1       0       0       0       0       0       0
1       0       0       1       1       0       0       0       0       0       0       0       0
1       0       0       0       1       0       0       0       0       0       0       0       0
0       0       0       0       0       0       0       0       1       0       0       0       0
0       0       0       0       0       0       0       1       0       0       0       0       0
0       0       0       0       0       0       0       0       0       0       1       1       1
0       0       0       0       0       0       0       0       0       1       0       0       0
0       0       0       0       0       0       0       0       0       1       0       0       1
0       0       0       0       0       0       0       0       0       1       0       1       0

*/