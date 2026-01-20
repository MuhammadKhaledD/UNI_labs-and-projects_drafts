using System;

namespace Example3
{
    class Arrays
    {
        static void Main(string[] args)
        {
            int[] arr = new int[3] { 1, 2, 3 };
            Console.WriteLine("3rd element: {0}", arr[2]);

            // Example of an array of arrays (jagged array)
            int[][] jaggedArray = new int[3][];
            // Initializing each array within the jagged array
            jaggedArray[0] = new int[] { 1, 2, 3 };    // 1st array with 3 elements
            jaggedArray[1] = new int[] { 4, 5 };       // 2nd array with 2 elements
            jaggedArray[2] = new int[] { 6, 7, 8, 9 }; // 3rd array with 4 elements
            // Accessing elements
            Console.WriteLine("element[0][1]: {0}", jaggedArray[0][1]);
            Console.WriteLine("element[2][3]: {0}", jaggedArray[2][3]);

            // Example of a 2D matrix (multidimensional array)
            int[,] matrix = new int[3, 3];
            // Initializing the matrix
            matrix[0, 0] = 1; matrix[0, 1] = 2; matrix[0, 2] = 3;
            matrix[1, 0] = 4; matrix[1, 1] = 5; matrix[1, 2] = 6;
            matrix[2, 0] = 7; matrix[2, 1] = 8; matrix[2, 2] = 9;
            // Accessing elements
            Console.WriteLine("matrix[0][1]: {0}", matrix[0, 1]);
            Console.WriteLine("matrix[2][2]: {0}", matrix[2, 2]);
        }
    }
}
