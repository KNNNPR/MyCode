#include <iostream>
#include <vector>


std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> answer;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] <= target || nums[i] >= target)
        {
            answer.push_back(i);
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    answer.push_back(j);
                    return(answer);
                }
            }
        }
        answer.clear();
    }
}

void showVector(std::vector<int> ans)
{
    for (int i = 0; i < ans.size(); i++) 
    {
        std::cout << ans[i] << "  ";
    }
}


int main()
{

}
