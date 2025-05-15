#include<bits/stdc++.h>
using namespace std;
//recursive
int binaryExponentian(int base,int power,int mod=1e9+7){
    if(power==0){
        return 1;
    }
    int half=binaryExponentian(base,power/2,mod)%mod;
    int result= (1LL*half*half)%mod;
    if(power%2==1){
        result=(1LL*result*base)%mod;
    }
    return result;
}
//iterative
int findPower(int base,int power,int mod=1e9+7)
{
    int result=1;
    base%=mod;
    while(power>0)
    {
        if(power%2==1)
        {
            result=(1LL*result*base)%mod;
        }
        base=(1LL*base*base)%mod;
        power/=2;
    }
    return result;
}


typedef vector<vector<int>> Matrix;
const int M = 1e9+7;
Matrix matrixMultiplication(Matrix &A, Matrix &B)
{
    Matrix C(26, vector<int>(26, 0));
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            for(int k = 0; k< 26; k++)
            {
                C[i][j] = (C[i][j] + (1LL * A[i][k] * B[k][j]) % M) % M;
            }
        }
    }
    return C;
}
Matrix matrixExponentiation(Matrix &base, int exponent)
{
    if(exponent == 0){
        Matrix I(26, vector<int>(26, 0));
        for(int i = 0; i < 26; i++)
        {
            I[i][i] = 1;
        }
        return I;
    }
    Matrix half = matrixExponentiation(base, exponent/2);
    Matrix result = matrixMultiplication(half, half);
    if(exponent % 2 == 1){
        result = matrixMultiplication(result, base);
    }
    return result;
}