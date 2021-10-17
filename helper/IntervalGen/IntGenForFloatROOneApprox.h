#pragma once
#include "Common.h"
#include <string>
#include <queue>
#include <map>
#include <cstdio>
#include "unistd.h"
mpfr_t mval;

int fileIndex = 0;

/*################################################
 Helper function declaration begin
 ################################################*/

// Take a 34-bit floating point value in double representation and convert it to
// a 34-bit floating point binary representation
unsigned long ValToBinary34Bit(double);

// Compute the rounding interval for a float value passed by argument 1. Lb and
// Ub are returned in 2nd and 3rd argument, respectively
// Argument 1   (double) : A 34-bit ro floating point representation in double
// Argument 2   (double) : lb of rounding interval
// Argument 3   (double) : ub of rounding interval
int CalculateInterval(double, double&, double&);

// Error message when the initial guess on lb and ub leads to a result that is
// outside of the rounding interval
void CalcRedIntErrorMsg1(double, double, double, double, double, double);

// Create a new temporary file name based on the largeFileName that is passed
// Argument 1   (string) : a filename used to create a new temporary file name
// return value (string) : a new temporary file name
string GetNewFileName(string largeFileName);

// Copy data from source array to dest array. very simple helper function
void CopyData(double dest[3], double source[3]);

// Read 3 doubles from f. A simple helper function to include some sanity check
bool ReadData(FILE* f, double dest[3]);

// Writes a map of intervals to a file specified by newFileName
// Argument 1   (map)    : a map containing reduced inputs and intervals
// Argument 2   (string) : name of the file to write the reduced inputs and
//                         interval information into.
void SaveIntervalsToAFile(std::map<double, IntData> intervals,
                          string newFileName);

/*################################################
 Helper function declaration end
 ################################################*/

// Description of an elementary function for 32-bit float math library. This
// class should be used if the output compensation function uses 1 approximation
// MpfrCalculateFunction, ComputeSpecialCase, RangeReduction,
// OutputCompensation, GuessInitialLbUb, SpecCaseRedInt must be implemented per
// elementary function.
class IntervalGenerator {
    public :
    
    // Defines the special case inputs. Accepts original input x. Returns
    // whether the input is a special case and f(x) for the input x.
    // Argument 1   (float)   : original input x
    // return value (bool)    : whether x is special case or not
    // return value (double&) : returned via argument 2. the result of f(x) if
    //                        x is a special case input
    bool ComputeSpecialCase(float, double&);
    
    // Range reduction function. Accepts original input x and returns the
    // reduced input x'
    // Argument 1   (double) : original input x
    // return value (double) : reduced input x'
    double RangeReduction(float);
    
    // Output compensation function. Accepts y' and original input x and returns
    // the actual output y
    // Argument 1   (double) : original input x
    // Argument 2   (double) : y' = P(x')
    // return value (double) : approximation of f(x)
    double OutputCompensation(float, double);
    
    // Provides an initial guess on what the reduced interval should be. This
    // function should be used when output compensation function only uses one
    // approximation function.
    // Argument 1   (double) : reduced input x
    // return value (double) : via argument 2. the lb of reduced interval
    // return value (double) : via argument 3. the ub of reduced interval
    void GuessInitialLbUb(double, double, double, double, double&, double&);
    
    // In some cases, we may need special treatment for the reduced interval.
    // This function is used to specify whether we should treat the reduced
    // interval as a special case. In that case, the function should return true
    // and also pass the customized [lb, ub] of the reduced input.
    // Argument 1   (double) : original input x
    // Argument 2   (double) : initial lb guess for reduced interval
    // return value (bool)   : returned as argument 3. whether the lb is a
    //                         special case
    // return value (double) : returned as argument 4. Lb of reduced input
    // Argument 5   (double) : initial ub guess for reduced interval
    // return value (bool)   : returned as argument 6. whether the ub is a
    //                         special case
    // return value (double) : returned as argument 7. Ub of reduced input
    void SpecCaseRedInt(float, double, bool&, double&, double, bool&, double&);
    
    // Computes reduced intervals from xlow to xhigh. If xlow > xhigh, then we
    // compute reduced intervals from 0 to 0x100000000. The reduced intervals are
    // added to the file since it is theoretically possible to have 2^32 reduced
    // intervals
    // Argument 1   (ull)   : the lower bound of input domain x
    // Argument 2   (ull)   : the upper bound of input domain x
    // Argument 3   (FILE*) : to store the reduced inputs and range
    // * Note: Function adds reduced input, reduced interval lower bound, and
    //         upperbound in filename. Thus, each input will add 24 bytes to the
    //         file. The resulting file will have duplicate reduced inputs.
    void ComputeReducedIntervals(unsigned long long, unsigned long long,
                                 FILE*, FILE*);
    
