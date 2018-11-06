using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp2
{
    public class Rac{
        int calc_mcd()
        {
            int M, N, tmp, MCD;
            /*si numerador!=0 y denominador!=0, usar Algoritmo de Euclides*/
            if ((n != 0) && (d != 0))
            {
                if (n > d)
                {
                    M = Math.Abs(n); N = Math.Abs(d);
                }
                else
                {
                    M = Math.Abs(d); N = Math.Abs(n);
                }/* ALGORITMO DE EUCLIDES (300 a.C.) */
                while ((tmp = M % N) != 0)
                { /* M = QN + tmp */
                    M = N;
                    N = tmp;
                }/*cuando este while termina, en N se tiene el mcd*/
                MCD = N;
            }
            else
            {/*si no, hacer mcd=1*/
                MCD = 1;/*Para evitar problemas cuando n=0 o d=0*/
            }
            return MCD;
        }

        void set_mcd(int MCD)
        {
            mcd = MCD;
        }

        public static Rac operator+(Rac r1,Rac RacObj)
        {
            Rac  RacResult = new Rac(r1.n * RacObj.d + r1.d * RacObj.n,
                r1.d * RacObj.d);
            RacResult.set_mcd(RacResult.calc_mcd());
            RacResult.simplificar();
            return RacResult;
        }
        public static Rac operator -(Rac r1, Rac RacObj)
        {
            Rac RacResult = new Rac(r1.n * RacObj.d - r1.d * RacObj.n,
                r1.d * RacObj.d);
            RacResult.set_mcd(RacResult.calc_mcd());
            RacResult.simplificar();
            return RacResult;
        }
        public static Rac operator *(Rac r1, Rac RacObj)
        {
            Rac  RacResult = new Rac(r1.n * RacObj.n,
                r1.d * RacObj.d);
            RacResult.set_mcd(RacResult.calc_mcd());
            RacResult.simplificar();
            return RacResult;

        }
        public static Rac operator /(Rac r1,Rac RacObj)
        {
            //Rac RacR;
            Rac  RacResult = new Rac();
            RacResult.n = r1.n * RacObj.d;
            RacResult.d = r1.d * RacObj.n;
            RacResult.set_mcd(RacResult.calc_mcd());
            RacResult.simplificar();
            return RacResult;
        }

        public Rac()
        {
            mcd = 1;
        }
        public Rac(int intNum, int intDen)
        {
            n = intNum;
            d = intDen;
            set_mcd(calc_mcd());
        }

        void simplificar()
        {
            n = n / mcd;
            d = d / mcd;
            if ((n < 0) && (d < 0))
            {
                n = -n;d = -d;
            }
            if (n == 0)
            {
                d = 1;
            }
        }
        public void set_n(int N)
        {
            n = N;
        }
        public void set_d(int D)
        {
            d = D;
        }
        public int get_n()
        {
            return n;
        }
        public int get_d()
        {
            return d;
        }

        int n;      /* numerador */
        int d;      /* denominador*/
        int mcd;	/* m\'aximo com\'un divisor*/
    }//end class
}//end namespace
