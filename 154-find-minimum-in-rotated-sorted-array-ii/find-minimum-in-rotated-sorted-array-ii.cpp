class Solution {
public:
    int findMin(vector<int>& arr) {
             int n=arr.size();
      int low=0;
      int high=n-1;
      int min=arr[0];
      while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]<min){
            min=arr[mid];
        }
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low=low+1;
            high=high-1;

        }
        else if(arr[low]<=arr[mid]){
           if(arr[mid]>=min && arr[low]<arr[high]){
            high=mid-1;
           }
           else{
            low=mid+1;
           }
        }
        else{
            if(arr[mid]<=arr[high] && arr[mid]<min &&arr[low]<arr[high] ){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
      }
      return min;
    }
};