    // Computes reduced interval for one input x. The reduced intervals are
    // added to the file
    // Argument 1   (float) : original input x
    // Argument 2   (FILE*) : file in which we write reduced input and interval
    void ComputeReducedInterval(float, double, FILE*);
    
    // Based on special case, range reduction, and output compensation function
    // create a file containing reduced inputs and reduced intervals. This file
    // contains merged reduced intervals sorted by reduced input.
    // Argument 1   (char*) : the name of the file to store reduced inputs and
    //                        intervals
    void CreateReducedIntervalFile(char*, char*);

    // Based on special case, range reduction, and output compensation function
    // create a file containing reduced inputs and reduced intervals. This file
    // contains merged reduced intervals sorted by reduced input.
    // Argument 1   (ull)   : lower bound of the input domain
    // Argument 2   (ull)   : upper bound of the input domain
    // Argument 3   (char*) : the name of the file to store reduced inputs and
    //                        intervals
    void CreateReducedIntervalFile(unsigned long long, unsigned long long,
                                   char*, char*);
    
    // Given a file with filename that contains reduced inputs and intervals,
    // merge same reduced inputs and sort them by reduced input.
    // It uses a type of merge sort. This function will also create several
    // temporary files.
    void SortIntervalFile(string, string);
    
    // Given two filenames, take reduced inputs and intervals and merge them
    // in an ascending order by inputs. Then save it to a file with the
    // third filename
    // Argument 1   (string) : a file containing reduced inputs and intervals
    // Argument 2   (string) : another file containing reduced inputs and
    //                         intervals
    // Argument 3   (string) : A file with emrged inputs and intervalss
    void MergeFiles(string, string, string);
};

/*################################################
 Class function implementation
 ################################################*/

void IntervalGenerator::CreateReducedIntervalFile(char* filename, char* oracleFile) {
    CreateReducedIntervalFile(0x0llu, 0x100000000llu, filename, oracleFile);
}

void IntervalGenerator::CreateReducedIntervalFile(unsigned long long xlow,
                                                  unsigned long long xhigh,
                                                  char* filename, char* oracleFile) {
  // Sanity check files
  if(access(oracleFile, F_OK ) != 0 ) {
    printf("Oracle file does not exist\n");
    exit(0);
  }

  if(access(filename, F_OK ) == 0 ) {
    printf("Reduced interval file already exists. Exiting to be safe\n");
    exit(0);
  }
  
  string fileNameString = filename;
  string largeFileName = fileNameString.append("_large");
  
  FILE* largeFile = fopen(largeFileName.c_str(), "w+");
  FILE* of = fopen(oracleFile, "r+");
  // Initially create a file with all the reduced inputs and intervals
  ComputeReducedIntervals(xlow, xhigh, largeFile, of);
  fclose(of);
  fclose(largeFile);
  
  // Sort the interval file and create a file named "filename"
  SortIntervalFile(largeFileName, filename);
  remove(largeFileName.c_str());
}

