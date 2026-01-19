using System;

namespace Example2
{
    class Strings
    {
        static void Main(string[] args)
        {
            string s1 = "Hello";
            string s2 = s1;  // Both s1 and s2 refer to the same string
            s1 = "World";   // s1 now points to a new string in memory, s2 remains unchanged
            Console.WriteLine("s1: {0}", s1);
            Console.WriteLine("s2: {0}", s2);
        }
    }
}
