// bstats.cpp: baseball statistics

#include <string>
#include <list>
#include <iomanip>
#include <iostream>
using namespace std;

class Player {
public:
  Player(string name, int at_bats, int runs, int hits, int runs_batted_in,
         int walks) {
    _name = name;
    _at_bats = at_bats;
    _runs = runs;
    _hits = hits;
    _rbi = runs_batted_in;
    _walks = walks;
  }

  std::string name() const {
    return _name;
  }

  int at_bats() const {
    return _at_bats;
  }

  int runs() const {
    return _runs;
  }

  int hits() const {
    return _hits;
  }

  int runs_batted_in() const {
    return _rbi;
  }

  int walks() const {
    return _walks;
  }

  double average() const {
    if (_at_bats == 0)
      return 0.0;
    else
      return _hits / double(_at_bats) * 1000.0;
  }

  static Player *read(string player_name = "") {
    int at_bats, runs, hits, rbi, walks;
    if (player_name == "")
      cin >> player_name;
    cin >> at_bats >> runs >> hits >> rbi >> walks;
    return new Player(player_name, at_bats, runs, hits, rbi, walks);
  }

  void dump() const {
    cout << _name << ": ABs: " << _at_bats << ", r: " << _runs
        << ", h: " << _hits << ", rbi: " << _rbi << ", w: " << _walks
        << ", ave: " << average()
        << endl;
  }

private:
  string _name;
  int _at_bats, _runs, _hits, _rbi, _walks;
};

list<string> remove_players_with_impossible_stats(list<Player *> &players) {
  // iterates over the entries, removing those for which the
  // number of runs is grater than the sum of the hits and walks.
  // Return a list of those players which were removed (just their names)
  list<string> removed_names;
  auto pit = players.begin();
  while (pit != players.end()) {
    const Player *p = *pit;
    if (p->runs() > (p->hits() + p->walks())) {
      removed_names.push_back(p->name());
      pit = players.erase(pit);
    } else {
      ++pit;
    }
  }
  return removed_names;
}

void divide_players_by_rbi_vs_hits(const list<Player *> &all_players,
                                   list<Player *> &more_rbi,
                                   list<Player *> &more_hits) {
  auto pit = all_players.begin();
  while (pit != all_players.end()) {
    Player *p = *pit;
    if (p->runs_batted_in() > p->hits()) {
      more_rbi.push_back(p);
    } else {
      more_hits.push_back(p);
    }
    ++pit;
  }
}

double average(const list<Player *> &players) {
  auto pit = players.begin();
  double sum = 0.0;
  int num_players = 0;
  while (pit != players.end()) {
    const Player *p = *pit;
    sum += p->average();
    ++num_players;
    ++pit;
  }

  return sum / static_cast<double>(num_players);
}

int main() {
  // ignore line of headers
  {
    string headers;
    getline(cin, headers);
  }
  list<Player *> all_players;
  Player *next_player = Player::read();
  while (cin) {
    all_players.push_back(next_player);
    next_player = Player::read();
  }
  if (false) {
    // for debugging only
    cout << "ALL:" << endl;
    for (auto x: all_players)
      x->dump();
    cout << endl;
  }

  list<string> removed_names =
      remove_players_with_impossible_stats(all_players);
  if (removed_names.size() > 0) {
    cout << "Found " << removed_names.size()
        << " players with more runs than hits and walks: " << endl;
    for (auto n: removed_names)
      cout << " " << n;
    cout << endl;
  }

  // number of players averaging more hits than rbi and vice versa

  list<Player *> more_rbi, more_hits;
  divide_players_by_rbi_vs_hits(all_players, more_rbi, more_hits);
  double more_rbi_ave = average(more_rbi);
  double more_hits_ave = average(more_hits);
  cout << setprecision(0) << setiosflags(ios::fixed);
  cout << "More hits than rbi: " << more_rbi.size() << endl
      << "               ave: " << more_rbi_ave << endl
      << "More rbi than hits: " << more_hits.size() << endl
      << "               ave: " << more_hits_ave << endl;
  return 0;
}
