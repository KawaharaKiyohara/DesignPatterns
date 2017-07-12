using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StatePattern
{
    /// <summary>
    /// エネミーの状態のインターフェースクラス。
    /// </summary>
    interface IEnemyState
    {
        /// <summary>
        /// 状態が始まるときに呼ばれる処理。
        /// </summary>
        void Enter();
        /// <summary>
        /// 状態を抜けるときに呼ばれる処理。
        /// </summary>
        void Leave();
        /// <summary>
        /// 毎フレーム呼ばれる更新処理。
        /// </summary>
        void Update();

    }
}
