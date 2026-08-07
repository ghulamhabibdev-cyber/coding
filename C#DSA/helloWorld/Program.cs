using System.Collections;
using System;
public class Solution
{
    public int LinearSearch(List<int> arr, int target)
    {
        int n = arr.Count;
        if (n <= 0)
        {
            return -1;
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == target)
            {
                return i;
            }
        }
        return -1;
    }
}
public class Program
{
    public static void Print<T>(T val)
    {
        Console.WriteLine(val);
    }
    public static void IteratorPirnt<T>(T arr) where T : IEnumerable
    {
        foreach (var val in arr)
        {
            Console.WriteLine(val);
        }
    }
    public static void Main(string[] args)
    {
        Solution s = new Solution();
        List<int> arr = new List<int>() { 1, 2, 3, 4 };
        int index = s.LinearSearch(arr, 2);
        if (index != -1)
        {

            Print<string>("Number is Prenset : " + arr[index]);
        }
    }
}