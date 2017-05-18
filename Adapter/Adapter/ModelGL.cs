using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Adapter
{
    /// <summary>
    /// OpenGLのモデル表示クラス。
    /// </summary>
    class ModelGL
    {
        public void DrawGL()
        {
            Console.WriteLine("OpenGL Draw!!!");
        }
        public void PreDraw()
        {
            Console.WriteLine("DirectX PreDraw!!!");
        }
        public void PostDraw()
        {
            Console.WriteLine("DirectX PostDraw!!!");
        }
    }
}
