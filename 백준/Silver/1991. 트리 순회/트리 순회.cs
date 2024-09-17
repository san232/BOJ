using System;
using System.Collections.Generic;

class Node
{
    public char Item;
    public char Left;
    public char Right;

    public Node(char item, char left, char right)
    {
        this.Item = item;
        this.Left = left;
        this.Right = right;
    }
}

class Program
{
    static Dictionary<char, Node> tree = new Dictionary<char, Node>();

    static void Preorder(Node node)
    {
        Console.Write(node.Item); // 현재 노드 출력

        if (node.Left != '.') // 왼쪽 자식이 있는 경우
        {
            Preorder(tree[node.Left]);
        }

        if (node.Right != '.') // 오른쪽 자식이 있는 경우
        {
            Preorder(tree[node.Right]);
        }
    }

    static void Inorder(Node node)
    {
        if (node.Left != '.') // 왼쪽 자식이 있는 경우
        {
            Inorder(tree[node.Left]);
        }

        Console.Write(node.Item); // 현재 노드 출력

        if (node.Right != '.') // 오른쪽 자식이 있는 경우
        {
            Inorder(tree[node.Right]);
        }
    }

    static void Postorder(Node node)
    {
        if (node.Left != '.') // 왼쪽 자식이 있는 경우
        {
            Postorder(tree[node.Left]);
        }

        if (node.Right != '.') // 오른쪽 자식이 있는 경우
        {
            Postorder(tree[node.Right]);
        }

        Console.Write(node.Item); // 현재 노드 출력
    }

    static void Main()
    {
        int n = int.Parse(Console.ReadLine()); // 노드의 개수 입력
        for (int i = 0; i < n; i++)
        {
            string[] input = Console.ReadLine().Split();
            char item = input[0][0];  // 노드 이름
            char left = input[1][0];  // 왼쪽 자식
            char right = input[2][0]; // 오른쪽 자식
            tree[item] = new Node(item, left, right);
        }

        Preorder(tree['A']); // 전위 순회
        Console.WriteLine();
        Inorder(tree['A']);  // 중위 순회
        Console.WriteLine();
        Postorder(tree['A']); // 후위 순회
        Console.WriteLine();
    }
}
