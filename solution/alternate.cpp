#include <vector>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int sz = 105;

using ll = long long;

int t, n;
int ar[sz];
ll dp[sz][sz];

ll rec( int l, int r ) {
        ll& ret = dp[l][r];
        if( ~ret ) return ret;
        ret = 0;
        for( int i=r+1; i<n; i++ ) {
                for( int j=i+1; j<n; j++ ) {
                        if( ar[i] == ar[j] ) {
                                ret = max( ret, 1 + rec( i, j ) );
                        }
                }
        }
        return ret;
}

ll solve() {
        ll ret = 0;
        memset( dp, -1, sizeof dp );
        for( int i=0; i<n; i++ ) {
                for( int j=i+1; j<n; j++ ) {
                        if( ar[i] == ar[j] ) {
                                ret = max( ret, 1 + rec( i, j ) );
                        }
                }
        }
        return ret;
}

int main() {

        scanf( "%d", &t );

        while( t-- ) {

                scanf( "%d", &n );

                assert( 1 <= n && n <= 100 );

                for( int i=0; i<n; i++ ) {
                        scanf( "%d", &ar[i] );
                        assert( 1 <= ar[i] && ar[i] <= 100 );
                }

                printf( "%lld\n", solve() );

        }

        return 0;
}