void IntervalGenerator::SortIntervalFile(string source, string dest) {
    std::map<double, IntData> intervals;
    std::map<double, IntData>::iterator it;
    std::queue<string> tempFiles;
    
    FILE* f = fopen(source.c_str(), "r+");
    if (!f) {
        printf("Could not open file\n");
    }
    double data[3];
    
    // Read intervals into sorted map. Output intervals to temp files, 40M
    // intervals at a time.
    unsigned long long int counter = 0;
    printf("Reading files and splitting to 40million intervals at a time\n");
    while (fread(data, sizeof(double), 3, f) == 3) {
        if (data[1] <= -1.0e300 && data[2] >= 1.0e300) {
            
	} else {
	  /*
	  printf("data[0] = %.100e\n", data[0]);
	  printf("data[1] = %.100e\n", data[1]);
	  printf("data[2] = %.100e\n", data[2]);
	  */
            it = intervals.find(data[0]);
            if (it != intervals.end()) {
                if (data[1] > it->second.lb) it->second.lb = data[1];
                if (data[2] < it->second.ub) it->second.ub = data[2];
            } else {
                IntData temp;
                temp.lb = data[1];
                temp.ub = data[2];
                intervals[data[0]] = temp;
	    }
        }
        
        counter++;
        if (counter % 1000000llu == 0llu) {
            printf("counter = %llu, interval.size() = %lu\r", counter, intervals.size());
            fflush(stdout);
        }
        
        // If there's 40M intervals, then save intervals to a temp file.
        if (intervals.size() == 40000000) {
            printf("Writing a new file\n");
            string newFileName = GetNewFileName(source);
            SaveIntervalsToAFile(intervals, newFileName);
            tempFiles.push(newFileName);
            intervals.clear();
            printf("Done writing a new file\n");
        }
    }
    
    fclose(f);
    
    // If there's anything else left, then save leftover to a temp file.
    if (intervals.size() > 0) {
        string newFileName = GetNewFileName(source);
        SaveIntervalsToAFile(intervals, newFileName);
        tempFiles.push(newFileName);
        intervals.clear();
    }
        
    // Once we created temp files, we read two files at a time from the queue,
    // and combine them. Delete the two old files. Add the new file to the queue.
    while (tempFiles.size() > 1) {
        string tempFile1 = tempFiles.front();
        tempFiles.pop();
        string tempFile2 = tempFiles.front();
        tempFiles.pop();
        string newFileName = GetNewFileName(source);
        MergeFiles(tempFile1, tempFile2, newFileName);
        remove(tempFile1.c_str());
        remove(tempFile2.c_str());
        
        tempFiles.push(newFileName);
        printf("Merged %s and %s to %s\n",
               tempFile1.c_str(),
               tempFile2.c_str(),
               newFileName.c_str());
    }
    
    // If there is only one file left in the queue, then we rename it to filename
    string tempFile1 = tempFiles.front();
    tempFiles.pop();
    rename(tempFile1.c_str(), dest.c_str());
}

void IntervalGenerator::MergeFiles(string s1, string s2, string d) {
    FILE* f1 = fopen(s1.c_str(), "r");
    FILE* f2 = fopen(s2.c_str(), "r");
    FILE* fd = fopen(d.c_str(), "w");
    
    int f1Read = 0, f2Read = 0;
    double toAdd[3], f1data[3], f2data[3];
    bool f1More, f2More;
    
    // Initialize the data:
    f1More = ReadData(f1, f1data);
    f2More = ReadData(f2, f2data);
    
    if (f1data[0] < f2data[0]) CopyData(toAdd, f1data);
    else CopyData(toAdd, f2data);
    unsigned counter = 0;
    
    while(true) {
        counter++;
        if (counter >= 1000000) {
            printf("Working with lines %d, %d\r", f1Read, f2Read);
            counter = 0;
        }
        
        if (f1More && f1data[0] == toAdd[0]) {
            if (f1data[1] > toAdd[1]) toAdd[1] = f1data[1];
            if (f1data[2] < toAdd[2]) toAdd[2] = f1data[2];
            f1More = ReadData(f1, f1data);
            f1Read++;
            continue;
        }
        if (f2More && f2data[0] == toAdd[0]) {
            if (f2data[1] > toAdd[1]) toAdd[1] = f2data[1];
            if (f2data[2] < toAdd[2]) toAdd[2] = f2data[2];
            f2More = ReadData(f2, f2data);
            f2Read++;
            continue;
        }
        
        // At this point, both f1data[0] and f2data[0] > toAdd[0]. I need to
        // add toAdd[0] to fd file.
        fwrite(toAdd, sizeof(double), 3, fd);
        
        // Now we need to decide to add either f1data or f2data to toAdd:
        if (!f1More && !f2More) break;
        
        if (f1More && !f2More) {
            CopyData(toAdd, f1data);
            f1More = ReadData(f1, f1data);
            f1Read++;
        } else if (!f1More && f2More) {
            CopyData(toAdd, f2data);
            f2More = ReadData(f2, f2data);
            f2Read++;
        } else if (f1data[0] < f2data[0]) {
            CopyData(toAdd, f1data);
            f1More = ReadData(f1, f1data);
            f1Read++;
        } else {
            CopyData(toAdd, f2data);
            f2More = ReadData(f2, f2data);
            f2Read++;
        }
    }
    
    fclose(f1);
    fclose(f2);
    fclose(fd);
}

