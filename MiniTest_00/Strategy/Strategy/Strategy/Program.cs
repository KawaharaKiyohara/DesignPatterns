using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Strategy
{
    class Program
    {
        static void Main(string[] args)
        {

            //Gameのインスタンスを生成。
            Game game = new Game();
            //ゲームループ。
            while (true)
            {
                game.Update();
                game.PostRender();
                game.Render();
                game.PreRender();
            }
        }
    }
}
