using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StatePattern
{
    class EnemyStateIdle : IEnemyState
    {
        public void Enter()
        {
            Console.WriteLine("EnemyStateIdle.Enter!!!");
        }
        public void Leave()
        {
            Console.WriteLine("EnemyStateIdle.Leave!!!");
        }
        public void Update()
        {
            Console.WriteLine("EnemyStateIdle.Update!!!");
        }
    }
}
