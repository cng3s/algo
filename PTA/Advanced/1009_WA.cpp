/*
This time, you are supposed to find A×B where A and B are two polynomials.

Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:
K N​1​​ a​N​1​​​​ N​2​​ a​N​2​​​​ ... N​K​​ a​N​K​​​​
where K is the number of nonzero terms in the polynomial, N​i​​ and a​N​i​​​​ (i=1,2,⋯,K) are the exponents and coefficients, respectively.
It is given that 1≤K≤10, 0≤N​K​​<⋯<N​2​​<N​1​​≤1000.

Output Specification:
For each test case you should output the product of A and B in one line, with the same format as the input.
Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.

Sample Input:
2 1 2.4 0 3.2
2 2 1.5 1 0.5

Sample Output:
3 3 3.6 2 6.0 1 1.6
*/

#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int main()
{
    vector<vector<pair<double, double>>> polys(2);
    map<double, double> res;
    
    // get inputs
    for ( int i = 0; i < 2; ++i ) {
        int K;
        double NK, aNK;
        scanf("%d", &K);
        for ( int j = 0; j < K; ++j ) {
            scanf("%lf %lf", &NK, &aNK);
            polys[i].push_back( {NK, aNK} );
        }
    }

    // do polyA * polyB
    for ( auto itemA : polys[0] ) {
        for ( auto itemB : polys[1] ) {
            double exp = itemA.first + itemB.first,
                   cof = itemA.second * itemB.second;
            auto it = res.find(exp);
            if ( it != res.end() ) {
                it->second += cof;
            } else {
                res.insert( {exp, cof} );
            }
        }
    }

    printf("%llu ", res.size());
    auto it = res.rbegin();
    printf("%.0lf %.1lf", it->first, it->second);
    for ( ++it; it != res.rend(); ++it ) {
        printf(" %.0lf %.1lf", it->first, it->second);
    }

    return 0;
}