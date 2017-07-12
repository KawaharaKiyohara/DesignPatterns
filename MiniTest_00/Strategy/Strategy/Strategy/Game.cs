using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Strategy
{
    class Game
    {
       
        enum EPlatform
        {
            DirectX,
            OpenGL,
            PS4
        };
        EPlatform platform;
        /// <summary>
        /// コンストラクタ
        /// </summary>
        /// <param name="pl">プラットフォーム</param>
        public Game()
        {
            Console.WriteLine("プラットフォームを選択してください。");
            Console.WriteLine("0:Windows、1:Mac、2:PS4");
            int pl = int.Parse(Console.ReadLine());
            if (pl == 0)
            {
                Console.WriteLine("ModelDX.Init");
                platform = EPlatform.DirectX;
            }
            else if(pl == 1)
            {
                Console.WriteLine("ModelGL.Init");
                platform = EPlatform.OpenGL;
            }
            else if(pl == 2)
            {
                Console.WriteLine("ModelPS4.Init");
                platform = EPlatform.PS4;
            }
        }
        /// <summary>
        /// 
        /// </summary>
        public void Update()
        {
            switch (platform) {
                case EPlatform.DirectX:
                    Console.WriteLine("ModelDX.Update");
                    break;
                case EPlatform.OpenGL:
                    Console.WriteLine("ModelGL.Update");
                    break;
                case EPlatform.PS4:
                    Console.WriteLine("ModelPS4.Update");
                    break;
            }
        }
        /// <summary>
        /// 描画
        /// </summary>
        public void Render()
        {
            switch (platform)
            {
                case EPlatform.DirectX:
                    Console.WriteLine("ModelDX.Render");
                    break;
                case EPlatform.OpenGL:
                    Console.WriteLine("ModelGL.Render");
                    break;
                case EPlatform.PS4:
                    Console.WriteLine("ModelPS4.Render");
                    break;
            }
        }
        /// <summary>
        /// プリレンダー。
        /// </summary>
        public void PreRender()
        {
            switch (platform)
            {
                case EPlatform.DirectX:
                    Console.WriteLine("ModelDX.PreRender");
                    break;
                case EPlatform.OpenGL:
                    Console.WriteLine("ModelGL.PreRender");
                    break;
                case EPlatform.PS4:
                    Console.WriteLine("ModelPS4.PreRender");
                    break;
            }
        }
        /// <summary>
        /// ポストレンダー。
        /// </summary>
        public void PostRender()
        {
            switch (platform)
            {
                case EPlatform.DirectX:
                    Console.WriteLine("ModelDX.PostRender");
                    break;
                case EPlatform.OpenGL:
                    Console.WriteLine("ModelGL.PostRender");
                    break;
                case EPlatform.PS4:
                    Console.WriteLine("ModelPS4.PostRender");
                    break;
            }
        }
    }
}
