using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Adapter
{
    class snModelPS4
    {
        /// <summary>
        /// ロード
        /// </summary>
        public void snLoad()
        {
            Console.WriteLine("LoadPS4!!!");
        }
        /// <summary>
        /// 描画
        /// </summary>
        public void snDraw()
        {
            Console.WriteLine("DrawPS4!!!");
        }
        /// <summary>
        /// プリレンダー。
        /// </summary>
        public void snBeginDraw()
        {
            Console.WriteLine("PS4 beginDraw!!!");
        }
        /// <summary>
        /// ポストレンダー0。
        /// ほとんどのケースでポストレンダーを完了させるためにはsnEndDraw_0とsnEndDraw_1を続けて呼び出す必要があります。
        /// 特殊なケースでsnEndDraw_1だけ呼びたい場合があるので、snEndDraw0とsnEndDraw1で分かれています。
        /// </summary>
        public void snEndDraw_0()
        {
            Console.WriteLine("PS4 endDraw_0!!!");
        }
        /// <summary>
        /// ポストレンダー1。
        /// ほとんどのケースでポストレンダーを完了させるためにはsnEndDraw_0とsnEndDraw_1を続けて呼び出す必要があります。
        /// 特殊なケースでsnEndDraw_1だけ呼びたい場合があるので、snEndDraw0とsnEndDraw1で分かれています。
        /// </summary>
        public void snEndDraw_1()
        {
            Console.WriteLine("PS4 endDraw_1!!!");
        }
    }
}
