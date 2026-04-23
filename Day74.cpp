/*
Problem Statement:
Given an array of candidate names (votes), find the candidate with the maximum votes.
If there is a tie, return the lexicographically smallest name.

Input:
- n (number of votes)
- n candidate names

Output:
- winner_name vote_count

Example:
Input:
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Output:
john 4
*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> votes;
    string name;

    // Count votes
    for (int i = 0; i < n; i++) {
        cin >> name;
        votes[name]++;
    }

    string winner = "";
    int maxVotes = 0;

    // Find winner
    for (auto &p : votes) {
        if (p.second > maxVotes) {
            maxVotes = p.second;
            winner = p.first;
        }
        else if (p.second == maxVotes && p.first < winner) {
            winner = p.first; // lexicographically smaller
        }
    }

    cout << winner << " " << maxVotes;

    return 0;
}
