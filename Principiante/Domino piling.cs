using System;

//https://codeforces.com/problemset/problem/50/A

public class Test
{
	public static void Main(string[] args)
	{
		int n; int m; 
		string [] w = Console.ReadLine().Split();
		n = int.Parse(w[0]);
		m = int.Parse(w[1]);
		
		Console.Write((n*m)/2);
	}
}