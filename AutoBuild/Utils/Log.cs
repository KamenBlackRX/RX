using System;
using Microsoft.Extensions.Logging;

namespace Utils.Log {
    public sealed class Log {
        //TO-DO implement Singleton class
        private static Log instance = new Log ();

        private ILogger Logger;

        public ILogger Logger1 { get => Logger; set => Logger = value; }

        private Log (){
          
         }

        public static Log Instance () {
            return instance;
        }

        public void ConfigureLogger () {
            Logger1.LogDebug("Starting Configure Log");
        }

        public void WriteToLog (string Message) {
            Logger1.LogDebug(0xffff,ErrorLog(Message),Message);
        }

         public void WriteToLog (string Message, string[] args) {
            Logger1.LogDebug(0xffff,ErrorLog(Message),Message, args);
        }

        public Exception ErrorLog(object e){
            return new Exception(e.ToString());
        }
    }
}