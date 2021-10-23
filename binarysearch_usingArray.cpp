#include <iostream>

using namespace std;

int binarySearch(int arr[],int num,int left,int right)
{
    if(right >= left)
    {
        int mid = (left + right) / 2;
        
        if(arr[mid] == num)
            return mid;
        
        if(arr[mid] > num)
            return binarySearch(arr,num,left,mid-1);
        
        return binarySearch(arr,num,mid+1,right);
    }
    return -1;
}

int main() 
{
    int total_num,total_search,num;
    cin >> total_num;
    
    int arr[total_num];
    for(int i=0;i<total_num;i++)
    {
        cin >> arr[i];
        if(i != 0 && arr[i-1] >= arr[i])
        {
            cout << "Numbers are not in ascending order";
            exit(0);
        }
    }
    
    cin >> total_search;
    
    while(total_search--)
    {
        cin >> num;
        int ans = binarySearch(arr,num,0,total_num);
        if(ans != -1)
            cout << ans+1 << " ";
        else
            cout << ans << " ";
    }
    
    return 0;
}
