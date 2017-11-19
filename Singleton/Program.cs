// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Singleton
{
    /// <summary>
    /// 只能用于单线程的版本
    /// </summary>
    public sealed class Singleton1
    {
        private Singleton1()
        {
        }

        private static Singleton1 instance = null;
        public static Singleton1 Instance
        {
            get
            {
                if (instance == null)
                    instance = new Singleton1();

                return instance;
            }
        }
    }


    /// <summary>
    /// 能够用于多线程，但是效率稍微低一点，因为每次get Instace的时候，都要加锁
    /// </summary>
    public sealed class Singleton2
    {
        private Singleton2()
        {
        }

        private static readonly object syncObj = new object();

        private static Singleton2 _instance = null;
        public static Singleton2 Instance
        {
            get
            {
                lock (syncObj)
                {
                    if (_instance == null)
                        _instance = new Singleton2();
                }

                return _instance;
            }
        }
    }

    /// <summary>
    /// 效率提升，每次先判断是否需要创建再加锁(因为其实就只是写的时候会出现创建多个，违背单例)
    /// </summary>
    public sealed class Singleton3
    {
        private Singleton3()
        {
        }

        private static object syncObj = new object();

        private static Singleton3 instance = null;
        public static Singleton3 Instance
        {
            get
            {
                if (instance == null)
                {
                    lock (syncObj)
                    {
                        if (instance == null)
                            instance = new Singleton3();
                    }
                }

                return instance;
            }
        }
    }


    /// <summary>
    /// 利用静态成员最先构造，很简单的方法也适用于多线程
    /// </summary>
    public sealed class Singleton4
    {
        private Singleton4()
        {
        }

        public static void Print()
        {
            Console.WriteLine("Singleton4 Print");
        }

        private static Singleton4 instance = new Singleton4();//静态成员是在静态构造函数里面进行初始化的，所以能够确保只运行一次，但是如果有任何一个静态方法过早调用，也会直接就创建了，所以有点浪费内存
        public static Singleton4 Instance
        {
            get
            {
                return instance;
            }
        }
    }

    /// <summary>
    /// 最终版本，这样就只有在用到Singleton5.Instance的时候才会创建对象了
    /// </summary>
    public sealed class Singleton5
    {
        Singleton5()
        {
        }

        public static void Print()
        {
            Console.WriteLine("Singleton5 Print");
        }

        public static Singleton5 Instance
        {
            get
            {
                return Nested.instance;
            }
        }

        class Nested
        {
            static Nested()
            {
            }

            internal static readonly Singleton5 instance = new Singleton5();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Singleton4.Print();
            Singleton5.Print();
        }
    }
}
