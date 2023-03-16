class Encrypter {
private:
    unordered_map<char,string> mp;
    unordered_map<string,string> encryptedStrings;
    unordered_map<string,int> encryptedStringsCount;
    string getEncryptedString(string &s, bool store = true) {
        string ans;
        for(char c : s) {
            if(!mp.count(c)) return "";
            ans += mp[c];
        }
        if(store) {
            encryptedStrings[s] = ans;
            encryptedStringsCount[ans] += 1;
        }
        return ans;
    }
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i = 0; i < keys.size(); i += 1) {
            mp[keys[i]] = values[i];
        }
        for(string s : dictionary) {
            getEncryptedString(s);
        }
    }
    
    string encrypt(string word1) {
        return getEncryptedString(word1,false);
    }
    
    int decrypt(string word2) {
        return encryptedStringsCount[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */