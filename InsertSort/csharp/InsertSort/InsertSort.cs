using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace BinarySearch
{
    public static class InsertSort
    {

        public static void Sort<T>(List<T> data) where T : IEquatable<T>, IComparable<T>
        {
            void Insert(int cur)
            {
                T inserted = data[cur];
                for (--cur; cur >= 0 && inserted .CompareTo(data[cur]) < 0; --cur)
                {
                    data[cur + 1] = data[cur];
                }
                data[cur + 1] = inserted;
            }

            int low = 0;
            int hight = data.Count - 1;
            for (int i = low + 1; i <= hight; ++i)
            {
                Insert(i);
            }
        }
    }
}
