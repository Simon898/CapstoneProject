#include "GameManager.h"
#include "DataManager.h"
#include "GridSize.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <dirent.h>
#include <unistd.h>
#include <sstream>
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <set>

using namespace std;

bool GameManager::quit_game_flag = false;

bool GameManager::InitManager()
{

    cout << " Capstone project SNAKE GAME" << endl;
    cout << "   " << endl;
    cout << " 1. New Game" << endl;
    cout << " 2. Top 10 players" << endl;
    cout << " 3. Quit!" << endl;
    cout << "your choice --> ";

    int key_pressed;

    while (!(cin >> key_pressed))
    {

        cin.clear();

        while (cin.get() != '\n')
            continue;

        cout << "FAILED. Only number is allowed. Please enter correct number -->  ";
    }
    if ((key_pressed < 1) || (key_pressed > 4))
    {
        cout << "you pressed : " << key_pressed << endl;
        cout << "FAILED. Please enter correct number!"
                  << "\n\n";
        return false;
    }

    switch (key_pressed)
    {

    case 1:
    {
        return true;
    };
    break;

    case 2:
    {
        DataManager dm;
        map<string, int> recorded_players;
        recorded_players = dm.ReadGameHistoryMap();
        if (recorded_players.size() > 0)
        {
            dm.DisplaySortedPlayers(recorded_players);
        }
        else
        {
            cout << "The history for this game does nor exist!" << endl;
        }
        return false;
    };
    break;
    case 3:
    {
        cout << "quiting the game ... Thanks" << endl;
        quit_game_flag = true;
    };

        return false;
    }
}

void GameManager::ManageNewPlayer(Player *p)
{

    p->SetPlayerName();
}

void GameManager::DumpDataToFile(Player *p)
{

    cout << "call the function " << __FUNCTION__ << endl;

    cout << "player:  " << p->GetPlayerName() << " :: " << p->GetPlayerScore() << " :: " << p->GetPlayerGameTime() << endl;
}

void GameManager::temp_print_vector_of_object_pointers(vector<Player *> v_player)
{

    int v_player_size = v_player.size();

    for (int i = 0; i < v_player_size; i++)
    {
        cout << "player vector::  " << v_player[i]->GetPlayerName() << endl;
    }
}


