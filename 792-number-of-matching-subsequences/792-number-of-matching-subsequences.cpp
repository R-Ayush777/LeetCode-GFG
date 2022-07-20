class Solution
{
public:
    bool isSubq(string &curr, string &s)
    {
        int idx = 1;
        int i = s.find(curr[0]);
        if (i == -1)
            return false;
        while (idx < curr.length())
        {
            i = s.find(curr[idx], i + 1);
            if (i == -1)
                return false;
            idx++;
        }
        return true;
    }

    int numMatchingSubseq(string s, vector<string> &words)
    {
        int count = 0;
        for (string str : words)
            if (isSubq(str, s))
                count++;

        return count;
    }
};