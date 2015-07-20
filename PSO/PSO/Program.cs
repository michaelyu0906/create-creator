using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PSO
{
    class Program
    {
        static void Main(string[] args)
        {
            var pso1 = new pso();
            pso1.append();
            pso1.Initialization();
            pso1.calcu();
            Console.WriteLine("最大值为：{0}", pso1.Gbest);
            Console.ReadLine();
        }
    }
}
