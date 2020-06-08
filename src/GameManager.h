#include <iostream>
#include "Player.h"
#include <vector>

using namespace std;
using std::vector;

class GameManager
{

public:
    GameManager()
    {

        cout << " " << endl;
    };

    void ManageNewPlayer(Player *player);
    bool InitManager();
    void DumpDataToFile(Player *player);
    void RetriveDataFromFile();
    void temp_print_vector_of_object_pointers(vector<Player *> v);
    static bool quit_game_flag;

private:
    Player *player;
    vector<Player *> v_player;
};