using Microsoft.VisualStudio.TestTools.UnitTesting;
using SensorSender;
using System;
using System.Collections.Generic;
using System.Text;

namespace SensorSender.Tests
{
    [TestClass]
    public class ProgramTests
    {
        [TestMethod("Test to open file and receive a list with 50 readings")]
        public void FetchSensorDataTest()
        {
            List<SensorData> sensorReadings = Program.FetchSensorData();

            Assert.AreEqual(sensorReadings.Count, 50);
        }

        [TestMethod("Test to generate the string in a correct format")]
        public void GenerateJsonStringTest()
        {
            SensorData sensorData = new SensorData { temperature = 6, stateOfCharge = 39 };

            string sensorDataInJson = Program.GenerateJsonString(sensorData);

            string expectedString = "{\"temperature\":6,\"stateOfCharge\":39}";

            Assert.AreEqual(sensorDataInJson, expectedString);
        }

        [TestMethod("Test the number of readings printed")]
        public void PrintSensorReadingsTest()
        {
            List<SensorData> sensorReadings = Program.FetchSensorData();

            int numberOfReadingsPrinted = Program.PrintSensorReadings(sensorReadings);

            Assert.AreEqual(numberOfReadingsPrinted, 50);
        }
    }
}