using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ObserverPattern
{
    /// <summary>
    /// プレイヤー
    /// </summary>
    class Player 
    {
        enum State
        {
            Idle,
            Run,
            Walk,
            Attack,
            Damage,
            Dead,
            Num
        };
        State state = State.Idle;
        Random random = new Random();
        /// <summary>
        /// プレイヤーのステートが変更されたときのデリゲート。
        /// </summary>
        /// <param name="pl"></param>
        public Action<Player> onChangeState { get; set; }
        /// <summary>
        /// 現在のステートを表示。
        /// </summary>
        void DrawState()
        {
            Console.WriteLine(state.ToString());
        }
        /// <summary>
        /// 更新処理。
        /// </summary>
        public void Update()
        {
            if(state == State.Dead)
            {
                return;
            }
            //ステートを描画。
            DrawState();
            //現在のステートのバックアップを取る。
            State oldState = state;
            //ランダムでステートを変える。
            if (random.Next() % 5 == 0)
            {
                state = (State)(random.Next() % (int)State.Num);
            }
            //状態が変わった？
            if (state != oldState)
            {
                //状態が変わった。
                //オブサーバーに通知する。
                if (onChangeState != null)
                { 
                    onChangeState(this);
                }
            }
        }
    }
}
