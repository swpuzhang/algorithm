using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace BinarySearch
{
    public static class BianrySearch
    {

        public static int Search<T>(List<T> data, T val) where T : IEquatable<T>, IComparable<T>
        {
            int low = 0;
            int hight = data.Count - 1;
            while (low <= hight)
            {
                int mid = (hight + low) / 2;
                T guess = data[mid];
                int com = guess.CompareTo(val);
                if (com == 0)
                {
                    return mid;
                }
                if (com < 0)
                {
                    low = mid + 1;
                }
                else
                {
                    hight = mid - 1;
                }
            }

            return -1;
        }
    }
}
