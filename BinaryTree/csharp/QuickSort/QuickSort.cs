using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace BinarySearch
{
    public static class SelectSort
    {
        
        public static void Sort<T>( List<T> data) where T : IEquatable<T>, IComparable<T>
        {
            void InnerSort(int low, int high, List<T> data)
            {

                if (data.Count < 1 || low >= high)
                {
                    return;
                }

                var privot = data[low];
                int lowTemp = low;
                int highTemp = high;
                while (lowTemp < highTemp)
                {
                    while (lowTemp < highTemp && data[highTemp].CompareTo(privot) >= 0)
                    {
                        --highTemp;
                    }
                    while (lowTemp < highTemp && data[lowTemp].CompareTo(privot) <= 0)
                    {
                        ++lowTemp;
                    }
                    if (lowTemp < highTemp)
                    {
                        T temp = data[lowTemp];
                        data[lowTemp] = data[highTemp];
                        data[highTemp] = temp;
                    }
                }
                data[low] = data[lowTemp];
                data[lowTemp] = privot;
                InnerSort(low, lowTemp - 1, data);
                InnerSort(lowTemp + 1, high, data);
            }
            InnerSort(0, data.Count - 1, data);
        }
        
    }
}
