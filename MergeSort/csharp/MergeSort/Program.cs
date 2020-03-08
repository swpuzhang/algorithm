using System;
using System.Collections.Generic;
using System.Linq;

namespace BinarySearch
{
    class Program
    {
        static void Main(string[] _)
        {
            List<int> l = new List<int> { 2, 1, 3, 6, 8, 2 };
            MergeSort.Sort(l);
            Console.WriteLine($"sorted:");
            l.ForEach(x => Console.WriteLine(x));
            Console.WriteLine("Hello World!");
        }
    }
}
