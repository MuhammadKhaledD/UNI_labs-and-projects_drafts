using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication2
{
    

    class Program
    {
        private static void ChangeByValue(int itemValue)
        {
            itemValue = 5;
        }
        private static void ChangeByObject(Product itemRef)
        {
            itemRef.ItemID = 22222;
        }
        static void Main(string[] args)
        {
            int x = 13;
            Console.WriteLine("Before change {0}", x);
            ChangeByValue(x);

            Console.WriteLine("Changed Value of X is : {0}\n", x);
            Product item = new Product("Fasteners", 54321);
            Console.WriteLine("Original values in Main.  Name: {0}, ID: {1}\n",
                item.ItemName, item.ItemID);

            ChangeByObject(item);
            Console.WriteLine("Back in Main.  Name: {0}, ID: {1}\n",
                item.ItemName, item.ItemID);
            int[] array = { 1, 3, 5, 7 };
            foreach (int i in array)
            {
                Console.Write(i+" ");
            }
            Console.WriteLine();
            Console.WriteLine("Enter a number");
            string s = Console.ReadLine();
            try
            {
                if (Convert.ToInt32(s) > 10)
                {
                    Console.WriteLine("Thank you!");
                }
                else {
                    Console.WriteLine("?");
                }
            }
            catch (Exception e) {
                Console.WriteLine("Not a number");
            }
            Console.ReadKey();
        }
    }
}
