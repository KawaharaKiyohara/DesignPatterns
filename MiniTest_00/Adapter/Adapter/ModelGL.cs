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
    class ModelGL : IModel
    {
        public void Load(string modelName)
        {
            Console.WriteLine("OpenGL Load");
        }
        public void Draw()
        {
            Console.WriteLine("OpenGL Draw!!!");
        }
        public void PreDraw()
        {
            Console.WriteLine("OpenGL PreDraw!!!");
        }
        public void PostDraw()
        {
            Console.WriteLine("OpenGL PostDraw!!!");
        }
    }
}
