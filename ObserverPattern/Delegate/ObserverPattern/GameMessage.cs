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
        /// <summary>
        /// プレイヤーの状態が変わったときに呼ばれる処理。
        /// </summary>
        /// <param name="pl"></param>
        public void OnChangePlayerState(Player pl)
        {
            GameOverMessage();
        }
    }
}
