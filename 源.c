#define _CRT_SECURE_NO_WARNINGS 1
void disdoey(int* str, int* end)
{
    while (str < end)
    {
        int tmp = *str;
        *str = *end;
        *end = tmp;
        str++;
        end--;
    }
}


void rotate(int* nums, int numsSize, int k)
{

    k %= numsSize;
    int* end = nums + numsSize - 1;
    disdoey(end - k + 1, end);
    disdoey(nums, end - k);
    disdoey(nums, end);

}
int missingNumber(int* nums, int numsSize)
{
    /*
    int sum=0;
    for(int i=0;i<=numsSize;i++)
    {
        sum+=i;
    }
    for(int i=0;i<numsSize;i++)
    {
        sum-=nums[i];
    }
    return sum;
    */

    int num = 0;
    for (int i = 0; i <= numsSize; i++)
    {
        num ^= i;
    }
    for (int i = 0; i < numsSize; i++)
    {
        num ^= nums[i];
    }
    return num;


}