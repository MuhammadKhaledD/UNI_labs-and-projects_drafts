using System;

namespace Example6
{
    public class Book
    {
        // Properties
        public string Title { get; set; }
        public string Author { get; set; }
        public int PublicationYear { get; set; }

        // Constructor
        public Book(string title, string author, int publicationYear)
        {
            Title = title;
            Author = author;
            PublicationYear = publicationYear;
        }

        // Method to display book details
        public void DisplayInfo()
        {
            Console.WriteLine($"Publication Year: {PublicationYear}");
        }
    }
    class ClassObjects
    {
        private static void changeArrElement(int[] arr)
        {
            arr[2] = 4444;
        }
        private static void changePubYear(Book b)
        {
            b.PublicationYear = 2024;
        }
        static void Main(string[] args)
        {
            /* ============== Note ==============
               class object / array passed by reference by default (don't need to add ref)
               ===================================  */
            // class object
            Book book1 = new Book("The Edge", "George Orwell", 2000);
            book1.DisplayInfo();
            changePubYear(book1);
            book1.DisplayInfo();

            // array
            int[] arr = new int[3] { 1, 2, 3 };
            changeArrElement(arr);
            Console.WriteLine("arr[2]: {0}", arr[2]);
        }
    }
}
