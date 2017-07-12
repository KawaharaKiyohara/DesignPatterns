using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ObserverPattern
{
    /// <summary>
    /// サブジェクト(観察対象)
    /// </summary>
    class Subject
    {
        List<IObserver> observers = new List<IObserver>();      //観察者のリスト。
        /// <summary>
        /// 観察者をリストに追加。
        /// </summary>
        /// <param name="o">観察者</param>
        public void Attach(IObserver o)
        {
            observers.Add(o);
        }
        /// <summary>
        /// 観察者をリストから除去。
        /// </summary>
        /// <param name="o"></param>
        public void Detach(IObserver o)
        {
            observers.Remove(o);
        }
        /// <summary>
        /// 観察対象の状態に変化があったことを通知。
        /// </summary>
        public void Notify()
        {
            foreach( var o in observers)
            {
                o.Update(this);
            }
        }
    }
}