void IntervalGenerator::ComputeReducedIntervals(unsigned long long xlow,
                                                unsigned long long xhigh,
                                                FILE* file, FILE* oracleFile) {
  if (xlow > xhigh) {
    xlow = 0x0llu;
    xhigh = 0x100000000llu;
  }
  
  unsigned long long int inputX;
  for (inputX = xlow; inputX < xhigh; inputX++) {
    if (inputX % 1000000 == 0) {
      printf("inputX = %llu\r", inputX);
      fflush(stdout);
    }
    floatX Xinput;
    Xinput.x = inputX;
    float input = Xinput.f;
    double oracleResult;
    size_t size = fread(&oracleResult, sizeof(double), 1, oracleFile);
    ComputeReducedInterval(input, oracleResult, file);
  }
  printf("\n");
}

void IntervalGenerator::ComputeReducedInterval(float input, double oracleResult,
                                               FILE* file) {
    // For each input, determine if it's special case or not. If it is, then
    // we continue to the next input
    double specialCaseResult;
    if (ComputeSpecialCase(input, specialCaseResult)) return;
    
    // Compute the correctly rounded result
    double corrResult = oracleResult;
    
    // Compute rounding interval
    double roundingLb, roundingUb;
    int stat = CalculateInterval(corrResult, roundingLb, roundingUb);
    if (stat == -1) {
        printf("Binary not even\n");
        printf("input = %.100e\n", input);
        exit(0);
    }
    
    if (stat == -2) {
        printf("Binary infinity/nan\n");
        printf("input = %.100e\n", input);
        exit(0);
    }

    if (roundingLb > corrResult || roundingUb < corrResult) {
      printf("Rounding interval seems to be computed wrongly.\n");
      printf("x            = %.100e\n", input);
      printf("oracleResult = %.100e\n", oracleResult);
      printf("roundingLb   = %.100e\n", roundingLb);
      printf("roundingUb   = %.100e\n\n", roundingUb);
      exit(0);
    }
    
    // Compute reduced input
    double reducedInput = RangeReduction(input);
    
    // Get the initial guess for Lb and Ub
    double guessLb, guessUb;
    GuessInitialLbUb(input, roundingLb, roundingUb, reducedInput, guessLb, guessUb);
    
    // 6. In a while loop, keep increasing lb and ub using binary search
    //    method to find largest reduced interval
    double redIntLb, redIntUb, tempResult;
    bool lbIsSpecCase = false, ubIsSpecCase = false;

    // Determine if there are any special case reduced interval lb/ub
    SpecCaseRedInt(input, guessLb, lbIsSpecCase, redIntLb,
                   guessUb, ubIsSpecCase, redIntUb);

    // If lb is not a special case, then we start from guessLb and try to
    // lower the lower bound as much as we can
    if (!lbIsSpecCase) {
      // Check if we can lower the lower bound more
      tempResult = OutputCompensation(input, guessLb);
      // If the initial guess puts us outside of rounding interval, there is
      // nothing more we can do
      if (tempResult < roundingLb || tempResult > roundingUb) {
          CalcRedIntErrorMsg1(input, roundingLb, roundingUb,
                              guessLb, guessUb, tempResult);
      }
      // Otherwise, we keep lowering lb and see if we are still inside the
      // rounding interval
      unsigned long long step = 0x10000000000000llu;
      while(step > 0) {
          doubleX dx;
          dx.d = guessLb;
          if (dx.d >= 0) {
            // if positive goes negative
            if (dx.x < step) {
              dx.x = 0x8000000000000000 + step - dx.x;
            } else dx.x -= step;
          }
          else dx.x += step;

        tempResult = OutputCompensation(input, dx.d);
      
        if (tempResult >= roundingLb && tempResult <= roundingUb) {
          // It's safe to lower the lb
          guessLb = dx.d;
        } else {
          // Otherwise decrease the step by half
          step /= 2;
        }
      }
        
      // Finally, set redIntLb
      redIntLb = guessLb;
    }
    
    // Similarly for lb, we do the same thing for ub
    if (!ubIsSpecCase) {
      // Check if we can increase the upper bound more
      tempResult = OutputCompensation(input, guessUb);
      // If the initial guess puts us outside of rounding interval, there is
      // nothing more we can do
      if (tempResult < roundingLb || tempResult > roundingUb) {
          CalcRedIntErrorMsg1(input, roundingLb, roundingUb,
                              guessLb, guessUb, tempResult);
      }
      // Otherwise, we keep lowering lb and see if we are still inside the
      // rounding interval
      unsigned long long step = 0x10000000000000llu;
      while(step > 0) {
        doubleX dx;
        dx.d = guessUb;
        if (dx.d >= 0) dx.x += step;
        else {
          // If we are negative and about to go positive:
          if (dx.x - step < 0x8000000000000000) {
            dx.x = 0x8000000000000000 - dx.x + step;
          } else {
            dx.x -= step;
          }
        }

        tempResult = OutputCompensation(input, dx.d);
        if (tempResult >= roundingLb && tempResult <= roundingUb) {
          // It's safe to lower the lb
          guessUb = dx.d;
        } else {
          // Otherwise decrease the step by half
          step /= 2;
        }
      }
        
      // Finally, set redIntLb
      redIntUb = guessUb;
    }
    
    // Save reduced input, lb, and ub to files.
    fwrite(&reducedInput, sizeof(double), 1, file);
    fwrite(&redIntLb, sizeof(double), 1, file);
    fwrite(&redIntUb, sizeof(double), 1, file);
}

