// https://leetcode.com/problems/palindrome-permutation-ii/description/

class Solution
{
public:
    std::vector<std::string> generatePalindromes(std::string s)
    {
        std::array<int, 26> cnt{};

        for (auto c : s)
        {
            cnt[c - 'a']++;
        }

        auto odds = 0;
        auto oddc = 'a';
        std::string perm;

        for (auto i = 0; i < 26; i++)
        {
            if (cnt[i] % 2 == 1)
            {
                odds++;
                oddc = 'a' + i;
            }

            perm += std::string(cnt[i] / 2, 'a' + i);

            if (odds > 1)
            {
                return {};
            }
        }

        std::vector<std::string> all_perms;

        do
        {
            auto end = perm;

            if (odds == 1)
            {
                end.push_back(oddc);
            }
            std::reverse(std::begin(end), std::end(end));

            all_perms.push_back(perm + end);
        }
        while (std::next_permutation(std::begin(perm), std::end(perm)));

        return all_perms;
    }
};