using System;

class Program
{
    static void Main()
    {
        int n;

        // 입력 처리
        n = int.Parse(Console.ReadLine());

        // 2차원 배열 선언
        int[,] arr = new int[505, 505];

        // 삼각형 숫자 입력 받기
        for (int i = 0; i < n; i++)
        {
            string[] input = Console.ReadLine().Split();
            for (int j = 0; j <= i; j++)
            {
                arr[i, j] = int.Parse(input[j]);
            }
        }

        // 하단에서부터 상단으로 최대 합 계산
        for (int i = n - 1; i >= 1; i--)
        {
            for (int j = 0; j < i; j++)
            {
                arr[i - 1, j] += Math.Max(arr[i, j], arr[i, j + 1]);
            }
        }

        // 결과 출력
        Console.WriteLine(arr[0, 0]);
    }
}
