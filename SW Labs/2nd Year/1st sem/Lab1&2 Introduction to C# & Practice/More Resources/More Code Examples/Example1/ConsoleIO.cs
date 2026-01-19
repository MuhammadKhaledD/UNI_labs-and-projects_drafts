using System;

namespace Example1
{
    class ConsoleIO
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter your age:");
            int age = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Your age is {0}", age);
            Console.ReadKey();  // use if console terminates automatically
        }
    }
}
