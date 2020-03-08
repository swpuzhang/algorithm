using System;
using System.Collections.Generic;

namespace BinarySearch
{
    class Program
    {
        static void Main(string[] _)
        {
            var findIndex = BianrySearch.Search(new List<int> { 1, 2, 3, 4, 5 }, 4);
            Console.WriteLine($"search 4 in list index:{findIndex}");
            Console.WriteLine("Hello World!");
        }
    }
}
