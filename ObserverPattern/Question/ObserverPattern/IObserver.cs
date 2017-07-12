using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ObserverPattern
{
    /// <summary>
    /// 観察者
    /// </summary>
    interface IObserver
    {
        /// <summary>
        /// 観察対象に変化があったときに呼ばれる処理。
        /// </summary>
        /// <param name="subject"></param>
        void Update(Subject subject);
    }
}
