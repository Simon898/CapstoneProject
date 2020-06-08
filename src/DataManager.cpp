#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <dirent.h>
#include <unistd.h>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <set>
#include "DataManager.h"

using namespace std;
using std::string;
using std::vector;

DataManager::DataManager(){};
DataManager::~DataManager(){};
map<string, int> DataManager::ReadGameHistoryMap()
{

  string line;
  string player_name;
  int player_score;
  map<string, int> players_map;
  map<string, int>::iterator it;
  const string gameDataDirectory{"../data"};

  ifstream filestream(gameDataDirectory + "/" + "game_record.txt");

  if (filestream.is_open())
  {
    while (getline(filestream, line))
    {

      istringstream linestream(line);
      while (linestream >> player_name >> player_score)
      {

        players_map.insert(make_pair(player_name, player_score));
      }

    }
    filestream.close();
    cout << "finishing reading file ..." << endl;
    return players_map;
  }
  else
  {
    ofstream outfile("game_record.txt");
    cout << "RECORD file does not exist. New is created." << endl;
  }
}


void DataManager::WriteGameHistoryMapSorted(map<string, int> aux_map)
{

  ofstream dataFile;

  dataFile.open("game_record.txt", ios::in | ios::out | ios::app);
  if (!dataFile.is_open())
  {
    cout << " not possible to open file" << endl;
  }
  else
  {
    map<string, int> sorted_aux_map;

    typedef function<bool(pair<string, int>, pair<string, int>)> Comparator;

    Comparator compFunctor =
        [](pair<string, int> elem1, pair<string, int> elem2) {
          return elem1.second > elem2.second;
        };

    set<pair<string, int>, Comparator> sorted_map(
        aux_map.begin(), aux_map.end(), compFunctor);

    int ii = 1;
    for (pair<string, int> element : sorted_map)
    {
      dataFile << ii << ". player : " << element.first << ", score : " << element.second << "\n";
      ii++;
    }

    dataFile.close();
  }
}

void DataManager::WriteGameHistoryMap(map<string, int> players_map)
{

  map<string, int>::iterator it;

  ofstream dataFile;

  dataFile.open("game_record.txt", ios::in | ios::out | ios::app);
  if (!dataFile.is_open())
  {
    cout << " not possible to open file" << endl;
  }
  else
  {

    for (it = players_map.begin(); it != players_map.end(); it++)
    {

      dataFile << (*it).first << " " << (*it).second << "\n";
    }

    dataFile.close();
  }
}

void DataManager::DisplaySortedPlayers(map<string, int> aux_map)
{

  cout << "called :: " << __FUNCTION__ << "   size  ::" << aux_map.size() << endl;
  map<string, int> sorted_aux_map;

  typedef function<bool(pair<string, int>, pair<string, int>)> Comparator;

  Comparator compFunctor =
      [](pair<string, int> elem1, pair<string, int> elem2) {
        return elem1.second > elem2.second;
      };

  set<pair<string, int>, Comparator> sorted_map(
      aux_map.begin(), aux_map.end(), compFunctor);

  int ii = 1;

  for (pair<string, int> element : sorted_map)
  {
    cout << ii << ". player : " << element.first << ", score : " << element.second << endl;
    ii++;
    if (ii > 10)
      break;
  }
}
