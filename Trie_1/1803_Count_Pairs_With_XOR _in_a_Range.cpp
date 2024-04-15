class Solution {
public:
    int trie[1 << 17];        
    int countPairs(vector<int>& nums, int low, int high) 
    {                
        for (int i = 0; i < (1 << 17); ++i)        
        {
            trie[i] = 0;                    
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int count = Search(15, 1, nums[i], 0, low) - Search(15, 1, nums[i], 0, high + 1);
            ans += count;            
            Insert(15, 1, nums[i]);
        }           
        return ans;
    }
    
    void Insert(int bitPos, int idx, int value)
    {
        if (bitPos < 0) 
        {
            trie[idx] += 1;
            return;
        }        
        if ( !(val & (1 << bitPos)) )                    
            Insert(bitPos - 1, idx * 2, value);        
        else        
            Insert(bitPos - 1, idx * 2 + 1, value);             
        trie[idx]  = trie[idx * 2] + trie[idx * 2 + 1];
    }
    
    int Search(int bitPos, int idx, int value, int xorVal, int threshold)
    {
        if (bitPos < 0)
        {
            if (xorVal >= threshold) return trie[idx];
            return 0;
        }
        if (xorVal >= threshold) return trie[idx];
        int mask = (1 << (bitPos + 1)) - 1;
        if ( (xorVal | mask) < threshold ) return 0;
        
        int ans = 0;
        if ( val & (1 << bitPos) )
        {            
            ans += Search(bitPos - 1, idx * 2, value, xorVal | ( 1 << bitPos ), threshold);            
            ans += Search(bitPos - 1, idx * 2 + 1, value, xorVal, threshold);               
        }
        else
        {            
            ans += Search(bitPos - 1, idx * 2, value, xorVal, threshold);            
            ans += Search(bitPos - 1, idx * 2 + 1, value, xorVal | (1 << bitPos), threshold);   
        }
        return ans;
    }
};