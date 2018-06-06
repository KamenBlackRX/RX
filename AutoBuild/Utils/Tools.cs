using System;
namespace Tools {

    public static class OS {
        public static string[] GetOSInfo {
            get {
                
                string[] resp = new string[5];
                
                resp[0] += Environment.OSVersion.ToString();
                
                int Plataform = (int) Environment.OSVersion.Platform;
                resp[1] += Plataform.ToString();
                
                return resp;
            }
            set {

            }

        }
    }
}