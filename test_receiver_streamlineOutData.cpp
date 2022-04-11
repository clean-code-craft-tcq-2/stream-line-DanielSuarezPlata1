// Test driven Development. -> Define the testcase before implementation.
#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "Receiver/receive_Streaming_BMS_values.h"

TEST_CASE("Test whether sensor inputs can be read from text file")
{
  REQUIRE(readSensorDataFromConsole("./Receiver/sensorStreamlineOutData.txt") == true);
}

TEST_CASE("Test whether sensor inputs can not be read from text file")
{
  REQUIRE(readSensorDataFromConsole("./Receiver/emptyfile.txt") == false);
}

TEST_CASE("Test SMA for Temp")
{
  float temp[5] = {12.5, 22.3, 30.4, 42.6, 44.2};
  REQUIRE(calculateSMA(temp, 5) == 30.4f);
}

TEST_CASE("Test SMA for SOC")
{
  float soc[5] = {22.1, 22.3, 30.4, 50.9, 75.2};
  REQUIRE(calculateSMA(soc, 5) == 40.18f);
}

TEST_CASE("Test min element in temp")
{
  float temp[5] = {12.5, 22.3, 30.4, 42.9, 44.2};
  REQUIRE(findMinInStream(temp, 5) == 12.5f);
}

TEST_CASE("Test max element in temp")
{
  float temp[5] = {12.5, 22.3, 30.4, 42.9, 44.2};
  REQUIRE(findMaxInStream(temp, 5) == 44.2f);
}

TEST_CASE("Test min element in soc")
{
  float soc[5] = {22.1, 22.3, 30.4, 50.9, 75.2};
  REQUIRE(findMinInStream(soc, 5) == 22.1f);
}

TEST_CASE("Test max element in soc")
{
  float soc[5] = {22.1, 22.3, 30.4, 50.9, 75.2};
  REQUIRE(findMaxInStream(soc, 5) == 75.2f);
}
