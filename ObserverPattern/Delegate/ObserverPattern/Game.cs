using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ObserverPattern
{
    class Game
    {
        /// <summary>
        /// Gameクラスのインスタンスのプロパティ。
        /// </summary>
        public static Game instance { get; private set; }
        /// <summary>
        /// プレイヤープロパティ
        /// </summary>
        public Player player { get; private set; }
        /// <summary>
        /// コンストラクタ。
        /// </summary>
        public Game()
        {
            instance = this;
        }
        /// <summary>
        /// ゲームループ。
        /// </summary>
        public void GameLoop()
        {
            player = new Player();
            //実習ヒント ゲームメッセージのインスタンスはすでに作成している。
            //後はこのインスタンスをオブサーバーとしてプレイヤーに追加すればいい。
            GameMessage gm = new GameMessage();
            player.onChangeState += gm.OnChangePlayerState;
            //ゲームループ。
            while (true)
            {
                player.Update();
                //100ミリ秒眠る。
                Thread.Sleep(100);
            }
        }
        
    }
}
