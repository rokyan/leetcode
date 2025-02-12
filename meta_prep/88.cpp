class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        auto p = m + n - 1;

        for (auto i = m - 1, j = n - 1; i >= 0 || j >= 0; )
        {
            if (i == -1)
            {
                nums1[p--] = nums2[j--];
            }
            else if (j == -1)
            {
                nums1[p--] = nums1[i--];
            }
            else
            {
                if (nums1[i] > nums2[j])
                {
                    nums1[p--] = nums1[i--];
                }
                else
                {
                    nums1[p--] = nums2[j--];
                }
            }
        }
    }
};