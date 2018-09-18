/***********************************************************************
// OOP244 Workshop 1: Compiling modular source code
// File	w1_in_lab.cpp
// Version 1.0
// Date	2016/01/10
// Author	Fardad Soleimanloo
// Description
// This provides some source code in a single file to break 
// into modules and compile together
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad
/////////////////////////////////////////////////////////////////
***********************************************************************/


#include <iostream>
using namespace std;



// Finds the largest sample in the samples array, if it is larger than 70,
// therwise it will return 70. 





// displays the user interface menu
int menu(){
  cout << "1- Number of Samples" << endl;
  cout << "2- Sample Entry" << endl;
  cout << "3- Draw Graph" << endl;
  cout << "0- Exit" << endl;
  cout << "> ";
  return getInt(0, 3);
}

// Performs a fool-proof integer entry
int getInt(int min, int max){
  int val;
  bool done = false;
  while (!done){
    cin >> val;
    if (cin.fail()){
      cin.clear();
      cout << "Invalid Integer, try again: ";
    }
    else{
      if (val < min || val > max){
        cout << "Invalid value!" << endl << "Enter a value between " << min << " and " << max << ": ";
      }
      else{
        done = true;
      }
    }
    cin.ignore(1000, '\n');
  }
  return val;
}
// prints a graph comparing the sample values visually 
void printGraph(int samples[], int noOfSamples){
  int max = findMax(samples, noOfSamples);
  cout << "Graph:" << endl;
  for (int i = 0; i < noOfSamples; i++){
    printBar(samples[i], max);
  }
}
// prints a scaled bar relevant to the maximum value in samples array
void printBar(int val, int max){
  int i;
  for (i = 0; i < 70 * val / max; i++){
    cout << "*";
  }
  cout << " " << val << endl;
}

// Fills the samples array with the statistic samples
void getSamples(int samples[], int noOfSamples){
  int i;
  for (i = 0; i < noOfSamples; i++){
    cout << (i + 1) << "/" << noOfSamples << ": ";
    samples[i] = getInt(1, 1000000);
  }
}

// finds the largest sample in the samples array, if it is larger than 70,
// otherwise it will return 70. 
int findMax(int samples[], int noOfSamples){
  int max = samples[0];
  int i;
  for (i = 1; i < noOfSamples; i++){
    if (max < samples[i]) max = samples[i];
  }
  return max < 70 ? 70 : max;
}

