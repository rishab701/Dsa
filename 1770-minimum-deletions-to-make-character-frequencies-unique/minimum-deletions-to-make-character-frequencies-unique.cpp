class Solution {
public:
int minDeletions(string s) {
    // Count the frequency of each character in the string
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    // Create a vector to store the frequencies of characters
    vector<int> frequencies;
    for (auto it = freq.begin(); it != freq.end(); ++it) {
        frequencies.push_back(it->second);
    }

    // Sort the frequencies in non-increasing order
    sort(frequencies.rbegin(), frequencies.rend());
    int deletions = 0;
    unordered_set<int> uniqueFrequencies;
    // Iterate over the sorted frequencies
    for (int i = 0; i < frequencies.size(); ++i) {
        int currentFreq = frequencies[i];

        // Keep decreasing the frequency until it reaches a value that has not appeared before
        while (uniqueFrequencies.count(currentFreq) > 0 && currentFreq > 0) {
            currentFreq--;
            deletions++;
        }

        // Add the current frequency to the set of unique frequencies
        uniqueFrequencies.insert(currentFreq);
    }

    return deletions;
  }
};