/*################################################
 Helper function implementation
 ################################################*/
// s eeeeeeee x xxxx xxxx xxxx xxxx xxxx xxxx
unsigned long ValToBinary34Bit(double val) {
    doubleX dx;
    dx.d = val;
    unsigned long result = 0UL;
    
    // Extract sign and put it in 34th position from the right
    if ((dx.x & 0x8000000000000000UL) != 0UL) result = 0x200000000UL;
    
    // Extract exponent and put it in 33rd ~ 26th position from the right
    // val is a value in the 34-bit floating point. Thus, it will never be
    // denormal in terms of double. We can find the exponent value from val's
    // exponent values
    unsigned long expBit = (dx.x & 0x7FF0000000000000UL) >> (52UL);
    long exp = (long)expBit - 1023L;
    exp += 127;
    expBit = (unsigned long)exp;
    if (exp < 1L) expBit = 0x0UL;
    result |= (expBit << 25UL);
    
    // Extract mantissa and put it in 25th ~ 1st position from the right
    unsigned long mantissa = (dx.x & 0x000FFFFFFFFFFFFFUL) >> 27UL;
    // If it's denormalized value, then make it into denormal mantissa
    if (exp < 1L) {
        mantissa |= 0x2000000UL;
        // Figure out how many bits to shift right
        long shiftAmount = 1L - exp;
        mantissa >>= (unsigned long)shiftAmount;
    }
    result |= mantissa;
    return result;
}

double Binary34BitToVal(unsigned long binary) {
    // Take care of special cases
    // 1. zero
    if ((binary & 0x1FFFFFFFFUL) == 0UL) return 0.0;
    // 2. infinity
    if ((binary & 0x3FFFFFFFFUL) == 0x1FE000000UL) return 1.0 / 0.0;
    if ((binary & 0x3FFFFFFFFUL) == 0x3FE000000UL) return -1.0 / 0.0;
    // 3. NaN
    if ((binary & 0x1FE000000UL) == 0x1FE000000UL) return 0.0 / 0.0;
    
    // None special case
    doubleX result;
    result.x = 0UL;
    // 1. Separate out sign, exponent, mantissa
    unsigned long sign     = (binary & 0x200000000UL);
    unsigned long expBit   = (binary & 0x1FE000000UL) >> 25UL;
    unsigned long mantissa = (binary & 0x001FFFFFFUL);

    //printf("mantissa = %lx\n", mantissa);
    
    // 2. Set sign to result:
    if (sign != 0) result.x = 0x8000000000000000;
    
    // 3. Find exponent value and adjust expBit and mantissa accordingly
    if (expBit == 0UL) {
        // denormal value
        long expValue = -126L;
        // 0000 0000 0000 0000 0000 0000 0000 0000 0000 000x xxxx xxxx ...
        unsigned long movedMantissa = mantissa << 39UL;
	//printf("mantissa = %lx\n", movedMantissa);
        // Find out how many leading zeroes there are
        while ((movedMantissa & 0x8000000000000000UL) == 0UL) {
            expValue--;
            movedMantissa <<= 1UL;
	    //printf("mantissa = %lx\n", movedMantissa);
        }
        // Remove the leading 1
	expValue--;
        movedMantissa <<= 1UL;
	//printf("mantissa = %lx\n", movedMantissa);
        // Now MSB is the 1st mantissa bit. Move it towards where it needs to
        // be for a double representation
        mantissa = movedMantissa >> 12UL;
	//printf("mantissa = %lx\n", mantissa);
        expValue += 1023L;
        expBit = (unsigned long)expValue;
    } else {
        long expValue = (long)expBit;
        expValue -= 127L;
        expValue += 1023L;
        expBit = (unsigned long)expValue;
        mantissa <<= 27UL;
    }
    
    expBit <<= 52UL;
    
    // 4. Add expBit and mantissa to double representation
    //printf("expBit = %lx\n", expBit);
    //printf("mantissa = %lx\n", mantissa);
    result.x |= expBit;
    result.x |= mantissa;
    //printf("result.x = %lx\n", result.x);
    return result.d;
}

