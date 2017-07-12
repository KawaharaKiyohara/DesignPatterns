using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace StatePattern
{
    class Program
    {
        static void Main(string[] args)
        {
            Enemy enemy = new Enemy();
            while (true)
            {
                enemy.Update();
             //   Console.Clear();
                Thread.Sleep(300);
            }
        }
    }
}
