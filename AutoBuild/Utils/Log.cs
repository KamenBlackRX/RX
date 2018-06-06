using System;
using Microsoft.Extensions.Logging;

namespace Utils.Log {
    public sealed class Log {
        //TO-DO implement Singleton class
        private static Log instance = new Log ();

        private static ILogger _logger;
    
        private Log () {
            
         }

        public static Log Instance () {
            return instance;
        }

        public static void ConfigureLogger () {
            LoggerExtensions.LogDebug(_logger, "Starting Configure Log");
        }

        public static void WriteToLog (string Message) {
            LoggerExtensions.LogDebug(_logger,Message);
        }

         public static void WriteToLog (string Message, string[] args) {
            LoggerExtensions.LogDebug(_logger,Message);
        }
    }
}