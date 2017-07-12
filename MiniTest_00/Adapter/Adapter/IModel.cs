using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Adapter
{
    /// <summary>
    /// モデルのインターフェースを定義。
    /// </summary>
    interface IModel
    {
        /// <summary>
        /// 読み込み処理。
        /// </summary>
        void Load(string modelName);
        /// <summary>
        /// 描画。
        /// </summary>
        void Draw();
        /// <summary>
        /// プリレンダー。
        /// </summary>
        void PreDraw();
        /// <summary>
        /// ポストレンダー。
        /// </summary>
        void PostDraw();
    }
}
