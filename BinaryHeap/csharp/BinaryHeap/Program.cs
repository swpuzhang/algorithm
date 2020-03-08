using System;
using System.Collections.Generic;
using System.Linq;

namespace BinaryHeap
{
    class Program
    {
        static void Main(string[] _)
        {
            List<int> l = new List<int> { 2, 1, 3, 6, 8, 2 };
            Heap<int> h = new Heap<int>();
            l.ForEach(x => h.Insert(x));
        }
    }
}
