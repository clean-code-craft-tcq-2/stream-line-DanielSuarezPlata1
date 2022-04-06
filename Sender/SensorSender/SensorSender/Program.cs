using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.IO;
using System.Reflection;
using System.Text.Json;

namespace SensorSender
{
    public static class Program
    {
        [ExcludeFromCodeCoverage]
        static void Main(string[] args)
        {
            List<SensorData> sensorDataReadings = FetchSensorData();

            PrintSensorReadings(sensorDataReadings);


        }

        public static int PrintSensorReadings(List<SensorData> sensorDataReadings)
        {
            int numberOfReadingsPrinted = 0;

            foreach (var sensorReading in sensorDataReadings)
            {
                var readingInJson = GenerateJsonString(sensorReading);

                Console.WriteLine(readingInJson);

                numberOfReadingsPrinted += 1;
            }

            return numberOfReadingsPrinted;
        }

        public static List<SensorData> FetchSensorData()
        {
            List<SensorData> sensorDataReadings = new List<SensorData>();

            string path = Path.Combine(Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location), "SensorData.csv");

            using (var rd = new StreamReader(path))
            {
                while (!rd.EndOfStream)
                {
                    var row = rd.ReadLine().Split(',');

                    sensorDataReadings.Add( new SensorData { temperature = float.Parse(row[0]), stateOfCharge = float.Parse(row[1]) });

                }
            }

            return sensorDataReadings;
        }

        public static string GenerateJsonString (SensorData sensorReading)
        {
            string sensorDataReadingJson = JsonSerializer.Serialize(sensorReading);

            return sensorDataReadingJson;
        }
    }
}
