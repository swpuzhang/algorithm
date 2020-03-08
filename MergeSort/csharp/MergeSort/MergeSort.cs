using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace BinarySearch
{
    public static class MergeSort
    {
        
        public static void Sort<T>( List<T> data) where T : IEquatable<T>, IComparable<T>
        {
            void InnerSort(int low, int high, List<T> data)
            {
                if (low >= high)
                {
                    return;
                }
                int mid = (low + high) / 2;
                InnerSort(low, mid, data);
                InnerSort(mid + 1, high, data);
                Merge(low, mid, high, data);
            }
            void Merge(int low, int mid, int high, List<T> data)
            {
                List<T> temp = new List<T>(data.Count);
                int lowIndex = low;
                int highIndex = mid + 1;
                while (lowIndex <= mid && highIndex <= high)
                {
                    if (data[lowIndex].CompareTo(data[highIndex]) <= 0 )
                    {
                        temp.Add(data[lowIndex]);
                        ++lowIndex;
                    }
                    else
                    {
                        temp.Add(data[highIndex]);
                        ++highIndex;
                    }
                }
                while (lowIndex <= mid)
                {
                    temp.Add(data[lowIndex]);
                    ++lowIndex;
                }
                while (highIndex <= high)
                {
                    temp.Add(data[highIndex]);
                    ++highIndex;
                }
                for (int i = 0; i < temp.Count; ++i)
                {
                    data[low + i] = temp[i];
                }
            }
            InnerSort(0, data.Count - 1, data);
        }
        
    }
}
