# Two_way_path_finder
This C++ program finds all two-way paths from a given start street to a destination street

Input: a data file with the names of the streets 
Output: All two way paths from a start street to a destination street

bool getPaths(string current, string finalDestination, unordered_map<string, vertex<string> > graph, unordered_map<string, bool>&nodesInPath, myStack<string>&recStack, int&pathNo) 
*function description: A dfs-type traversal that uses a stack to hold the found paths.
*parameters: start street, destination street,the adjacency list unordered map, inPath unordered map, stack instantiation, amount of paths

vertexEdge.h 
  Used to formulate an adjacency list 
  
myStack.h
  A linked list implementation of a stack
