using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Adapter
{
    class ModelDX
    {
        public void Draw()
        {
            Console.WriteLine("DirectX Draw!!!");
        }
        public void BeginDraw()
        {
            Console.WriteLine("DirectX PreDraw!!!");
        }
        public void EndDraw()
        {
            Console.WriteLine("DirectX PostDraw!!!");
        }
    }
}
