/*
Kaylee Chan
2348244
kaychan@chapman.edu
CPSC 350-03
Assignment 1

This assignment is used to calculate the statistics of a .txt file and output 1000 random DNA strings.
*/
#include <cmath>
#include <math.h>
#include "assign1.h"

//default constructor
Analysis::Analysis(){
  sumChar = 0;
  numLines = 0;
  numMean = 0;
  Variance = 0;
  deviation = 0;
  probA = 0, probC = 0, probT = 0, probG = 0;
  probofA = 0, probofC = 0, probofT = 0, probofG = 0;
}

/*
sum method
returns an int of the sum of length of DNA strings
parameter - a string of the name of file to be opened
*/
int Analysis::sum(string filename){
  fstream readfile;
  readfile.open(filename, ios::in); //open a file to perform read operation using file object
  sumChar = 0.0;
  if (readfile.is_open()){  //checking whether the file is open
    string str;
    while(getline(readfile, str)){  //read data from file object and put it into string.
      sumChar += str.length();
    }
  readfile.close(); //close the file object.
  }
  return sumChar;
}

/*
mean method
returns a float of the mean of length of DNA strings
parameter - a string of the name of file to be opened
*/
float Analysis::mean(string filename){
  fstream readfile;
  readfile.open(filename, ios::in); //open a file to perform read operation using file object

  numLines = 0;
  numMean = 0;
  if (readfile.is_open()){   //checking whether the file is open
    string str;
    while(getline(readfile, str)){  //read data from file object and put it into string.
      numLines++;
    }
  numMean = sumChar/numLines;
  readfile.close(); //close the file object.
  }
  return numMean;
}

/*
variance method
returns a float of the variance of length of DNA strings
parameter - a string of the name of file to be opened
*/
float Analysis::variance(string filename){
  int eachStrLength = 0;
  float diff = 0;
  float numerator = 0;
  Variance =0;
  fstream readfile;
  readfile.open(filename, ios::in); //open a file to perform read operation using file object

  if (readfile.is_open()){   //checking whether the file is open
    string str;
    while(getline(readfile, str)){  //read data from file object and put it into string.
      eachStrLength = str.length();
      diff = abs(numMean -  eachStrLength);
      numerator += diff*diff;
    }
  Variance = numerator /numLines;
  readfile.close(); //close the file object.
  }
return Variance;
}

/*
standard deviation method
returns a float of the standard deviation of length of DNA strings
parameter - none
*/
float Analysis::stdDeviation(){
  deviation = sqrt(Variance);
  return deviation;
}

/*
relProb A method
returns a float of the relative probability of the letter A
parameter - a string of the name of file to be opened
*/
float Analysis::relProbA(string filename){
  int letterA = 0;
  fstream  readfile;
  readfile.open(filename, ios::in);

  if (readfile.is_open()){
    string str;
    //calculate probability of letter A
    while(getline(readfile, str)){
      for(int i = 0; i < str.length(); ++i){
        if(tolower(str[i]) == 'a'){
          letterA++;
        }
      }
    }
  probA = letterA / sumChar;
  readfile.close(); //close the file object.
  }
  return probA;
}

/*
relProbC method
returns a float of the relative probability of the letter C
parameter - a string of the name of file to be opened
*/
float Analysis::relProbC(string filename){
  int letterC = 0;
  fstream readfile;
  readfile.open(filename, ios::in); //open a file to perform read operation using file object

  if (readfile.is_open()){   //checking whether the file is open
    string str;
    //calculate probability of letter C
    while(getline(readfile, str)){  //read data from file object and put it into string.
      for(int i = 0; i < str.length(); ++i){
        if(tolower(str[i]) == 'c'){
          letterC++;
        }
      }
    }
  probC = letterC / sumChar;
  readfile.close(); //close the file object.
  }
  return probC;
}

/*
relProb T method
returns a float of the relative probability of the letter T
parameter - a string of the name of file to be opened
*/
float Analysis::relProbT(string filename){
  int letterT = 0;
  fstream  readfile;
  readfile.open(filename, ios::in); //open a file to perform read operation using file object

  if (readfile.is_open()){   //checking whether the file is open
    string str;
    //calculate probability of letter T
    while(getline(readfile, str)){  //read data from file object and put it into string.
      for(int i = 0; i < str.length(); ++i){
        if(tolower(str[i]) == 't'){
          letterT++;
        }
      }
    }
  probT = letterT / sumChar;
  readfile.close(); //close the file object.
  }
  return probT;
}

/*
relProb G method
returns a float of the relative probability of the letter G
parameter - a string of the name of file to be opened
*/
float Analysis::relProbG(string filename){
  int letterG= 0;
  fstream readfile;
  readfile.open(filename, ios::in); //open a file to perform read operation using file object

  if (readfile.is_open()){   //checking whether the file is open
    string str;
    //calculate probability of letter G
    while(getline(readfile, str)){  //read data from file object and put it into string.
      for(int i = 0; i < str.length(); ++i){
        if(tolower(str[i]) == 'g'){
          letterG++;
        }
      }
    }
  probG = letterG / sumChar;
  readfile.close(); //close the file object.
  }
  return probG;
}

/*
gaussianNum method
returns a double of a random generated number calculated using the Gaussian Distribution
parameter - none
*/
double Analysis::gaussianNum(){
  double a = 0.0, b = 0.0,c = 0.0, d = 0.0;
  //generate two random numbers [0,1)
    a = ((double) rand() / (RAND_MAX));
    b = ((double) rand() / (RAND_MAX));

    if( a!= 0){
      c = sqrt(-2 * log(a)) * (cos(2*M_PI*b));
      d = (deviation*c) + numMean;
    }else{
      return 0;
    }

    d = round(d);
    return d;
}
