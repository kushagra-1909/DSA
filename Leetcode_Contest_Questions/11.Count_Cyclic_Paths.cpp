// Given a triangular pyramid with its vertices marked as O, A, B and C and a number N, the
// task is to find the number of ways such that a person starting from the origin O initially,
// reaches back to the origin in N steps. In a single step, a person can go to any of its adjacent
// vertices.
// o
// c
// Example 1:
// Input:

int countPaths(int N){
        long mod = 1e9+7, o = 1, a = 0, b=0, c=0;
        for(int i=0; i<N; i++){
            long temp1 = (a+b+c)%mod;
            long temp2 = (o+b+c)%mod;
            long temp3 = (o+a+c)%mod;
            long temp4 = (o+a+b)%mod;
            o = temp1;
            a = temp2;
            b = temp3;
            c = temp4;
        }
        return o;
    }