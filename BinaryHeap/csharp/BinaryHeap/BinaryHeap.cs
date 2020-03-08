using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace BinaryHeap
{
    public class Heap<T>  where T :IComparable<T>
    {
        private List<T> _arr = new List<T>();
        private int _size = 0;
        public void Insert(T data)
        {
            _arr.Add(data);
            ++_size;
            FilterUp(_size - 1);
        }

        public int Find(T data)
        {
            return _arr.FindIndex(x => x.CompareTo(data) == 0);
        }

        public void Remove(T data)
        {
            if (_size == 0)
            {
                return;
            }
            int index = Find(data);
            if (index == -1)
            {
                return;
            }
            _arr[index] = _arr[_size - 1];
            _arr.RemoveAt(_size - 1);

        }
        private void FilterDown(int index)
        {
            T data = _arr[index];
            while (index < _size - 1)
            {
                int left = 2 * index + 1;
                int right = left + 1;
                T leftData = _arr[left];
                T rightData = _arr[right];
                T comData = leftData;
                int comIndex = left;
                if (leftData.CompareTo(rightData) > 0)
                {
                    comData = rightData;
                    comIndex = right;
                }
                if (data.CompareTo(comData) <= 0)
                { 
                    break; 
                }
                else
                {
                    _arr[index] = _arr[comIndex];
                    index = comIndex;
                }
            }
        }
        private void FilterUp(int index)
        {
            T data = _arr[index];
            if (index <= 0)
            {
                return;
            }
            //找到父节点, 如果比父节点小,继续找父节点
            while (index > 0)
            {
                int parentIndex = (index - 1) / 2;
                if (data.CompareTo(_arr[parentIndex]) < 0)
                {
                    _arr[index] = _arr[parentIndex];
                    _arr[parentIndex] = data;
                    index = parentIndex;
                }
                else
                {
                    break;
                }
            }
        }
    }
   
}
