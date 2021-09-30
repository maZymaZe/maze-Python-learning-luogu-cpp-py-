class Solution {
   public:
    // Encodes a URL to a shortened URL.
    unordered_map<int, string> mp;
    int c;

    string encode(string longUrl) {
        c++;
        mp.insert({c, longUrl});
        return to_string(c);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) { return mp[stoi(shortUrl)]; }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
