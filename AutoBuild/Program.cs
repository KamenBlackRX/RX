using System;
using Utils.Log;

namespace AutoBuild {
    class GenerateMakeFile {
        public static bool IsLinux {
            get {
                int p = (int) Environment.OSVersion.Platform;
                return (p == 4) || (p == 6) || (p == 128);
            }
        }

    }

    class Program {
        static void Main (string[] args) {
            //Log.Instance().WriteToLog("Initalizing program");
            Console.WriteLine ("Starting AutoBuild");
            Console.WriteLine ("Generic OS Name: " + Tools.OS.GetOSInfo[0]);
            Console.WriteLine ("Plataform Code: " + Tools.OS.GetOSInfo[1]);
            if(Tools.OS.GetOSInfo[0] == null) {
                Console.BackgroundColor = ConsoleColor.Red;
                Console.WriteLine("We cant continue, No plataform detected");
            }

        }
    }
}