using System;

namespace Example4
{
    class Loops
    {
        static void Main(string[] args)
        {
            int[] arr = new int[3] { 1, 2, 3 };

            Console.WriteLine("Standard for loop:");
            for (int i = 0; i < arr.Length; ++i)
            {    
                Console.WriteLine(arr[i]);
            }

            Console.WriteLine("foreach loop:");
            foreach (int element in arr)
            {           
                Console.WriteLine(element);
            }
        }
    }
}
