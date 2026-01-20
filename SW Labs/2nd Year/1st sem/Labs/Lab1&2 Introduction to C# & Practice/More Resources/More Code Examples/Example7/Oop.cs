using System;

namespace Example7
{
    class Shape
    {
        protected int width, height;
        public Shape(int w = 0, int h = 0)
        {
            width = w;
            height = h;
        }
        public virtual int area()
        {
            Console.WriteLine("Parent Class Area");
            return 0;
        }
    }
    class Rectangle : Shape
    {
        public Rectangle(int w = 0, int h = 0) : base(w, h)
        {
        }
        public override int area()
        {
            Console.WriteLine("Rectangle Class Area: ");
            return width * height;
        }
    }
    class Oop
    {
        static void Main(string[] args)
        {
            Rectangle r1 = new  Rectangle(2, 4);
            Console.WriteLine(r1.area());
        }
    }
}
