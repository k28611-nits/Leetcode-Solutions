class Solution {
    unordered_map<string,string> shortner;
    int counter=0;
    public:
    string encode(string longUrl) {
        string shortUrl="http://tinyurl.com/"+to_string(counter);
        shortner[shortUrl] = longUrl;
        counter++;
        return shortUrl;
    }
    string decode(string shortUrl) {
        return shortner[shortUrl];
    }
};