// Return value is status:
// 0  : success
// -1 : binary is even number
// -2 : return is infinity/NaN
int CalculateInterval(double x, double& lb, double& ub) {
    // 1. Convert double to a 34-bit binary representation
    unsigned long binary = ValToBinary34Bit(x);
    
    // Have to make sure that this binary is not even. We should have weeded
    // all of it out in the special case
    if ((binary & 0x1UL) == 0) return -1;
    
    // Binary should not be NaN or Infinity, because we should have taken care
    // of them in special cases as well
    // s1 1111 111x xxxx xxxx xxxx xxxx xxxx xxxx
    if ((binary & 0x1FE000000UL) == 0x1FE000000UL) return -2;

    if ((binary & 0x200000000UL) == 0) {
        // x is positive.
        // 2. Add +1 ulp
        unsigned long ubBinary = binary + 1UL;
        // 3. Convert that to double
        doubleX dx;
        dx.d = Binary34BitToVal(ubBinary);
        // 4. Subtract 1 ulp from double
        dx.x--;
        ub = dx.d;
        
        // 5. Subtract -1 ulp
        unsigned long lbBinary = binary - 1UL;
        // 6. Convert that to double
        dx.d = Binary34BitToVal(lbBinary);
        // 7. Add 1 ulp from double
        dx.x++;
        lb = dx.d;
    } else {
        // x is negative.
        // 2. Add +1 ulp
        unsigned long lbBinary = binary + 1UL;
        // 3. Convert that to double
        
        // 4. Subtract 1 ulp from double
        doubleX dx;
        dx.d = Binary34BitToVal(lbBinary);
        dx.x--;
        lb = dx.d;
        
        // 5. Subtract -1 ulp
        unsigned long ubBinary = binary - 1UL;
        // 6. Convert that to double
        
        // 7. Add 1 ulp from double
        dx.d = Binary34BitToVal(ubBinary);
        dx.x++;
        ub = dx.d;
    }
    
    return 0;
}

void CalcRedIntErrorMsg1(double input, double roundingLb, double roundingUb,
                         double guessLb, double guessUb, double tempResult) {
    printf("Initial guess resulted in a value outside of rounding interval\n");
    printf("Diagnostics:");
    printf("Input x = %.100e\n", input);
    printf("Rounding interval:\n");
    printf("lb      = %.100e\n", roundingLb);
    printf("ub      = %.100e\n", roundingUb);
    printf("Initial guess:\n");
    printf("lb      = %.100e\n", guessLb);
    printf("ub      = %.100e\n", guessUb);
    printf("output  = %.100e\n", tempResult);
    exit(0);
}

string GetNewFileName(string tfileName) {
    fileIndex++;
    return tfileName + "_temp" + std::to_string(fileIndex);
}

void SaveIntervalsToAFile(std::map<double, IntData> intervals,
                          string newFileName) {
    
    std::map<double, IntData>::iterator it;
    printf("Creating file %s\n", newFileName.c_str());
    FILE* tf = fopen(newFileName.c_str(), "w+");
    for (it = intervals.begin(); it != intervals.end(); it++) {
      fwrite(&(it->first), sizeof(double), 1, tf);
      fwrite(&(it->second.lb), sizeof(double), 1, tf);
      fwrite(&(it->second.ub), sizeof(double), 1, tf);
    }
    fclose(tf);
}

void CopyData(double dest[3], double source[3]) {
    for (int i = 0; i < 3; i++) dest[i] = source[i];
}

bool ReadData(FILE* f, double dest[3]) {
    size_t s = fread(dest, sizeof(double), 3, f);
    if (s == 0) return false;
    if (s == 3) return true;
    printf("ReadData needs to read 3 * double data. Seems like we couldn't.\n");
    exit(0);
}
