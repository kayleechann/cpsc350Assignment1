/*
Kaylee Chan
2348244
kaychan@chapman.edu
CPSC 350-03
Assignment 1

This assignment is used to calculate the statistics of a .txt file and output 1000 random DNA strings.
*/
#include "assign1.h"

int main(int argc, char *argv[]){
  //declare instance of class
  Analysis word;
  //declaring instance of ifstream library
  fstream readfile;
  //declaring instance of ofstream library
  ofstream outfile;

  //error message for user
  if (argc < 2){
    cout << "Invalid command line arguments! Please enter a file name" << endl;
    return 0;
  }

  outfile.open("KayleeChan.txt");
  if(outfile.is_open()){
    outfile << "Kaylee Chan" << endl;
    outfile << "2348244" << endl;
    outfile << "kaychan@chapman.edu" << endl << endl;
  } else{
    cout << "Could not open file..." << endl;
  }

  int firstTime  = 0;
  while(true){
    string fileToProcess = "";
    //check if this is the first time running program
    if(firstTime == 0){
      //if first time running program, use command line argument to open the file
      fileToProcess = argv[1];
    }else{
      //if running program again, set fileToProcess to user input
      cout << "What is the .txt you would like to process?  (include '.txt' extension when entering the name) " <<endl;
      cin >> fileToProcess;
      outfile <<  "-------------------- PROCESSING ANOTHER FILE --------------------" << endl << endl;
    }

    outfile << "Sum:                   " << word.sum(fileToProcess) << endl;
    outfile << "Mean:                  " << word.mean(fileToProcess) << endl;
    outfile << "Variance:              " << word.variance(fileToProcess) << endl;
    outfile << "Standard Deviation:    " << word.stdDeviation() << endl;
    outfile << "Probability of A:      " <<  word.relProbA(fileToProcess) << endl;
    outfile << "Probability of C:      " <<  word.relProbC(fileToProcess) << endl;
    outfile << "Probability of T:      " <<  word.relProbT(fileToProcess) << endl;
    outfile << "Probability of G:      " <<  word.relProbG(fileToProcess) << endl;
    outfile << endl;

    //BIGRAM CALCULATIONS -----------------------------------------------------------------------------
    string bigram = "";
    string aa = "AA", ac = "AC", at = "AT", ag = "AG", ca = "CA", cc = "CC", ct = "CT", cg = "CG";
    string ta = "TA", tc = "TC", tt = "TT", tg = "TG", ga = "GA", gc = "GC", gt = "GT", gg = "GG";
    float bigramCombinations = 16.0;
    float counterAA = 0.0, counterAC = 0.0, counterAT = 0.0, counterAG = 0.0,  counterCA = 0.0, counterCC = 0.0, counterCT = 0.0, counterCG = 0.0;
    float counterTA = 0.0, counterTC = 0.0, counterTT = 0.0, counterTG = 0.0,  counterGA = 0.0, counterGC = 0.0, counterGT = 0.0, counterGG = 0.0;
    float probAA = 0, probAC = 0, probAT = 0, probAG = 0, probCA = 0, probCC = 0, probCT = 0, probCG = 0;

    readfile.open(fileToProcess, ios::in); //open a file to perform read operation using file object

    if (readfile.is_open()){   //checking whether the file is open
      string str;
      string bigram;
      int start = 0;
      int end = 2;
      while(getline(readfile, str)){
        //check if string is even
        if(str.length() % 2 ==0){
          for(int i  = 0; i <str.length(); ++i){
            //creating substrings to check bigrams
            bigram = str.substr(i, 2);
            transform(bigram.begin(), bigram.end(), bigram.begin(), ::toupper);
            if(bigram.compare(aa) == 0){ //AA
              counterAA++;
            }else if(bigram.compare(ac) == 0){ //AC
              counterAC++;
            }else if(bigram.compare(at) == 0){ //AT
              counterAT++;
            }else if(bigram.compare(ag) == 0){ //AG
              counterAG++;
            }else if(bigram.compare(ca) == 0){ //CA
              counterCA++;
            }else if(bigram.compare(cc) == 0){ //CC
              counterCC++;
            }else if(bigram.compare(ct) == 0){ //CT
              counterCT++;
            }else if(bigram.compare(cg) == 0){ //CG
              counterCG++;
            }else if(bigram.compare(ta) == 0){ //TA
              counterTA++;
            }else if(bigram.compare(tc) == 0){ //TC
              counterTC++;
            }else if(bigram.compare(tt) == 0){ //TT
              counterTT++;
            }else if(bigram.compare(tg) == 0){ //TG
              counterTG++;
            }else if(bigram.compare(ga) == 0){ //GA
              counterGA++;
            }else if(bigram.compare(gc) == 0){ //GC
              counterGC++;
            }else if(bigram.compare(gt) == 0){ //GT
              counterGT++;
            }else if(bigram.compare(gg) == 0){ //GG
              counterGG++;
            }else{
              //empty
            }
            i++;
          }//end of for loop
        }else{
          //if string is odd, only make bigrams up to str.length() -1
          for(int i = 0; i < (str.length() - 1); ++i){
            bigram = str.substr(i, 2);
            transform(bigram.begin(), bigram.end(), bigram.begin(), ::toupper);
            if(bigram.compare(aa) == 0){ //AA
              counterAA++;
            }else if(bigram.compare(ac) == 0){ //AC
              counterAC++;
            }else if(bigram.compare(at) == 0){ //AT
              counterAT++;
            }else if(bigram.compare(ag) == 0){ //AG
              counterAG++;
            }else if(bigram.compare(ca) == 0){ //CA
              counterCA++;
            }else if(bigram.compare(cc) == 0){ //CC
              counterCC++;
            }else if(bigram.compare(ct) == 0){ //CT
              counterCT++;
            }else if(bigram.compare(cg) == 0){ //CG
              counterCG++;
            }else if(bigram.compare(ta) == 0){ //TA
              counterTA++;
            }else if(bigram.compare(tc) == 0){ //TC
              counterTC++;
            }else if(bigram.compare(tt) == 0){ //TT
              counterTT++;
            }else if(bigram.compare(tg) == 0){ //TG
              counterTG++;
            }else if(bigram.compare(ga) == 0){ //GA
              counterGA++;
            }else if(bigram.compare(gc) == 0){ //GC
              counterGC++;
            }else if(bigram.compare(gt) == 0){ //GT
              counterGT++;
            }else if(bigram.compare(gg) == 0){ //GG
              counterGG++;
            }else{
              //empty
            }
            i++;
            //empty the bigram string
            bigram = "";
          }//end of for loop

          //since we left off from the odd string,
          bigram += str[str.length()-1];
          bigram += (str[0]);
          if(bigram.compare(aa) == 0){ //AA
            counterAA++;
            //outfile << counterAA << endl;
          }else if(bigram.compare(ac) == 0){ //AC
            counterAC++;
          }else if(bigram.compare(at) == 0){ //AT
            counterAT++;
          }else if(bigram.compare(ag) == 0){ //AG
            counterAG++;
          }else if(bigram.compare(ca) == 0){ //CA
            counterCA++;
          }else if(bigram.compare(cc) == 0){ //CC
            counterCC++;
          }else if(bigram.compare(ct) == 0){ //CT
            counterCT++;
          }else if(bigram.compare(cg) == 0){ //CG
            counterCG++;
          }else if(bigram.compare(ta) == 0){ //TA
            counterTA++;
          }else if(bigram.compare(tc) == 0){ //TC
            counterTC++;
          }else if(bigram.compare(tt) == 0){ //TT
            counterTT++;
          }else if(bigram.compare(tg) == 0){ //TG
            counterTG++;
          }else if(bigram.compare(ga) == 0){ //GA
            counterGA++;
          }else if(bigram.compare(gc) == 0){ //GC
            counterGC++;
          }else if(bigram.compare(gt) == 0){ //GT
            counterGT++;
          }else if(bigram.compare(gg) == 0){ //GG
            counterGG++;
          }else{
            //empty
          }
        }//end of  else loop
      }//end of while loop to read in lines from file

    readfile.close();
    outfile << "Here is the relative probability of nucleotide bigrams: " << endl;
    outfile << "AA:          " <<  counterAA/bigramCombinations << endl;
    outfile << "AC:          " <<  counterAC/bigramCombinations << endl;
    outfile << "AT:          " <<  counterAT/bigramCombinations << endl;
    outfile << "AG:          " <<  counterAG/bigramCombinations << endl;
    outfile << "CA:          " <<  counterCA/bigramCombinations << endl;
    outfile << "CC:          " <<  counterCC/bigramCombinations << endl;
    outfile << "CT:          " <<  counterCG/bigramCombinations << endl;
    outfile << "CG:          " <<  counterCG/bigramCombinations << endl;
    outfile << "TA:          " <<  counterTA/bigramCombinations << endl;
    outfile << "TC:          " <<  counterTC/bigramCombinations << endl;
    outfile << "TT:          " <<  counterTT/bigramCombinations << endl;
    outfile << "TG:          " <<  counterTG/bigramCombinations << endl;
    outfile << "GA:          " <<  counterGA/bigramCombinations << endl;
    outfile << "GC:          " <<  counterGC/bigramCombinations << endl;
    outfile << "GT:          " <<  counterGT/bigramCombinations << endl;
    outfile << "GG:          " <<  counterGG/bigramCombinations << endl<< endl;
  } //end of if statement used to check if file is open

    outfile <<  "here are the 1000 DNA strings: " << endl <<endl;

    //-----------------------------------for loop used to append 1000 DNA strings to text file
    for(int i = 0; i  < 1000; ++i){
      //call method to generate & return new length each time using Gaussian Distribution
      int gaussianLength = word.gaussianNum();
      float probofA = word.relProbA(fileToProcess) * gaussianLength;
      probofA = ceil(probofA);
      float probofC = word.relProbC(fileToProcess) * gaussianLength;
      probofC = ceil(probofC);
      float probofT = word.relProbT(fileToProcess) * gaussianLength;
      probofT = ceil(probofT);
      float probofG = word.relProbG(fileToProcess) * gaussianLength;
      probofG = ceil(probofG);
      int counterA = 0;
      int counterC = 0;
      int counterT = 0;
      int counterG = 0;
      for(int j = 0; j < gaussianLength; ++j) {
        //generate random number from 1 - 4
  			int randVal = rand() % 4 + 1;

        if(randVal == 1 ){
          if(counterA < probofA){
            outfile << "A";
            counterA++;
          }else if(counterC < probofC){
            outfile<< "C";
            counterC++;
          }else if(counterT < probofT){
            outfile << "T";
            counterT++;
          }else if(counterG < probofG){
            outfile << "G";
            counterG++;
          }
        }else if(randVal == 2){
          if(counterC < probofC){
            outfile <<  "C";
            counterC++;
          }else if( counterA < probofA){
            outfile << "A";
            counterA++;
          }else if(counterT < probofT){
            outfile << "T";
            counterT++;
          }else if(counterG < probofG){
            outfile << "G";
            counterG++;
          }
        }else if(randVal ==  3){
          if(counterT < probofT){
            outfile << "T";
            counterT++;
          }else if( counterA < probofA){
            outfile << "A";
            counterA++;
          }else if(counterT < probofT){
            outfile << "C";
            counterT++;
          }else if(counterG < probofG){
            outfile << "G";
            counterG++;
          }
        }else if(randVal == 4){
          if(counterG < probofG){
            outfile << "G";
            counterG++;
          }else if( counterA < probofA){
            outfile << "A";
            counterA++;
          }else if(counterT < probofT){
            outfile << "T";
            counterT++;
          }else if(counterG < probofG){
            outfile << "C";
            counterG++;
          }
        }
  		}//end of second for loop
      outfile << endl;
    }

    //outfile.close();
    //ask user if they want to process another list
    bool run = true;
    while(true){
      string userInput;
      cout << "Do you want to process another list? (y/n) " << endl;
      cin >> userInput;
      // transform(userInput.begin(), bigram.end(), bigram.begin(), ::tolower); -------> KEEPING THIS LINE OF CODE GAVE ME A SEGMENTATION FAULT <--------
      if(userInput == "n" || userInput == "N"){
        outfile.close();
        return 0;
      }else if (userInput == "y" || userInput == "Y"){
        firstTime++;
        cout << "Processing another list..." << endl;
        break;
      }else{
        cout << "invalid input! try entering 'y' or 'n' " << endl;
        continue;
      }
    }// end of second while loop


  }// end of first while loop
  return 0;
}// end of main
