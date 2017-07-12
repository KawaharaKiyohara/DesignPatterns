using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StatePattern
{
    class Enemy
    {
        IEnemyState state;
        Random random = new Random();
        /// <summary>
        /// コンストラクタ
        /// </summary>
        public Enemy()
        {
            state = new EnemyStateIdle();
            state.Enter();
        }
        /// <summary>
        /// 更新。
        /// </summary>
        public void Update()
        {
            if (random.Next() % 100 < 10)
            {
                //待機状態に遷移
                state.Leave();
                state = new EnemyStateIdle();
                state.Enter();
            }
            state.Update();
        }   
    }
}
