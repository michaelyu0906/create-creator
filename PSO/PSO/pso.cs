using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PSO
{
    public class pso:function
    {
        private const int C1 = 2, C2 = 2;//学习因子为2
        private const int N = 100;//最大迭代次数为100
        private const double W = 0.8;//惯性权重设为0.8
        private const int PNum = 30;//散布30个粒子
        private double[] v = new double[PNum];//每个粒子速度
        private double vmax = 2;
        private Random r1 = new Random();
        private Random r2 = new Random();//定义随机数r1,r2
        private double[] pre = new double[PNum];//定义粒子当前位置
        private double[] pbest = new double[PNum];
        private double[] pbestIndex = new double[PNum];//定义pbest
        private double gbest;
        public double Gbest
        {
            get
            {
                return gbest;
            }
        }
        private double gbestIndex;//定义gbest
        public void Initialization()//对粒子群初始化 
        {
            Random r = new Random();
            this.pre[0] = r.NextDouble() * (this.xmax - this.xmin) + this.xmin;//随即位置撒点
            this.v[0] = r.NextDouble() * this.vmax;//随机速度
            this.pbest[0] = this.solution(this.pre[0]);
            this.pbestIndex[0] = this.pre[0];//初始化pbest
            this.gbest = this.pbest[0];
            this.gbestIndex = this.pbestIndex[0];//初始化gbest
            for (int i = 1; i < PNum; i++) 
            {
                this.pre[i] = r.NextDouble() * (this.xmax - this.xmin) + this.xmin;//随即位置撒点
                this.v[i] = r.NextDouble() * this.vmax;//随机速度
                this.pbest[i] = this.solution(this.pre[i]);
                this.pbestIndex[i] = this.pre[i];//初始化pbest
                if(this.pbest[i]>this.gbest)
                {
                    this.gbest = this.pbest[i];
                    this.gbestIndex = this.pbestIndex[i];//初始化gbest
                }
            }
        }
        public void calcu()//进行pso计算
        {
            for (int j = 0; j < N; j++)//迭代N次
            {
                for (int i = 0; i < PNum; i++)//对每个粒子进行迭代
                {
                    this.v[i] = this.v[i] * W + C1 * this.r1.NextDouble() * (this.pbestIndex[i] - this.pre[i])
                        + C2 * this.r2.NextDouble() * (this.gbestIndex - pre[i]);//更新速度
                    if (this.v[i] > vmax) v[i] = vmax;
                    if (this.v[i] < (vmax * (-1))) v[i] = vmax * (-1);
                    this.pre[i] = this.pre[i] + this.v[i];//更新位置
                    if (this.solution(this.pre[i]) > this.pbest[i])//更新pbest
                    {
                        this.pbest[i] = this.solution(this.pre[i]);
                        this.pbestIndex[i] = this.pre[i];
                        if (this.pbest[i] > this.gbest)//更新gbest
                        {
                            this.gbest = this.pbest[i];
                            this.gbestIndex = this.pbestIndex[i];
                        }
                    }
                }
            }
        }
    }
}
