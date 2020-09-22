/*
Kaylee Chan
2348244
kaychan@chapman.edu
CPSC 350-03
Assignment 1

This assignment is used to calculate the statistics of a .txt file and output 1000 random DNA strings.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h> //used to import transform() method in order to make a string uppercase 
#include <stdlib.h>
#include <string.h>
#include <random>
using namespace std;

//Analysis class
class Analysis{
//public methods
public:
  Analysis();
  int sum(string input);
  float mean(string input);
  float variance(string input);
  float stdDeviation();
  float relProbA(string input);
  float relProbC(string input);
  float relProbT(string input);
  float relProbG(string input);
  double gaussianNum();

//private variables
private:
  float sumChar = 0;
  float numLines = 0;
  float numMean = 0;
  float Variance = 0;
  float deviation = 0;
  float probA = 0, probC = 0, probT = 0, probG = 0;
  float probofA, probofC, probofT, probofG;

};
