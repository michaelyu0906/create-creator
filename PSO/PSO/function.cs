using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PSO
{
    public class function//一元n次函数
    {
        private double[] xi = new double[100];//第i次项系数
        private int n = 0;//最高为n次
        private double xn = 1;//x的n次幂
        public void append()//建立函数
        {
            Console.Write("请输入函数次数n(n<100):");
            this.n = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("请依次输入n次项的系数");
            for (int i = 0; i <= n; i++) 
            {
                Console.Write("x{0}:", i);
                this.xi[i] = Convert.ToDouble(Console.ReadLine());
                Console.WriteLine(this.xi[i]);
            }
            Console.WriteLine("输入完毕");
        }
        public double solution(double x)//求函数值
        {
            double y = 0;
            this.xn = 1;
            for (int i = 0; i <= n; i++)
            {
                y += xn * xi[i];
                xn *= x;
            }
            return y;
        }
    }
}
