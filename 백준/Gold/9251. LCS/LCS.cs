using System;

class Program
{
    static void Main()
    {
        // 문자열 입력
        string str = Console.ReadLine();
        string str2 = Console.ReadLine();

        // LCS 테이블 초기화
        int[,] LCS = new int[1002, 1002];

        // LCS 알고리즘 적용
        for (int i = 1; i <= str.Length; i++)
        {
            for (int j = 1; j <= str2.Length; j++)
            {
                if (str[i - 1] == str2[j - 1])
                {
                    LCS[i, j] = LCS[i - 1, j - 1] + 1;
                }
                else
                {
                    LCS[i, j] = Math.Max(LCS[i - 1, j], LCS[i, j - 1]);
                }
            }
        }

        // 결과 출력
        Console.WriteLine(LCS[str.Length, str2.Length]);
    }
}
