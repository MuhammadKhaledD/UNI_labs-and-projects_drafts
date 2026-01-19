using System;

namespace Example5
{
    class Program
    {
        private static void passByValue(int item)
        { // passing by value
            item = 8;
        }

        private static void passByref(ref int item)
        { // passing by ref
            item = 8;
        }
        static void Main(string[] args)
        {
            int x = 5;
            passByValue(x);
            Console.WriteLine("x value after passByValue call: {0}", x);

            passByref(ref x);
            Console.WriteLine("x value after passByref call: {0}", x);
        }
    }
}
