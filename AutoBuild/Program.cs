using System;

namespace AutoBuild
{
    class GenerateMakeFile
    {
        public static bool IsLinux
        {
            get
            {
                int p = (int) Environment.OSVersion.Platform;
                return (p == 4) || (p == 6) || (p == 128);
            }
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Starting AutoBuild");
            Console.WriteLine(Tools.OS.GetOSInfo);
        }
    }
}
