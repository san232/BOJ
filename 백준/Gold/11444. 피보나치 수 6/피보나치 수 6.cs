using System;

class Program
{
    const int MOD = 1000000007;

    static void Main()
    {
        long n = long.Parse(Console.ReadLine());
        Console.WriteLine(Fibonacci(n));
    }

    static long Fibonacci(long n)
    {
        if (n == 1) return 1;
        long[,] baseMatrix = { { 1, 1 }, { 1, 0 } };
        long[,] result = MatrixPower(baseMatrix, n - 1);
        return result[0, 0];
    }

    static long[,] MatrixPower(long[,] matrix, long exp)
    {
        long[,] result = { { 1, 0 }, { 0, 1 } };
        long[,] baseMatrix = matrix;

        while (exp > 0)
        {
            if (exp % 2 == 1)
                result = MatrixMultiply(result, baseMatrix);
            baseMatrix = MatrixMultiply(baseMatrix, baseMatrix);
            exp /= 2;
        }

        return result;
    }

    static long[,] MatrixMultiply(long[,] A, long[,] B)
    {
        return new long[,] {
            { (A[0,0] * B[0,0] + A[0,1] * B[1,0]) % MOD, (A[0,0] * B[0,1] + A[0,1] * B[1,1]) % MOD },
            { (A[1,0] * B[0,0] + A[1,1] * B[1,0]) % MOD, (A[1,0] * B[0,1] + A[1,1] * B[1,1]) % MOD }
        };
    }
}
