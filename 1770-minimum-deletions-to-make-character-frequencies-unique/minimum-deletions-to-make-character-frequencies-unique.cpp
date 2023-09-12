class Solution {
public:
int minDeletions(string s) {
    unordered_map<char, int> f;
    for (char c : s) {
        f[c]++;
    }
    vector<int> freq;
    for (auto it = f.begin(); it != f.end(); ++it) {
        freq.push_back(it->second);
    }
    sort(freq.rbegin(), freq.rend());
    int cnt=0;
    set<int>st;
    for(int i=0;i<freq.size();i++){
        int currfreq=freq[i];
        while(st.count(currfreq)>0 && currfreq>0){
            currfreq--;
            cnt++;
        }
        st.insert(currfreq);
    }
    return cnt;
  }
};
// a-1
// b-1
// c-1
// d-1
// e-1