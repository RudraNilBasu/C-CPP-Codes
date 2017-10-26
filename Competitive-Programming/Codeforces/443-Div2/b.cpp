#include <iostream>
#include <vector>

using namespace std;

#define ll long long int

class Player {
        public:
                int power;
                ll wins;

                Player() {}

                Player(int power)
                {
                        wins = 0;
                        this->power = power;
                }

                void won()
                {
                        wins++;
                }

                bool isWinner(ll k)
                {
                        return wins >= k;
                }
};

int main()
{
        int n;
        ll k;

        cin >> n >> k;
        vector<Player> players;

        int i, power;

        int max_power = -1;
        for (i = 0; i < n; i++) {
                cin >> power;
                Player _player(power);

                players.push_back(_player);

                if (power > max_power)
                        max_power = power;
        }

        Player current_player = players[0];
        while (!current_player.isWinner(k)) {
                //cout << "Current Player's power: " << current_player.power << " max: " << max_power << endl;
                if (current_player.power == max_power) {
                        //cout << "Max power, break " << current_player.power << "\n";
                        break;
                }
                //cout << current_player.wins << endl;
                Player next_player = players[1];

                if (current_player.power > next_player.power) {
                        players.erase(players.begin() + 1);
                        players.push_back(next_player);
                        current_player.won();
                } else {
                        players.erase(players.begin());
                        players.push_back(current_player);
                        next_player.won();
                        current_player = next_player;
                }
        }

        cout << current_player.power << endl;
        /*
        for (i = 0; i < n; i++) {
                cout << "Player: " << players[i].power << endl;
        }
        */
        return 0;
}
