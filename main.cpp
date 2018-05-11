//
//  main.cpp
//  program7
//
/*
 PROJECT 7 (New # 8)
 
 Quick Sort and Recursion
 
 - Create a vector of student records (minimum 15+ records) which is unsorted
 
 (For Vector, refer to Chapter 7.11)
 
 - You should read student records from a file into the vector in C++
 
 or Java program.
 
 - Display the unsorted 10+ student records (entire record, not just ID) and associated test scores.
 
 - Each Student record should include Student ID, Name, GPA, Student Address, and a pointer which points to (10+) test scores somewhere in the program or in the file.
 
 - Use QuickSort and recursion to Sort the student records according to student ID or GPA.
 
 - Display the sorted list of student records (entire record, not just ID) and associated test scores.
 
 - Repeat the above on two sets of student records. Each set with a minimum of 10 records.
 
*/
//  Created by Lawrence Miles Gomez on Nov/4/17.
//  Copyright © 2017 Lawrence Miles Gomez. All rights reserved.
//

#include<iostream>
#include<fstream>
#include<vector>
#include<time.h>
#include<string>
using namespace std;   // libraries for cpp file


struct records  // struct for holding student info
{
    int ID;
    string Address;
    string Name;
    double GPA;
    int *testPointer;
};

int partition( vector<records>& Vec, int start, int end );  // fucntion prototypes that can operate on student info
void quickSort( vector<records>& Vec, int start, int end );
void swap( int & value1, int & value2 );


void quickSort(vector<records>& Vec, int start, int end)  // uses recursion and 2 other functions to sort vector info
{
    if (start < end)
    {
        int split = partition(Vec, start, end);
        quickSort(Vec, start, split-1);
        quickSort(Vec, split+1, end);
    }
}

int partition( vector<records>& Vec, int start, int end)   // does 1/3 of the sorting by sorting vector by ID
{
    int pivotValue, pivotIndex, middle;
    
    middle = (start + end)/2;
    swap(Vec[start], Vec[middle]);
    pivotIndex = start;
    pivotValue = Vec[start].ID;
    
    for(int scan = start + 1; scan <= end; scan++)
    {
        if(Vec[scan].ID < pivotValue)
        {
            pivotIndex++;
            swap(Vec[pivotIndex], Vec[scan]);
        }
    }
    swap(Vec[start], Vec[pivotIndex]);
    return pivotIndex;
}

void swap(int & value1, int & value2)      // does 1/3 of the sorting by swaping values
{
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

int main()
{
    records v;    // creates object for record struct
    vector<records> Vec;   // creates vector to store info
    
    
    ifstream infile;  // creates file object
    infile.open("records.txt");
    if (!infile)    // checks for file
    {
        cout << "No input file" << endl;
        return -1;
    }
    cout<<" Information from input file :"<<endl;
    
    while (!infile.eof())  // while not at end of file it takes all info from file and stores it
    {
        infile >> v.ID;
        infile.ignore( numeric_limits<streamsize>::max(), '\n' );
        getline( infile, v.Name );
        getline( infile, v.Address );
        infile >> v.GPA;
        
        cout << v.ID << " " << v.Name << " " << v.Address << " " << v.GPA << " ";
        
        v.testPointer = new int[10];
        int temp;
        
        for (int j = 0; j < 10; j++)
        {
            infile >> temp;
            v.testPointer[j] = temp;
            cout << " " << v.testPointer[j];
        }
        
        Vec.push_back(v);
        cout<<endl;
    }
    
    
    cout<<endl<<endl;
    cout<<" Sorted vector that displays 10 files :";
    cout << endl;
    
    quickSort(Vec, 0, 19); // sorts vecotr that is from the file
    
    
    for(int i = 0; i < 10; i++) // displays sorted file
    {
        cout << Vec[i].ID << " " << Vec[i].Name <<" "<< Vec[i].Address <<" "<< Vec[i].GPA << " ";
        for(int k =0; k < 10; k++)
        {
            cout << *(Vec[k].testPointer) << " ";
        }
        cout<<endl;
    }
    
    return 0;
}

