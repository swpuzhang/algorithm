using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace BinarySearch
{
    public static class ShellSort
    {

        public static void Sort<T>(List<T> data) where T : IEquatable<T>, IComparable<T>
        {
            void Insert(int cur, int inc)
            {
                T inserted = data[cur];
                for (cur -= inc; cur >= 0 && inserted .CompareTo(data[cur]) < 0; cur -= inc)
                {
                    data[cur + inc] = data[cur];
                }
                data[cur + inc] = inserted;
            }
            int low = 0;
            int hight = data.Count - 1;
            for (int inc = data.Count / 2; inc > 0; inc /= 2)
            {
                for (int i = low + inc; i <= hight; ++i)
                {
                    Insert(i, inc);
                }
            }
           
        }
    }
}
