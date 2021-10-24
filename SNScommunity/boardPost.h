#pragma once
#include "board.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
//#include <curses.h>
#include <stdlib.h>

using namespace std;

class boardPost {
private:

public:
   boardPost();
   ~boardPost();
   void Post(string _filename, string _userid);
   int Report(int data);
   int check_fspace(string s);
   int check_(string s);
};