/* test.cpp -- tests the prototype functions from file_utils.h

   If you want to use the functions from file_utils.c in multiple projects,
   it makes sense to compile this file into a library rather than an executable.
   Here's how you can change the output type for "Read And Write":

   1. Right-click on the "Read And Write" project in the Solution Explorer and select "Properties".
   2. Go to "Configuration Properties" > "General".
   3. Change "Configuration Type" to "Static library (.lib)".
   4. Click "OK" to apply the changes. 

	Ensure that the .lib file is linked by checking "Linker" > "Input" in the "File Tests" properties

	once done testing, its ok to set the configuration back to application(.exe)

	Compiling the c code into a satic library helps with compatability and linkage,
    when mixing c and cpp code.

 */

#include "pch.h"
#include "../Read And Write/file_utils.h"
#include <fstream>

// Test fixture class, if needed
class FileUtilsTest : public ::testing::Test {
protected:
    std::string tempFileName;

    // Setup code, if needed, runs before each test
    void SetUp() override {
        tempFileName = "./temp_test_file.txt";

        // Create and open a temporary file
        std::ofstream tempFile(tempFileName);
        ASSERT_TRUE(tempFile.is_open()) << "Error creating temporary file for test.";

        // Write some test data to the file
        tempFile << "Test data for file read.\n";
        tempFile << "Here's and extra line also...\n";
        tempFile.close();
    }

    // Teardown code, if needed, runs after each test
    void TearDown() override {
        remove(tempFileName.c_str());
    }
};


TEST_F(FileUtilsTest, ReadsFileCorrectly) {
    const int result = read_file(tempFileName.c_str());
    ASSERT_EQ(result, 0) << "Error: Failed to read file.\n";
}