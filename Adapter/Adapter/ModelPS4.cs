using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Adapter
{
    class ModelPS4
    {
        public void DrawPS4()
        {
            Console.WriteLine("DrawPS4!!!");
        }
        public void PreDrawPS4()
        {
            Console.WriteLine("DirectX PreDraw!!!");
        }
        public void PostDrawPS4()
        {
            Console.WriteLine("DirectX PostDraw!!!");
        }
    }
}
