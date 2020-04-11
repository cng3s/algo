#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

#define MAXN 101
string str1, str2;
int dp[MAXN][MAXN] = { 0 };


// 使用push方式生成dp表并返回最长公共子序列
int dp_push() {
    dp[0][0] = ( str1[0] == str2[0] );
    for ( int i = 1; i < str1.size(); ++i ) { dp[i][0] = dp[i-1][0] == 1 ? 1 : str1[i] == str2[0]; } 
    for ( int i = 1; i < str2.size(); ++i ) { dp[0][i] = dp[0][i-1] == 1 ? 1 : str1[0] == str2[i]; }

    for ( int i = 1; i < str1.size(); ++i ) {
        for ( int j = 1; j < str2.size(); ++j ) {
            dp[i][j] = ( str1[i] == str2[j] ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]) );
        }
    }

    return dp[str1.size()-1][str2.size()-1];
}

// 《算法笔记》的解法，和我自己写的dp_push略有差别，也是push方式
// 其中算法思路是完全相同的，而dp数组的使用方式略有不同
int dp_push2() {
    for ( int i = 0; i < str1.size(); ++i ) { dp[i][0] = 0; }
    for ( int i = 0; i < str2.size(); ++i ) { dp[0][i] = 0; }

    for ( int i = 1; i <= str1.size(); ++i ) {
        for ( int j = 1; j <= str2.size(); ++j ) {
            dp[i][j] = ( str1[i-1] == str2[j-1] ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]) );
        }
    }

    return dp[str1.size()][str2.size()];
}

// 使用pull的方式生成dp表 - 这种pull方式是基于我写的push方式来的
// idx1: str1的idx
// idx2: str2的idx
static int _pull1( int idx1, int idx2 ) {
    if ( idx1 == 0 || idx2 == 0 || dp[idx1][idx2] != 0 ) { return dp[idx1][idx2]; }
    dp[idx1][idx2] = ( str1[idx1] == str2[idx2] ? _pull1( idx1-1, idx2-1 )+1 : max( _pull1(idx1-1, idx2), _pull1(idx1, idx2-1) ) );
    return dp[idx1][idx2];
}

int dp_pull1() {
    dp[0][0] = ( str1[0] == str2[0] );
    for ( int i = 1; i < str1.size(); ++i ) { dp[i][0] = dp[i-1][0] == 1 ? 1 : str1[i] == str2[0]; } 
    for ( int i = 1; i < str2.size(); ++i ) { dp[0][i] = dp[0][i-1] == 1 ? 1 : str1[0] == str2[i]; }

    return _pull1( str1.size()-1, str2.size()-1 );
}

// 使用基于《算法笔记》的push方式而改造的pull方式生成dp表
static int _pull2( int idx1, int idx2 ) {
    if ( idx1 == 0 || idx2 == 0 || dp[idx1][idx2] != 0 ) { return dp[idx1][idx2]; }
    dp[idx1][idx2] = ( str1[idx1-1] == str2[idx2-1] ? _pull2(idx1-1, idx2-1)+1 : max(_pull2(idx1-1, idx2), _pull2(idx1, idx2-1)) );
    return dp[idx1][idx2];
}

int dp_pull2() {
    for ( int i = 0; i < str1.size(); ++i ) { dp[i][0] = 0; }
    for ( int i = 0; i < str2.size(); ++i ) { dp[0][i] = 0; }

    return _pull2( str1.size(), str2.size() );    
}

static void testFromFile() {
    ifstream ins("LCS_Testcases.txt", ios::in);
    if ( !ins.is_open() ) {
        cerr << "Error opening file!";
        exit(-1);
    }

    while (!ins.eof() && ins >> str1 >> str2) {
        memset( dp, 0, sizeof(int)*MAXN*MAXN );
        cout << dp_push() << " ";

        memset( dp, 0, sizeof(int)*MAXN*MAXN );
        cout << dp_push2() << " ";

        memset( dp, 0, sizeof(int)*MAXN*MAXN );
        cout << dp_pull1() << " ";

        memset( dp, 0, sizeof(int)*MAXN*MAXN );
        cout << dp_pull2() << endl;
    }

    ins.close();
}

static void testFromStdInput() {
    cin >> str1 >> str2;
    memset( dp, 0, sizeof(int)*MAXN*MAXN );
    cout << dp_push() << " ";

    memset( dp, 0, sizeof(int)*MAXN*MAXN );
    cout << dp_push2() << " ";

    // memset( dp, 0, sizeof(int)*MAXN*MAXN );
    // cout << dp_pull1() << " ";

    // memset( dp, 0, sizeof(int)*MAXN*MAXN );
    // cout << dp_pull2() << endl;
}


int main() {

    // testFromStdInput();
    testFromFile();

    return 0;
}