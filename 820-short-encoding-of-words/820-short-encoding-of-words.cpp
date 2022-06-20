bool comperator(const string &s1, const string &s2)
{
    return s1.size()>s2.size();
}

class TrieNode{
    
    public:
    char data;
    TrieNode **children;
    bool isTerminal;
        
    TrieNode(char data)
    {
        this->data=data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal=false;
    }
    
};

class Solution {
    
    void insert(TrieNode *root, string s)
    {
        if(s.size()==0)
        {
            root->isTerminal = true;
            return;
        }
        int index=s[0]-'a';
        TrieNode *child;
        if(root->children[index]==NULL)
        {
            child=new TrieNode(s[0]);
            root->children[index]=child;
        }
        else
        {
            child=root->children[index];
        }
        
        insert(child,s.substr(1));
    }
    
    bool search(TrieNode *root, string s)
    {
        if(s.size()==0)
        {
            return true;
        }
        int index=s[0]-'a';
        if(root->children[index]==NULL)
        {
            return false;
        }
        bool smallans=search(root->children[index],s.substr(1));
        return smallans;
    }
    
public:
    int minimumLengthEncoding(vector<string>& words) {
        
        TrieNode *root=new TrieNode('\0');
        
        int n=words.size();
        int ans=0;
        sort(words.begin(),words.end(),comperator);
        
        for(int i=0;i<n;i++)
        {
            reverse(words[i].begin(),words[i].end());
            bool found=search(root,words[i]);
            if(found==false)
            {
                ans+=words[i].size()+1;
                insert(root,words[i]);
            }
        }
        
        return ans;
        
    }
};