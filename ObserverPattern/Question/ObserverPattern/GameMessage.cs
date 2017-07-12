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
    class GameMessage
    {
        /// <summary>
        /// ゲームオーバーメッセージ。
        /// </summary>
        public void GameOverMessage()
        {
            MessageBox.Show("ゲームオーバー");
        }
    }
}
