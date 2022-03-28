/*
Name: Lucas Allen, 5004607031, AS9
Description: This program finds all two-way paths from a start street to a destination street
Input: a data file with the names of the streets
Output: All two way paths from a start street to a destination street
*/
#include <iostream>
#include <fstream>
#include <unordered_map>


#include "myStack.h"
#include "vertexEdge.h"

using namespace std;

bool getPaths(string current, string finalDestination, unordered_map<string,
  vertex<string> > graph, unordered_map <string, bool>&nodesInPath, myStack<string>&recStack, int& pathNo);

int main()
{
  ifstream infile;
  string fileName;
  string start, destination, street1,street2;


  unordered_map<string, vertex<string> > adjList; //the adjacency list
  unordered_map<string, bool> inPath;             //"nodesInPath"
  myStack<string> ms;                             //stack.h :: myStack instantiation
  int pathAmount=0;                               //"pathNo"



  cout<<"Enter the input file: ";
  cin>>fileName;
  infile.open(fileName.c_str());
  while(!infile.is_open())
  {
    cout<<"Enter the input file: ";
    cin>>fileName;
    infile.open(fileName.c_str());                      //Take in the input file and reprompt on error
  }

  infile>>start;                                        //take in the start street from the input file
  infile>>destination;                                  //take in the destination from the input file
  while(infile>>street1)
  {
    infile>>street2;
    adjList[street1].addEdge(street2);                  //add each street2 to each street1's adjacency list
  }
  infile.close();         //close the file
  getPaths(start, destination, adjList, inPath, ms, pathAmount);  //call getPaths to find the paths between them



return 0;
}
/*
*function description: A dfs-type traversal that uses a stack to hold the found paths.
*parameters: start street, destination street,the adjacency list unordered map, inPath unordered map, stack instantiation, amount of paths
*return value: a boolean value
*/
bool getPaths(string current, string finalDestination, unordered_map<string, vertex<string> > graph, unordered_map<string, bool>&nodesInPath, myStack<string>&recStack, int&pathNo)
{

  if(current == finalDestination)
  {
    cout<<"Path "<<pathNo<<endl;
    cout<<recStack.top()<<endl;
    recStack.pop();
    pathNo++;
    return true;
  }
  vertex<string>::edgeIterator it;
  vertex<string>::edgeIterator nil;
  nil = graph[current].end();

  nodesInPath[current]=true;
  for(it=graph[current].begin(); it!=nil;it++)
  {
    if(nodesInPath[current]==true)
    {
      recStack.push(current);
      return true;
    }
    if(nodesInPath[current]!=true)
    {
      if(getPaths(current, finalDestination, graph, nodesInPath, recStack,pathNo))
       {
        return true;
      }
    }
  }
  nodesInPath[current]=false;
return false;
}
