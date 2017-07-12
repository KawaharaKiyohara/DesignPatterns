using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ObserverPattern
{
    /// <summary>
    /// ゲームメッセージクラス。
    /// </summary>
    class GameMessage : IObserver
    {
        /// <summary>
        /// ゲームオーバーメッセージ。
        /// </summary>
        public void GameOverMessage()
        {
            MessageBox.Show("ゲームオーバー");
        }
        /// <summary>
        /// 観察者の状態が変わったときに呼ばれる更新処理。
        /// </summary>
        /// <param name="s"></param>
        public void Update(Subject s)
        {
            GameOverMessage();
        }
    }
}
