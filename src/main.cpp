#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "GameManager.h"
#include "GridSize.h"
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
#include "snake.h"

using namespace std;

int main()
{
  constexpr size_t kFramesPerSecond{60};
  constexpr size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr size_t kScreenWidth{640};
  constexpr size_t kScreenHeight{640};
  constexpr size_t kGridWidth{32};
  constexpr size_t kGridHeigth{32};


  bool start_game;
  int player_score;
  start_game = false;
  map<string, int> actual_player_map;
  string actual_player_name;
  Snake tempSnake;
  bool quit_game_flag = false;

  while (true)
  {

    while (start_game == false)
    {
      GameManager gm;

      if (gm.quit_game_flag == true)
      {
        return 0;
      }

      start_game = gm.InitManager();
    }

    start_game = false;
    Player *newplayer = new Player();
    DataManager *newdm = new DataManager();
    Snake newsnake;
    newplayer->SetPlayerName();
    tempSnake.head_total_distance = 0;

    cout << "begin the game" << endl;

    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeigth);

    Controller controller;
    Game game(kGridWidth, kGridHeigth);
    game.Run(controller, renderer, kMsPerFrame);

    cout << "Game Over!\n";

    actual_player_name = newplayer->GetPlayerName();
    cout << " Player Name:  " << actual_player_name << endl;
    cout << "Score: " << game.GetScore() << "\n";
    player_score = game.GetScore();
    cout << "Size: " << player_score << "\n";
    cout << "Snake head travel ::" << tempSnake.head_total_distance << endl;

    actual_player_map.insert(make_pair(actual_player_name, player_score));
    newdm->WriteGameHistoryMap(actual_player_map);
  }
  return 0;
}